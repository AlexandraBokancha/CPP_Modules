#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe(void){
  //  std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other){
   // std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
PmergeMe &PmergeMe::operator=(const PmergeMe &other){
   // std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
PmergeMe::~PmergeMe(void){
    //std::cout << "Destructor called" << std::endl;
}

void PmergeMe::displayArray(){
    for (std::vector<int>::size_type i = 0; i < _vecArray.size(); ++i) {
        std::cout << _vecArray[i] << " ";
    }
    if (_hasStray)
        std::cout << _leftOver;
    std::cout << std::endl;
}

void PmergeMe::displayResults(){
    // /*-> to test: */ if (std::is_sorted(main.begin(), main.end()))
    //     std::cout << "sorted" << std::endl;
    struct timeval end_t;
    
    gettimeofday(&end_t, NULL);
    long seconds1 = end_t.tv_sec - startVec.tv_sec;
    long duration1 = seconds1 * 1000000 + (end_t.tv_usec - startVec.tv_usec);
    long seconds2 = end_t.tv_sec - startDeq.tv_sec;
    long duration2 = seconds2 * 1000000 + (end_t.tv_usec - startDeq.tv_usec);
    
    std::cout << "Before:  ";
    displayArray();
    std::cout << "After:  ";
    for (size_t i = 0; i < _main.size(); ++i){
        std::cout << _main[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(5); 
    std::cout << "Time to process a range of " << _vecArray.size() \
    << " elements with std::vector<int> : " << static_cast<double>(duration1) << " us"  << std::endl;
     std::cout << "Time to process a range of " << _deqArray.size() \
    << " elements with std::deque<int> : " << static_cast<double>(duration2) << " us"  << std::endl;
}

/**
 * @brief 
 * Function using a binary search to find the
 * correct position of an element in the sorted portion
 * of an array reducing the number of comparaison to place
 * each element.
 */
void PmergeMe::binaryInsertionV(std::vector<int>  & pend){
    for (size_t i = 0; i < pend.size(); ++i){
        int value = pend[i];
        std::vector<int>::iterator pos = std::upper_bound(_main.begin(), _main.end(), value);
        _main.insert(pos, value);
    }
   // displayResults(main);
}

void PmergeMe::mergeV(){
    std::vector<int>pendV;
    size_t i = 0;

    _main.push_back(_vecPairs[0].first); // first element in "pend" is smaller than the first element in "max" array
    while (i < _vecPairs.size()){
        _main.push_back(_vecPairs[i].second);
        if (i != 0){
            pendV.push_back(_vecPairs[i].first);
        }
        i++;
    }
    if (_hasStray){
        pendV.insert(pendV.begin(), _leftOver); // add a leftOver if it exists
    }
    binaryInsertionV(pendV);
}

void PmergeMe::insert(std::pair<int, int> newPair, size_t size){
    size_t j = size;

    while (j > 0 && _vecPairs[j - 1].second > newPair.second){
        _vecPairs[j] = _vecPairs[j - 1];
        j--;
    }
    _vecPairs[j] = newPair;
}

void PmergeMe::recursiveInsertionSortV(size_t size){
    if (size <= 1){ // condition to finish a recursive  sort
        return ;
    }

    recursiveInsertionSortV(size - 1);
   
    std::pair<int, int> lastPair = _vecPairs[size - 1];
    insert(lastPair, size - 1);
}


void PmergeMe::makePairsV(){
    _hasStray = (_vecArray.size() % 2 != 0);
    if (_hasStray){
        _leftOver = _vecArray.back();
        _vecArray.pop_back();
    }
    size_t index = 0;
    while (index < _vecArray.size()){
        if (index + 1 < _vecArray.size()){
            if (_vecArray[index] > _vecArray[index + 1]){
                std::swap(_vecArray[index + 1], _vecArray[index]);
            }
            _vecPairs.push_back(std::make_pair(_vecArray[index], _vecArray[index + 1]));
        }
        index += 2;
    }
    recursiveInsertionSortV(_vecPairs.size());
}

void PmergeMe::recursiveInsertionSortD(size_t size){
   if (size <= 1){
        return ;
   }
   recursiveInsertionSortD(size - 1);
   std::pair<int, int> lastPair = _deqPairs[size - 1];
   size_t j = size - 1;
   while (j > 0 && _deqPairs[j - 1].second > lastPair.second){
        _deqPairs[j] = _deqPairs[j - 1];
        j--;
   }
   _deqPairs[j] = lastPair;
}


void PmergeMe::deqMergeInsert(){
    gettimeofday(&startDeq, NULL);
    if (_hasStray){
        _deqArray.pop_back();
    }
    size_t index = 0;
    while (index < _deqArray.size()){
        if (index + 1 < _deqArray.size()){
            if (_deqArray[index] > _deqArray[index + 1]){
                std::swap(_deqArray[index + 1], _deqArray[index]);
            }
            _deqPairs.push_back(std::make_pair(_deqArray[index], _deqArray[index + 1]));
        }
        index += 2;
    }
    recursiveInsertionSortD(_deqPairs.size());
    std::deque<int> pend, main;
    size_t i = 0;
    main.push_back(_deqPairs[0].first);
     while (i < _deqPairs.size()){
        main.push_back(_deqPairs[i].second);
        if (i != 0){
            pend.push_back(_deqPairs[i].first);
        }
        i++;
    }
    if (_hasStray){
        pend.insert(pend.begin(), _leftOver);
    }
    for (size_t i = 0; i < pend.size(); ++i){
        int value = pend[i];
        std::deque<int>::iterator pos = std::upper_bound(main.begin(), main.end(), value);
        main.insert(pos, value);
    }
}

void PmergeMe::vecMergeInsert(){
    gettimeofday(&startVec, NULL);
    makePairsV();
    mergeV();
}

void PmergeMe::initArray(int ac, char *av[]){
    int nb;

    for (int i = 1; i < ac; ++i){
        nb = std::atoi(av[i]);
        if (nb > 0){
            _vecArray.push_back(nb);
            _deqArray.push_back(nb);
        }
        else
            throw PmergeMe::NotValidInput();
    }
}

void PmergeMe::FJMI(int ac, char *av[]){
    initArray(ac, av);
    vecMergeInsert();
    deqMergeInsert();
    displayResults();
}

const char* PmergeMe::NotValidInput::what() const throw(){
    return "\033[31mInput has to be a sequence of positive integers\033[0m";
}

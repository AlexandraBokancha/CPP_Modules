#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <iomanip>
# include <vector>
# include <sstream>
# include <cstdlib>
# include <utility>
# include <algorithm>
# include <sys/time.h>
# include <deque> 

class PmergeMe
{
    private:

        std::vector<int>                    _vecArray;
        std::deque<int>                     _deqArray;

        std::vector<std::pair<int, int> >   _vecPairs;
        std::deque<std::pair<int, int> >    _deqPairs;
        std::vector<int>                    _main;
       
        bool                                _hasStray;
        int                                 _leftOver;
       
        struct timeval                      startVec;
        struct timeval                      startDeq;

    public:

        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void FJMI(int ac, char *av[]);
        
        // Step 1
        void initArray(int ac, char *av[]);
        void vecMergeInsert();
        void deqMergeInsert();
        void makePairsV();
        
        // Step 2
        void recursiveInsertionSortV(size_t size);
        void recursiveInsertionSortD(size_t size);
        void insert(std::pair<int, int> newPair, size_t size);

        // Step 3
        void mergeV();
        void binaryInsertionV(std::vector<int> & pend);
        
        void displayResults();
        void displayArray();

        class NotValidInput: public std::exception{
            public:
                virtual const char* what() const throw();
        };
};


#endif


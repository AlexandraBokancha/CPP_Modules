#include "MutantStack.hpp"
# include <list>


void test2(){
  
    /* tests of member functions of std::stack */
  
    MutantStack<int> mstack;
    mstack.push(100);
    mstack.push(-20);
    std::cout << "isEmpty: " << mstack.empty() << std::endl;
    mstack.push(22);
    mstack.push(-2);
    mstack.push(40);
    std::cout << "mstack top is: " << mstack.top() << std::endl;
    std::cout << "mstack size is: " << mstack.size() << std::endl;
    std::cout << std::endl;
    MutantStack<int>::iterator it1 = mstack.begin();
    MutantStack<int>::iterator ite1 = mstack.end();
    std::cout << "Stack items: " << std::endl;
    while (it1 != ite1){
        std::cout << *it1 << std::endl;
        it1++;
    }
    std::cout << std::endl;
    MutantStack<int>::reverse_iterator it2 = mstack.rbegin();
    MutantStack<int>::reverse_iterator ite2 = mstack.rend();
    std::cout << "Stack items in reverse: " << std::endl;
    while (it2 != ite2){
        std::cout << *it2 << std::endl;
        it2++;
    }
}

void test1(){
    std::cout << "TEST OF MUTANT STACK" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    //std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "mstack size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;

    std::cout << "TEST OF A LIST CONTAINER" << std::endl;
    std::list<int> listTest;
    listTest.push_back(5);
    listTest.push_back(17);
    listTest.pop_back();
    std::cout << "listTest size: "<< listTest.size() << std::endl;
    listTest.push_back(3);
    listTest.push_back(5);
    listTest.push_back(737);
    //[...]
    listTest.push_back(0);
    std::list<int>::iterator it2 = listTest.begin();
    std::list<int>::iterator ite2 = listTest.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
    std::cout << *it2 << std::endl;
    ++it2;
    }

}

int main()
{
    //test1();
    //test2();
    return 0;
}
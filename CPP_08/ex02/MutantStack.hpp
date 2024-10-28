#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <stack>
# include <deque>


/* The Standard Template Library offers a stack template, which may be
implemented as a vector, a list, or a deque. stacks are implemented as container adaptors,
which are classes that use an encapsulated object of a specific container class as its underlying container


iterators that we will use from **deque** container for our stack:

iterator: A random-access iterator to iterate from the beginning to the end.

const_iterator: A constant random-access iterator that doesn’t allow modification of elements.

reverse_iterator: A reverse iterator that moves from the end to the beginning.

const_reverse_iterator: A constant reverse iterator that moves backward without modifying elements. 

*/

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {

    private:

    public:

        MutantStack() : std::stack<T, Container>(){};
        MutantStack(const MutantStack & other): std::stack<T, Container>(other){};
        ~MutantStack(){};
        const MutantStack &operator=(const MutantStack & rhs){
            if (this != &rhs)
                std::stack<T, Container>::operator=(rhs);
            return *this;
        };

        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        /* this->c is the encapsulated object of the underlying container,
        you can use it to access the container methods and add more functionalities
        to your stack*/
        
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }

        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }

        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }

        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }

};

#endif
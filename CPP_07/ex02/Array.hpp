#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>
# include <cstdlib>

template <typename T>
class Array{

    private:

        T *_aptr; // to point to the allocated array
        unsigned int _arraySize; // number of elements in the array
		void memError(); //handles memory allocation errors
    
	public:

        // Default constructor 
        Array();
        // Parametric constructor (n: for nb of elements)
        Array(unsigned int n);
        // Copy constructor 
        Array(const Array & other);
        // Destructor
        ~Array();
        // Assignement operator
        const Array &operator=(const Array & rhs);
        // Overloaded [] operator
        T &operator[](const int &); // reading and writing
		const T &operator[](const int &) const; // for reading only
        
		// Accesor to return a specific element 
        unsigned int size() const;

};

class SubscriptOutOfBounds: public std::exception {
	public:
		virtual const char* what() const throw();
};

# include "Array.tpp"

#endif
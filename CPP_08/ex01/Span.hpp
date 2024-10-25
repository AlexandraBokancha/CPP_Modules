#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <set>
# include <algorithm>
#include <cstdlib>

class Span
{
	private:

		unsigned int _N;
		std::multiset<int> _numbers;

    public:

        Span(void);
		Span(unsigned int n);
        Span(const Span& other);
        Span &operator=(const Span &other);
        ~Span();


		void addNumber();
		
		unsigned int shortestSpan();
		unsigned int longestSpan();
		void printSpan() const;

		class ContainerIsFull: public std::exception {
			public:
				virtual const char* what() const throw();
		};

};


#endif


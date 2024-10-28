#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <set>
# include <algorithm>
# include <cstdlib>
# include <iterator>
# include <ctime>
# include <limits>

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

		/* add one single number at time */
		void addNumber(int nb);
		
		/* using a range of iterators */
		void addNumber(std::multiset<int>::iterator start, std::multiset<int>::iterator end);
		
		/* return a shortest/longest distance between all the numbers stored */
		unsigned int shortestSpan();
		unsigned int longestSpan();

		/* display Span content*/
		void printSpan() const;
		
		/* get real-time nb of elements present in a set */
		long unsigned int getSize() const;

		class ContainerIsFull: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class OutOfBounds: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoSpanFound: public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

// generate random multiset with a range (start, end)
std::multiset<int> generate(int size, int start, int end);

#endif


#include "easyfind.hpp"

void test5(){

	/* Copy constructor */

	std::vector<int> v1(5, 6);
	std::vector<int> v2(v1);
	::easyfind(v2, 6);
	::easyfind(v2, 0);
}

void test4(){

	/* Range constructor (iterator1, iterator2)*/
	
	std::vector<int> original(5, 3);
	std::vector<int> copy(original.begin(), original.end());
	::easyfind(copy, 3);
	::easyfind(copy, 5);
}

void test3(){

	/* Fill Constructor with size and value */

	std::vector<int> numbers(5, 10);
	::easyfind(numbers, 10);
	::easyfind(numbers, 0);
	numbers.clear(); // erases all of the elements in the container
	::easyfind(numbers, 10);
}

void test2(){

	/* Fill Constructor with only size*/

	const int SIZE = 10;
	std::vector<int> numbers(SIZE);
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3); // add a new element to the end of the container
	std::cout << "back() returns a reference to a last element which is: " << numbers.back() << std::endl;
	::easyfind(numbers, 2);
	::easyfind(numbers, 5);
	numbers.pop_back(); // removes the last element of the container
	::easyfind(numbers, 3);
}

void test1(){

	/* empty vector : default constuctor */

	std::vector<int> numbers;
	::easyfind(numbers, 0);
	numbers.assign(10, 5); // assign(size, value);
	::easyfind(numbers, 5);
	std::cout << "nb at sub 0: " << numbers.at(0) << std::endl;
}


int main(){
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	return 0;
}
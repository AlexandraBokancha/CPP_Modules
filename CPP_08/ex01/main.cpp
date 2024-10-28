#include "Span.hpp"

void test6(){
	Span sp(10);
	sp.addNumber(1);
	try{
		sp.shortestSpan();
		sp.longestSpan();
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

void test5(){
	Span sp(10000);
	std::multiset<int> nums = generate(500, -200, 300);
	try{
		sp.addNumber(nums.begin(), nums.end());
		std::cout << "span : " << std::endl;
		sp.printSpan();
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

void test4(){
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test3(){
	Span span(12000);
	std::multiset<int> nums = generate(11000, -100, 11900);
	try
	{
		span.addNumber(nums.begin(), nums.end());
		std::cout << "span : " << std::endl;
		span.printSpan();
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "span size " <<  span.getSize() << std::endl;
}

void test2(){
	Span span(100);

	std::multiset<int> nums = generate(10, 1, 100);
	try
	{
		span.addNumber(nums.begin(), nums.end());
		std::cout << "span : " << std::endl;
		span.printSpan();
		std::cout << std::endl;
		std::multiset<int> nums2 = generate(100, 1, 100);
		std::cout << "span size " <<  span.getSize() << std::endl;
		span.addNumber(nums2.begin(), nums2.end());
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

void test1(){
	Span span(10);

	try{
		span.addNumber(3);
		span.addNumber(4);
		span.addNumber(6);
		span.addNumber(11);
		span.addNumber(10);
		span.addNumber(111);
		span.addNumber(2);
		span.addNumber(3);
		span.addNumber(555);
		span.addNumber(64);
		std::cout << "span :" << std::endl;
		span.printSpan();
		std::cout << "trying to add one more :" << std::endl;
 		span.addNumber(0);
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

int main(){

	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	return 0;
}
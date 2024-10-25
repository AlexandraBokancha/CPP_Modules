#include "Span.hpp"

void test1(){
	Span span(10);

	try{
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.addNumber();
		span.printSpan();
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
}

int main(){

	test1();
	return 0;
}
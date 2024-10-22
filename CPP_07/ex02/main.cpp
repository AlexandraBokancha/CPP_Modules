#include <iostream>
#include "Array.hpp"
#define MAX_VAL 750

void test3(){
	/* mandatory test */
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

void test2(){
	Array<double> numbers(5);
	numbers[3] = 4.4;
	std::cout << "Array size: " << numbers.size() << std::endl;
	std::cout << "Array element at sybscript 0 : " << numbers[0] << std::endl;
	std::cout << "Array element at sybscript 3 : " << numbers[3] << std::endl;
	
	/* assignement operator + copy constructor*/
	Array<double> newArray = numbers;
	Array<double> newArray2(3);
	newArray = newArray2;
	
	/* pour montrer que les changement dans l'orginel n'impact
	pas la copie cree par copy constructor */
	
	numbers[2] = 3.2;
	std::cout << "newArray element at sybscript 2 : " << newArray[2] << std::endl;
}

void test1(){
    Array<int> numbers(MAX_VAL);
	numbers[1] = 26;
	std::cout << "Array size: " << numbers.size() << std::endl;
	try{
		std::cout << "Array element at sybscript 1 : " << numbers[1] << std::endl;
		std::cout << numbers[751] << std::endl;
		// numbers[751] = 2; // will throw an exception
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

}

int main(int, char**)
{
	test1();
	test2();
	test3();
	
    return 0;
}
#include "Serializer.hpp"

void test2(){
    Data newData;

    newData.nb = 100;
    newData.str = "my str";

    std::cout << "original nb: " << newData.nb << std::endl;
    std::cout << "original str: " << newData.str << std::endl;

    Data *newData2 = Serializer::deserialize(Serializer::serialize(&newData));

    std::cout << "deserialized nb: " << newData2->nb << std::endl;
    std::cout << "deserialized str: " << newData2->str << std::endl;
    
    if (&newData == newData2)
        std::cout << "they are equal !" << std::endl;
    else
        std::cout << "error" << std::endl;
}

void test1(){
    Data *someRandomData = new Data;
    someRandomData->nb = 5;
    std::cout << "inital nb: " << someRandomData->nb << std::endl;
    uintptr_t newPtr = Serializer::serialize(someRandomData);
    std::cout << "newPtr value: "<< newPtr << std::endl;
    std::cout << newPtr << std::endl;
    //someRandomData->nb = 10;
    Data *newData = Serializer::deserialize(newPtr);
    std::cout << "deserialize nb from someRandomData: " << newData->nb << std::endl;
    delete someRandomData;
}

int main(){
   // test1();
   // test2();
    return 0;
}
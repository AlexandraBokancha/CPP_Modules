#include "iter.hpp"

int main(){
    
    std::cout << "*** TEST1 ***" << std::endl;
    int nums[] = {10, 20, 30};
    const size_t len1 = 3;
    std::cout << "Nums before multiplication by 10: " << std::endl;
    ::iter(nums, len1, &printArray);
    ::iter(nums, len1, &multiplyBy10);
    std::cout << "Nums after multiplication by 10: " << std::endl;
    ::iter(nums, len1, &printArray);
     std::cout << std::endl;

    std::cout << "*** TEST2 ***" << std::endl;
    double nums2[] = {10.2, 20.2, 30.2};
    std::cout << "(Double) Nums before multiplication by 10: " << std::endl;
    ::iter(nums2, len1, &printArray);
    ::iter(nums2, len1, &multiplyBy10);
    std::cout << "(Double) Nums after multiplication by 10: " << std::endl;
    ::iter(nums2, len1, &printArray);
    std::cout << std::endl;
     
    std::cout << "*** TEST3 ***" << std::endl;
    std::string alphabet[] = {"a", "b", "c", "d"};
    const size_t len2 = 4;
    ::iter(alphabet, len2, &printArray);
    ::iter(alphabet, len2, &convertToAscii);


    return 0;
}
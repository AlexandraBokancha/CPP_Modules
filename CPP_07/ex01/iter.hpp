#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <iostream>
#include <string>
#include <cstring>

template <typename T>
void iter(T *arr, const size_t len,  void (*f)(T &)){
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

// pour les fonctions qui modifie pas le array
template <typename T>
void iter(const T *arr, const size_t len,  void (*f)(const T &)){
    for (size_t i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>
void multiplyBy10(T &c){   
    c *= 10;
}

template <typename T>
void printArray(const T & c){
    std::cout << c << std::endl;
}

template <typename T>
void convertToAscii(T & c){
    for (size_t i = 0; i < c.size(); i++){
        std::cout << "ASCII number for " << c[i] << " is : " << static_cast<int>(c[i]) << std::endl;
    }
}

#endif
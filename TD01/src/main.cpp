#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1;
    // f1.display();
    std::cout << " f2 = " << f2;
    // f2.display();
    std::cout << std::endl;

    Fraction f3 = f1 + f2;

    std::cout << "f1 + f2 = " << f3;
    // f3.display();

    Fraction f4 = f1 - f2;
    std::cout << std::endl << "f1 - f2 = " << f4;
    // f4.display();

    Fraction f5 = f1 * f2;
    std::cout << std::endl << "f1 * f2 = " << f5;
    // f5.display();

    Fraction f6 = f1 / f2;
    std::cout << std::endl << "f1 / f2 = " << f6;
    // f6.display();


    // EX 6 : Conversion
    std::cout << std::endl << "f1 = " << f1.to_float();
    float d1 {static_cast<float>(f1)};
    std::cout << std::endl << "d1 = " << d1 ;


   // EX 3-4 : Egalité et comparaison
    if (f1 == f2) {
        std::cout  << std::endl << "f1 est égal à f2";
    } 
    else {
        std::cout  << std::endl << "f1 n'est pas égal à f2";
    }

    if (f1 < f2) {
        std::cout  << std::endl << "f1 est strictement inférieur à f2";
    } 
    else {
        std::cout  << std::endl << "f1 n'est pas strictement inférieur à f2";
    }

    if (f1 <= f2) {
        std::cout  << std::endl << "f1 est inférieur ou égal à f2";
    } 
    else {
        std::cout  << std::endl << "f1 n'est pas inférieur ou égal à f2";
    }

    if (f1 > f2) {
        std::cout  << std::endl << "f1 est strictement supérieur à f2";
    } 
    else {
        std::cout  << std::endl << "f1 n'est pas strictement supérieur à f2";
    }

    if (f1 >= f2) {
        std::cout  << std::endl << "f1 est supérieur ou égal à f2";
    } 
    else {
        std::cout  << std::endl << "f1 n'est pas supérieur ou égal à f2";
    }
    
    
    return 0;
}
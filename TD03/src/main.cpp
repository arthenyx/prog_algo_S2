#include <iostream>
#include "npi.hpp"


int main(){
    std::string npi_str;
    std::cout << "Saisir une expression arithmétique en NPI : ";
    std::getline(std::cin, npi_str);

    std::vector<std::string> tokens = split_string(npi_str);

    float result = npi_evaluate(tokens);
    std::cout << result << std::endl;
}
#include <vector>
#include <algorithm>
#include <iostream>
#include "tri.hpp"

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

int main(){

    std::vector<int> array {1, 12, 3, 14, 5, 16, 7, 18, 9};


    // Affichage du tableau avant tri
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;


    //selection_sort(array);
    bubble_sort(array);


    // Affichage du tableau après tri
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;


    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

}
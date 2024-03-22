#include "tri.hpp"

void selection_sort(std::vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int valeur_min = i;

        for (int j = i+1; j < vec.size(); j++)
        {
            if (vec[j] < vec[valeur_min])
            {
                valeur_min = j;
            } 
        }

        if (valeur_min != i)
        {
            std::swap(vec[i], vec[valeur_min]);
        } 
    }   
}

void bubble_sort(std::vector<int> & vec){
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec[j] > vec[j+1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}
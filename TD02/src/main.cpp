#include <iostream>
#include <algorithm>
#include "tri.hpp"
#include "ScopedTimer.hpp"

int main(){
    {
        ScopedTimer timer("nom du chronomètre");
        // code à chronométrer
    }

    // Tableaux
    //std::vector<int> array {1, 12, 3, 14, 5, 16, 7, 18, 9};
    //std::vector<float> array {1, 12, 3, 14, 5, 16, 7, 18, 9};
    std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};


    // Tableau avec valeurs aléatoires
    // std::srand(std::time(nullptr));
    // std::vector<int> array = generate_random_vector(10);


    // Affichage du tableau avant tri
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;


    // Algorithmes
    //selection_sort(array);
    //bubble_sort(array);
    //merge_sort(array);
    //quick_sort(array);

    // bibliothèque standard
    std::sort(array.begin(), array.end());


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


    //EX 3 :
    // Temps d'exécution
    // Bibliothèque standard : 0.0049ms
    // Selection sort : 0.0061ms
    // Bubble sort : 0.0117ms
    // Merge sort : 0.0071ms
    // Quick sort : 0.0058ms

    // L'algorithme de tri de la bibliothèque standard semble plus rapide que les autres algorithmes de tri.


    //EX 4 :
    int valeur {10};
    int index = search(array, valeur);
    
    if (index != -1) {
        std::cout << "La valeur " << valeur << " a été trouvée à l'indice : " << index << std::endl;
    } else {
        std::cout << "La valeur " << valeur << " n'a pas été trouvée dans le tableau." << std::endl;
    }

}
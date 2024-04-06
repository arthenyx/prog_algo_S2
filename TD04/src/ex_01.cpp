#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <numeric>


int main(){
    //std::list<int> vec(50); 
    // for (int i = 0; i < 50; i++)
    // {
    //     vec[i] = rand()%1000;
        
    //     std::sort(vec.begin(), vec.end());
    // }

    // for (auto it = vec.begin(); it!=vec.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    

    // 1. Remplir un std::vector avec des nombres entiers aléatoires compris entre 0 et 100.
    std::vector<int> val;
    
    for (int i = 0; i < 50; i++)
    {
        int random_num = std::rand() % 100 + 1;
        val.push_back(random_num);
    }
    
    // 2. Utiliser les itérateurs et les méthodes begin et end pour afficher les valeurs du vecteur à l'aide d'une boucle for.
    for (auto it = val.begin(); it!=val.end(); it++)
    {
        std::cout << *it << ",";
    }
    std::cout << std::endl;

    // 3. Chercher si un nombre saisi par l'utilisateur est présent dans le vecteur à l'aide de la fonction std::find et afficher un message adapté.
    std::cout << "Saisissez un nombre : ";
    int nbr{};
    std::cin >> nbr;

    auto it { std::find(val.begin(), val.end(), nbr) };

    if (it != val.end())
    {
        std::cout << nbr << " est présent dans le vecteur." << std::endl;
    }
    else
    {
        std::cout << nbr << " n'est pas présent dans le vecteur." << std::endl;
    }
    
    // 4. Utiliser la fonction std::count pour compter le nombre d'occurrences d'un nombre entier dans le vecteur.
    int nb_occurrences = std::count(val.begin(), val.end(), nbr);
    std::cout << "Nombre d'occurrences dans le vecteur : " << nb_occurrences << std::endl;

    // 5. Utiliser la fonction std::sort pour trier le vecteur.
    std::sort(val.begin(), val.end());

    for (auto it = val.begin(); it!=val.end(); it++)
    {
        std::cout << *it << ",";
    }
    std::cout << std::endl;

    // 6. Utiliser la fonction std::accumulate pour calculer la somme des éléments du vecteur.
    int somme = std::accumulate(val.begin(), val.end(), 0);
    std::cout << "Somme des éléments du vecteur : " << somme << std::endl;

}
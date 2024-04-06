#include <iostream>
#include <string>
#include <vector>

auto const is_space = [](char letter){ return letter == ' '; };

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> mots {};
    std::string mot;

    for (char c : str) 
    {
        if (!is_space(c))
        {
            mot += c;
        }
        else {
            mots.push_back(mot);
            mot.clear();
        }  
    }
    
    if (!mot.empty()) 
    {
        mots.push_back(mot);
    }

    return mots;
}

int premierMot(const std::string& str){
    auto it = std::find_if(str.begin(), str.end(), is_space);
    int nbDeLettres = std::distance(str.begin(), it);

    return nbDeLettres;
}

int main(){
    //std::string str = "pee pee poo poo";
    std::cout << "Ecris une phrase : ";
    std::string str;
    std::getline(std::cin, str);

    std::cout << "Nombre de lettres du premier mot de la phrase : " << premierMot(str) << std::endl;

    std::vector<std::string> nb_mots = split_string(str);
    std::cout << "Nombre de mots dans la phrase : " << nb_mots.size() << std::endl;
    
}
#include <iostream>
#include <string>

bool is_palindrome(const std::string& str){
    auto debut_str = std::begin(str);
    auto fin_str = std::end(str);

    auto debut_str_reverse = std::rbegin(str);
    auto fin_str_reverse = std::rend(str);

    bool is_palindrome = std::equal(debut_str, fin_str, debut_str_reverse, fin_str_reverse);
    
    return is_palindrome;
}

int main(){
    std::cout << "Saisissez une chaîne de caractères : ";
    std::string mot;
    std::getline(std::cin, mot);

    bool palindrome = is_palindrome(mot);

    if (palindrome)
    {
        std::cout << "Cette chaîne de caractères est un palindrome ! Yipee !!" << std::endl;
    }
    else{
        std::cout << "Cette chaîne de caractères n'est pas un palindrome :(" << std::endl;
    }
    
}
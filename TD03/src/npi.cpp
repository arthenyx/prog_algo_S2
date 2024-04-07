#include "npi.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>
#include <iostream>


std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating(std::string const& s){
    bool is_float = false;

    for (char c : s)
    {
        if (std::isdigit(c)){
            continue;
        }
        else if (c == '.'  && !is_float){
            is_float = true;
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const& tokens){
    std::stack<float> stack;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        if (is_floating(tokens[i]))
        {
            stack.push(std::stof(tokens[i]));
        }
        else {
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result;
            
            if (tokens[i] == "+")
            {
                result = leftOperand + rightOperand;
            }
            else if (tokens[i] == "-")
            {
                result = leftOperand - rightOperand;
            }
            else if (tokens[i] == "*")
            {
                result = leftOperand * rightOperand;
            }
            else if (tokens[i] == "/")
            {
                result = leftOperand / rightOperand;
            }
            else if (tokens[i] == "^")
            {
                result = pow(leftOperand, rightOperand);
            }
                
            stack.push(result);
        }
    }

    if (stack.size() != 1)
        {
            std::cout << "Expression NPI invalide." << std::endl;
        }

    return stack.top();
}

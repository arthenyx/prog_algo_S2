#include <iostream>
#include <vector>
#include <stack>
#include "npi.hpp"


// EX 2 :
enum class Operator { ADD, SUB, MUL, DIV };
enum class TokenType { OPERATOR, OPERAND };

struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value){
    return Token{TokenType::OPERAND, value, Operator::ADD};
}

Token make_token(Operator op){
    return Token{TokenType::OPERATOR, 0.0f, op};
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens {};

    for (size_t i = 0; i < words.size(); i++) 
    {
        if (words[i] == "+")
        {
            tokens.push_back(Token{TokenType::OPERATOR, 0.0f, Operator::ADD});
        }
        else if (words[i] == "-")
        {
            tokens.push_back(Token{TokenType::OPERATOR, 0.0f, Operator::SUB});
        }
        else if (words[i] == "*")
        {
            tokens.push_back(Token{TokenType::OPERATOR, 0.0f, Operator::MUL});
        }
        else if (words[i] == "/")
        {
            tokens.push_back(Token{TokenType::OPERATOR, 0.0f, Operator::DIV});
        }
        else 
        {
            float value = std::stof(words[i]);
            tokens.push_back(Token{TokenType::OPERAND, value, Operator::ADD});
        } 
    }

    return tokens;
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack;

    for (size_t i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].type == TokenType::OPERAND)
        {
            stack.push(tokens[i].value);
        }
        else if (tokens[i].type == TokenType::OPERATOR)
        {
            float rightOperand { stack.top() };
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();

            if (tokens[i].op == Operator::ADD)
            {
                stack.push(leftOperand + rightOperand);
            }
            else if (tokens[i].op == Operator::SUB)
            {
                stack.push(leftOperand - rightOperand);
            }
            else if (tokens[i].op == Operator::MUL)
            {
                stack.push(leftOperand * rightOperand);
            }
            else if (tokens[i].op == Operator::DIV)
            {
                stack.push(leftOperand / rightOperand);
            } 
        }
    }

    if (stack.size() != 1)
    {
        std::cout << "Expression NPI invalide." << std::endl;
    }

    return stack.top();
}


int main(){
    std::string npi_str;
    std::cout << "Saisir une expression arithmétique en NPI : ";
    std::getline(std::cin, npi_str);

    // EX 1 :
    // std::vector<std::string> tokens = split_string(npi_str);
    // float result = npi_evaluate(tokens);
    // std::cout << result << std::endl;

    // EX 2 :
    std::vector<std::string> tokens_str = split_string(npi_str);
    std::vector<Token> tokens = tokenize(tokens_str);

    float result = npi_evaluate(tokens);
    std::cout << result << std::endl;
}
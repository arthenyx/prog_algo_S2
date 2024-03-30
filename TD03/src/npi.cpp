#include "npi.hpp"
#include <cctype>
#include <stack>

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

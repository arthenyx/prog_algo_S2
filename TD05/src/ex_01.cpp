#include <iostream>
#include <string>

size_t folding_string_hash(std::string const& s, size_t max){
    size_t sum {0};

    for (char c : s)
    {
        size_t value_ascii = static_cast<size_t>(c);
        sum += value_ascii;
    }
    
    return sum % (max + 1);
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t sum {0};
    
    for (size_t i = 0; i < s.size(); i++)
    {
        size_t value_ascii = static_cast<size_t>(s[i]);
        sum += value_ascii * (i + 1);
    }
    
    return sum % (max + 1);
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t sum {0};
    size_t power {1};

    for (char c : s)
    {
        size_t value_ascii = static_cast<size_t>(c);
        sum += (value_ascii * power);
        power *= p;
    }

    return sum % m;
}

int main(){
   std::string str = "pee pee poo poo";
   
   size_t max {1024};
   size_t p {31};
   size_t m {1031};

   std::cout << folding_string_hash(str, max) << std::endl;
   std::cout << folding_string_ordered_hash(str, max) << std::endl;
   std::cout << polynomial_rolling_hash(str, p, m) << std::endl;
}
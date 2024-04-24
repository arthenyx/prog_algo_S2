#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

std::string random_name(size_t size) {
    std::string name {""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for(size_t i {0}; i < size; ++i) {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
    std::vector<std::pair<std::string, float>> robots_fix {};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        // random name 
        std::string robotName { random_name(2) };
        // random cost
        float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const& robots_fixes){
    std::unordered_map<std::string, std::vector<float>> map {};

    for (size_t i = 0; i < robots_fixes.size(); i++)
    {
        auto robot_name = map.find(robots_fixes[i].first);
        if (robot_name != map.end())
        {
            map[robots_fixes[i].first].push_back(robots_fixes[i].second);
        }
        else
        {
            map[robots_fixes[i].first] = { robots_fixes[i].second };
        }
        
    }
    return map;
}

float sum_vector(std::vector<float> const& vec){
    float sum {0};

    for (size_t i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    
    return sum;
}


int main() {
    std::vector<std::pair<std::string, float>> robots = get_robots_fix(50);
    std::unordered_map<std::string, std::vector<float>> robots_fixes = robots_fixes_map(robots);

    for(const auto& robot : robots_fixes) 
    {
        std::cout << "Nom du robot : " << robot.first << " | Coûts des réparations : ";
        for(float repair_cost : robot.second) 
        {
            std::cout << repair_cost << " ; ";
        }

        float sum_total = sum_vector(robot.second);
        std::cout << " | Coût total des réparations : " << sum_total;
        std::cout << std::endl;
    }

}
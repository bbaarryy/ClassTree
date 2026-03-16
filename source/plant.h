#pragma once

#include <string>
#include <iostream>
#include <algorithm>

class Plant {
protected:
    float max_height;
    std::string climate;
    int lifetime;
    int min_temp, max_temp;
    int watering;
public:
    std::string name;

    Plant() {
        std::cout << "Create plant" << '\n';
        this->min_temp = -1;
        this->max_temp = -1;
        this->watering = -1;
    }

    virtual void touch() { std::cout << "" << '\n'; }
    virtual void shake() { std::cout << "" << '\n'; }
    

    int survivalability() {
        return (this->lifetime + this->max_temp - this->min_temp) * std::min(0.9f, std::max(1.2f, (1.0f / max_height)));
    }
};
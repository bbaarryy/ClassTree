#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <plant.h>
#include <ctime>
#include <chrono>
#include <random>
#include <thread>

using std::cout;

std::mt19937 rnd2(std::chrono::steady_clock::now().time_since_epoch().count());

class TropicalPlants: public Plant{
public:
    TropicalPlants(){
        this->climate = "Tropical, Subtropical";
        this->min_temp = 15;
        this->max_temp = 40;
        this->watering = 80;
    }
    
    void touch() override{
        std::cout << "Hmm... Something hot with sunny on the beach" << '\n';
    }
};

class Palm: public TropicalPlants{
public:
    Palm(){
        this->max_height = 10;
    }
    
    void touch() override{
        std::cout << "You can climb" << '\n';
    }
    
    void shake() override{
        int lucky = rnd2()%3;
        switch(lucky){
            case 0:
                std::cout << "Oh! Bananas!" << '\n';
                break;
            case 1:
                std::cout << "Ouch*** Coconut just falled on my head!" << '\n';
                break;
            case 2:
                std::cout << "Hmmm... Nothing" << '\n';
                break;
        }
    }
};

class cactuse: public TropicalPlants{
public:
    cactuse(){
        this->watering = 3;
        this->max_height = 0.5;
    }
    
    void touch() override{
        cout << "Ahh... Its spiky" << '\n';
    }

    void shake() override{
        cout << "Not the best idea" << '\n';
    }
};

class fat_bush: public TropicalPlants{
public:
    fat_bush(){
        this->watering = 40;
        this->max_height = 1.3;
    }
    
    void touch() override{
        cout << "Nothing special" << '\n';
    }

    void shake() override{
        cout << "Fshh" << '\n';
    }
};

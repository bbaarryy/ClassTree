#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;
#define vi vector<int>
#define REP(n) for(int i = 0 ; i < n ; i++)

class Plant{
protected:
    float max_height;
    string climate;
    int lifetime;

public:
    Plant(){
        REP(5){
            test.push_back(i);
        }
    }
    //virtual int Danger() = 0;
    // virtual int LifePossibility() = 0;
};

class TropicalPlants: public Plant{
public:
    TropicalPlants(){
        this->climate = "Tropical, Subtropical";
    }

    void test_fun(){
        REP((this->test).size()){
            cout << this->test[i] << '\n';
        }
    };

};

int main(){
    //
    // --checking classes
    //

    TropicalPlants Coconut_tree;
    Coconut_tree.test_fun();
}


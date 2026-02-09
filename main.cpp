#include <iostream>
#include <algorithm>

using namespace::std;

class Plant{
    protected:
        float max_height;
        string climate;

    public:
        virtual int Danger() = 0;
        virtual int LifePossibility() = 0;
};

class TropicalPlants: public Plant{
    
};

int main(){
    //
    // --checking classes
    //
}


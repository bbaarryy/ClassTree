#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <chrono>
#include <random>

using namespace::std;
#define vi vector<int>
#define REP(n) for(int i = 0 ; i < n ; i++)

std::mt19937 rnd2(std::chrono::steady_clock::now().time_since_epoch().count());

class Plant{
protected:
    float max_height;
    string climate;
    int lifetime;
    int min_temp,max_temp;
    int watering;

    bool operator< (Plant& Other){
        return this->survivalability() < Other.survivalability();
    };
public:
    Plant(){
        this->min_temp = -1;
        this->max_temp = -1;
        this->watering = -1;
    }

    bool compitability(Plant Other){
        return ((Other.max_temp - this->max_temp) < 5 ) && ((Other.min_temp - this->min_temp) < 5);
    };
    virtual void touch() = 0;
    virtual void shake() = 0;

    int survivalability(){
        return (this->lifetime + this->max_temp - this->min_temp) * min(0.9,max(1.2, (1/((double)max_height))));
    }

};

class TropicalPlants: public Plant{
public:
    TropicalPlants(){
        this->climate = "Tropical, Subtropical";
        this->min_temp = 15;
        this->max_temp = 40;
        this->watering = 80;
    }
    
    void touch(){
        cout << "Hmm... Something hot with sunny on the beach" << '\n';
    }
};

class Palm: public TropicalPlants{
public:
    Palm(){
        this->max_height = 10;
    }
    
    void touch(){
        cout << "You can climb" << '\n';
    }

    void shake(){
        int lucky = rnd2()%3;
        switch(lucky){
            case 0:
                cout << "Oh! Bananas!" << '\n';
            case 1:
                cout << "Ouch*** Coconut just falled on my head!" << '\n';
            case 2:
                cout << "Hmmm... Nothing" << '\n';
        }
    }
};

class cactuse: public TropicalPlants{
public:
    cactuse(){
        this->watering = 3;
        this->max_height = 0.5;
    }
    
    void touch(){
        cout << "Ahh... Its spiky" << '\n';
    }

    void shake(){
        cout << "Not the best idea" << '\n';
    }
};

class fat_bush: public TropicalPlants{
public:
    fat_bush(){
        this->watering = 40;
        this->max_height = 1.3;
    }
    
    void touch(){
        cout << "Nothing special" << '\n';
    }

    void shake(){
        cout << "Fshh" << '\n';
    }
}; 

int main(){
    //
    // --checking classes
    //

    // string s;
    // vector<Plant> collecture;

    // while(true){
    //     cin >> s;
    //     string arr[10];

    //     string curr_w = "";
    //     int ind=0;
    //     for(int i = 0 ; i < s.size();i++){
    //         if(s[i] == ' '){
    //             arr[ind]=curr_w;
    //             ind++;
    //             curr_w =  "";
    //         }
    //         else{
    //             curr_w +=s[i];
    //         }
    //     }
    //     arr[ind] = curr_w;
    //     if(arr[0] == "create" || arr[0] == "c"){
    //     }
    // }

    Palm Royal;
    Royal.shake();

}


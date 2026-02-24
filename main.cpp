#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <chrono>
#include <random>
#include <thread>

using namespace std;

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;
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

   
public:
    string name;

    Plant(){
        cout << "create plant" << '\n';
        this->min_temp = -1;
        this->max_temp = -1;
        this->watering = -1;
    }

    void touch(){cout << "" << '\n';}
    void shake(){cout << "" << '\n';}

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
                break;
            case 1:
                cout << "Ouch*** Coconut just falled on my head!" << '\n';
                break;
            case 2:
                cout << "Hmmm... Nothing" << '\n';
                break;
        }
    }
};

class cactus: public TropicalPlants{
public:
    cactus(){
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

    string s;
    vector<Plant*> collecture;

    while(true){
        getline(cin, s);
        string arr[10];

        string curr_w = "";
        int ind=0;
        for(int i = 0 ; i < s.size();i++){
            if(s[i] == ' '){
                arr[ind]=curr_w;
                ind++;
                curr_w =  "";
            }
            else{
                curr_w +=s[i];
            }
        }
        arr[ind] = curr_w;

        if(arr[0] == "create" || arr[0] == "c"){
            if(arr[1] == "palm"){
                Palm* ch = new Palm;
                ch->name = arr[2];
                collecture.push_back(ch);
            }
        }
        if(arr[0] == "touch"){
            //cout<< arr[0]<< ' ' << arr[1] <<'\n';
            collecture[stoi(arr[1])]->touch();
        }
        if(arr[0] == "shake"){
            collecture[stoi(arr[1])]->shake();
        }

        sleep_for(nanoseconds(100));
    }
}


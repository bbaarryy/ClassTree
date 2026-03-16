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

#include <tropical_plants.h>
#include <plant.h>
#include <home_plants.h>

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


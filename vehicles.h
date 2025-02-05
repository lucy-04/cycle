#include<iostream>
using namespace std;

class Vehicle { 
    int vehicleNumber;
public:
    void vNum(int n){
        vehicleNumber=n;
    }
    int getvnum(){
        return vehicleNumber;
    }

    virtual void display() = 0;
};

class Cycle: public Vehicle{
    bool cyclestate;
public:
    Cycle():cyclestate(1){}

    void takecycle(){
        cyclestate=0;
    }

    void display(){
            cout<<"   "<<getvnum()<<endl;
        
        
    }

    void  addcycle(){
        if(cyclestate== 0){
            cyclestate =1;
        }
    }
};
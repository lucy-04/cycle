#include<iostream>
using namespace std;
#include"user.h"
#include"vehicles.h"

double rentValue;

class Rent : public User , public Cycle{
private:
    string startTime;
    string endTime;
    long long interval; 
    int cycleno;
public:
    Rent():interval(0){}
    Rent(long long intvl):interval(intvl){}
    Rent(const string regNum, const long phoneNum, const string userName,long long intvl, const string start, const string end, const int n/*Vehicle* type*/)
        : User(regNum, phoneNum, userName), interval(intvl) ,startTime(start), endTime(end),cycleno(n) {}

    friend double calculateRent(const Rent& rent); 
    friend void displayRentInfo(const Rent& rent); 
    long long displayinterval(){
        return interval;
    }

    Rent operator+(const Rent& other) const {
        Rent temp;

       
        temp.interval = interval + other.interval;

        return temp; 
    }
    int getcycleno(){
        return cycleno;
    }
};
double calculateRent(const Rent& rent) {
    double rps = 0.5;
    rentValue = (rps * rent.interval * 0.001);
    return rentValue;
}

void displayRentInfo(const Rent& rent) {
    rent.displayUserInfo();
    cout << "cycle no.:" << rent.cycleno <<endl;
    cout << "Start Time: " << rent.startTime << endl;
    int x = 0;
    cout << "End Time: " << rent.endTime << endl;

    cout << "Interval: " << rent.interval << " milliseconds" << endl;
    cout << "Total Rent: Rs. " << int(calculateRent(rent)) << endl;
}

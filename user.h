#include<iostream>
using namespace std;

class User {
protected:
    string registrationNumber;
    long phoneNumber;
    string name;
public:
    User(){}
    User(const string regNum, const long phoneNum, const string userName)
        : registrationNumber(regNum), phoneNumber(phoneNum), name(userName) {}

    void displayUserInfo() const{
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Name: " << name << endl;
    }
};

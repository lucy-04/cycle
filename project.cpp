#include <iostream>
#include"rent.h"
#include"time.h"
#include"data.h"
using namespace std;


int main() {
    int ar[100];
    Rent rents[100];
    int num= -1;
    int x , y;
    string r;
    cout << "--> ENTER REGISTRATION NUMBER: "<<endl;
    cin >> r;
    int re;
    Vehicle *ptr;
    Cycle c[100];

    for (int i = 0; i < 100; i++)
    {
        ptr = &c[i];
        ptr -> vNum(i+1);
    }

    while(1){
        num++;
        string t;
        cout << "DO YOU WANT A RIDE (Y/N):";
        cin >> t;
        if (t=="Y")
        {
            for (int i = 0; i < 5; i++){
            if (r == regno[i]){
            cout << "__________________MENU____________________"<<endl<<endl;
            cout <<"--> PRESS 1 FOR TAKING CYCLE"<<endl;

            cin >> x;
            if (x == 1)
            {   
                cout << "ENTER CYCLE NO."<<endl;
                cin >> y;
                ar[num] = y;
                Rent rent(regno[i],phno[i], name[i], interval(), start_str, end_str,y);
                cout << "Rent Information for "<<name[i]<< " is:"<< endl;
                displayRentInfo(rent);
                cout << endl;
                c[rent.getcycleno()-1].takecycle();
                re  = calculateRent(rent);
                rents[num] = rent;
            }
            else
            {
                cout<<"ENTER A PROPER VALUE"<<endl;
            }
            cout <<"--> PRESS 2 FOR PAYING RENT"<<endl;
            cin >> x;
            if (x == 2){
                int amount;
                cout << "ENTER AMOUNT :";
                cin >> amount;
                if (amount == re)
                {
                    c[y-1].addcycle();
                    cout << "_______AMOUNT PAID______"<<endl;
                    cout << "_______THANK YOU______"<< endl;
                }
                else
                {
                    cout << "ENTER PROPER AMOUNT"<<endl;
                }
            
            }
            else
            {
                cout<<"ENTER A PROPER VALUE"<<endl;
            }
            

            break;
            
            
        }
        else
            {
                cout << "YOUR REGISTRATION NO. IS WRONG"<<endl;
                break;
            }
        
    }
        }
        
    else
    {
        cout << "_______THANK YOU______"<< endl;
        break;
    }
    

    }

    //ADMIN
    Rent total_rent;
    int totalrides = num+1;
    for (int i = 0; i < totalrides; i++)
    {
        total_rent = total_rent + rents[i];
    }
    cout << int(calculateRent(total_rent))<< endl;

    cout << "vehicle no." <<endl;
    for (int i = 0; i <= num; i++)
    {
        int j = ar[i];
        ptr = &c[j-1];
        ptr -> display();
    }
    return 0;
}
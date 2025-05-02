#include<iostream>
using namespace std;
#include<chrono>
#include<ctime>
void current_start_time();
void current_end_time();
int interval();
string start_str ="0";
string end_str = "0";

int interval() {
    
    chrono::steady_clock::time_point end;

    auto start = chrono::steady_clock::now();
    current_start_time();
    int x = -1;
    
    while(x!=0)
    {
        cout << " PRESS 0 TO TERMINATE TRIP "<<endl;
        cin >> x;
        
    }
    end = chrono::steady_clock::now();

    
    current_end_time();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    int duration_int = static_cast<int>(duration);

    return duration_int;
}

void current_start_time() {
    time_t my_time = time(nullptr);
    start_str = ctime(&my_time);
}
void current_end_time() {
    time_t my_time = time(nullptr);
    end_str = ctime(&my_time);
}
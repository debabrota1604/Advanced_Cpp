#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;

// Run two threads that print even and odd numbers respectively from 1 to 10

mutex mtx;

void print_odd(int& count){
    while(count <10){
        mtx.lock(); //lock before access
        if(count%2 ==1){
            cout << "ODD: " << count << endl;
            count++;
        }
        mtx.unlock(); //unlock post access
    }
}

void print_even(int& count){
    while(count <10){
        mtx.lock();
        if(count%2 ==0){
            cout << "EVEN: " << count << endl;
            count++;
        }
        mtx.unlock(); //unlock post access
    }
}

int main(){
    int count = 1; // Shared variable to keep track of count 

    thread t1(print_odd, ref(count)); // Thread for printing odd numbers
    thread t2(print_even, ref(count)); // Thread for printing even numbers

    t1.join();
    t2.join();
}
#include<iostream>
using namespace std;

int main() {
    int a; //declaration
    a = 12; //initialization

    cout<<"size of int "<<sizeof(a)<<endl;

    float b;
    cout<<"size of float "<<sizeof(b)<<endl;

    char c;
    cout<<"size of char "<<sizeof(c)<<endl;

    bool d;
    cout<<"size of bool "<<sizeof(d)<<endl;

    short int si;
    long long int li;

    cout<<"Size of short int "<<sizeof(si)<<endl;
    cout<<"Size of long int "<<sizeof(li)<<endl;

    return 0;
}

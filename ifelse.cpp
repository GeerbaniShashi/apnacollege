#include<iostream>
using namespace std;

int main() {
    /*
    #ifdef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    */

    int savings;
    cin>>savings;
    /*
    if(savings > 5000) {
        cout<<"Neha\n";
    } else {
        cout<<"Rashmi\n";
    }
     */
     /*
     if(savings > 5000) {
        cout<<"Neha\n";
     } else if(savings > 2000) {
        cout<<"Rashmi\n";
     } else {
         cout<<"Friends\n";
     }
     */
     //nested if else
     if(savings > 5000) {
        if(savings > 10000) {
            cout<<"Roadtrip with Neha\n";
        } else {
            cout<<"Shopping with neha\n";
        }
     } else if(savings > 2000) {
        cout<<"Rashmi\n";
     } else {
         cout<<"Friends\n";
     }

    return 0;
}

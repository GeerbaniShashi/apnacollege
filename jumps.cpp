#include<iostream>
using namespace std;

int main() {

    int pocketMoney = 3000;
    for(int date = 1; date<=30; date++) {
        if(date % 2 == 0) {
            continue;
        }
        cout<<"Go out today!"<<endl;
        pocketMoney = pocketMoney - 300;

        if(pocketMoney == 0) {
            break;
        }
    }
    return 0;
}

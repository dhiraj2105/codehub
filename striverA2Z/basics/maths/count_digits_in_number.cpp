#include <bits/stdc++.h>
using namespace std;

int bruteForce(int num){
    int counter = 0;
    while(num > 0){
        counter++;
        num = num / 10;
    }
    return counter;
}

int main(){
    // count total number of digits in a number
    int num = 123456;

    cout << "Total number of digit using brute force method : "<< bruteForce(num);

    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int stairCase(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    if (n < 0){
        return 0;
    }
    return stairCase(n-1) + stairCase(n-2) + stairCase(n-3);
};


int main(){
    int n = 4;

    int num_ways = stairCase(n);
    cout << num_ways << endl;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Can transfer disk, one at a time, smaller disk cannot rest on big disk
// answer is 2^n - 1

int TowerOfHanio(int n){

    if (n == 0){
        return 0;
    }
    
    return 2 * TowerOfHanio(n-1) + 1 ;
};

int main(){

    int n = 5;
    int steps = TowerOfHanio(n);
    cout << steps << endl;

};
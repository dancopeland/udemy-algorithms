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
    return TowerOfHanio(n-1) + 1 + TowerOfHanio(n-1);
};

void ToHprint(int n, char s, char d, char h){
    if (n==0){
        return;
    }
    ToHprint(n-1, s, h, d);

    cout << "moving disk " << n <<" from " << s << " to " << d << endl;

    ToHprint(n-1, h, d, s);
    return;
};

int main(){

    int n = 3;
    int steps = TowerOfHanio(n);
    cout << steps << endl;

    ToHprint(3, 's', 'd', 'h');

};
#include <iostream>

using namespace std;

int SumArray(int a[], int n){
    //base
    if (n == 0){
        return 0;
        }

    // small array sum
    //small array sum plus last charactar
    return a[0] + SumArray(a+1, n-1) ;
}

int SumArray2(int a[], int n){
    //base
    if (n == 0){
        return 0;
        }

    // small array sum
    //small array sum plus last charactar
    return a[n-1] + SumArray2(a, n-1) ;
}

int SumArray3(int a[], int n, int i){
    //base
    if (n == i){
        return 0;
    }

    // small array sum
    //small array sum plus last charactar
    return a[i] + SumArray3(a, n, i+1) ;
}


int main(){
    cout << "Enter length of array, followed by values" << endl;
    int n = 5; 
    int c[] = {1,2,3,4,5};
    
    cout << "The sum of the array is " << SumArray(c,n) << endl;
    return 0;

}
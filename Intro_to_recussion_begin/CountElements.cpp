#include <iostream>
#include <string>

using namespace std;

int CountElements(int a[], int n, int x, int count){
    // base case
    
    if (n == 0){return count;}

    if (a[0] == x){
        count++;
    }
    return CountElements(a+1, n-1, x, count);
}

int main(){
    cout << "Enter a number to be searched for in a prebuilt array: ";
    int x;
    cin >> x;

    int c[] = {1,1,3,4,5};
    
    int nelements = CountElements(c, 5, x, 0);

    if (nelements == 0 ){
        cout << "No occurances of " << x << " were found in the array";
    }
    else {
        cout << nelements << " occurances of " << x << " were found in the array!";
    }

}

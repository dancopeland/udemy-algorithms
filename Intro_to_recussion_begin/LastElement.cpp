#include <iostream>

using namespace std;

int LastElement(int a[], int n, int x){
    // base case
    
    if (n == 0){
        return -1;
    }
    else if (a[n-1] == x){
        return n-1;
    }

    return LastElement(a, n-1, x);
}

int main(){
    cout << "Enter value to be searched for in an prebuilt array" << endl;
    int x ;
    cin >> x; 
    int c[] = {1,1,3,4,5};
    
    
    int index = LastElement(c, 5, x);

    if (index != -1){
        cout << "The value " << x << " was found at index " << index << endl;
        }
    else {
        cout << "The value " << x << " was NOT FOUND..." << endl;
    }
    return 0;

}


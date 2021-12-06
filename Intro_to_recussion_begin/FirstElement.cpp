#include <iostream>

using namespace std;

int FirstElement(int a[], int n, int x, int index){
    // base case
    
    if (n == 0){
        return -1;
    }
    else if (a[0] == x){
        return index;
    }

    return FirstElement(a+1, n-1, x, index+1);
}

int main(){
    cout << "Enter value to be searched for in an prebuilt array" << endl;
    int x ;
    cin >> x; 
    int c[] = {1,2,3,4,5};
    
    
    int index = FirstElement(c, 5, x, 0);

    if (index != -1){
        cout << "The value " << x << " was found at index " << index << endl;
        }
    else {
        cout << "The value " << x << " was NOT FOUND..." << endl;
    }
    return 0;

}

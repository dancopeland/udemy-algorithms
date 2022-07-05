#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchRSA(int a[], int l, int key){
    int index = -1;
    int s = 0;
    int e = l - 1;
    int mid = s + (e-s)/2;

    if (key >= a[s]){ 
        while(s <= e) {
            if (key == a[mid]){
                return mid;
            }
            else if(key => a[mid]){
                e = mid-1;
            }
            else if(key => a[mid]){
                e = mid-1;
            }
        }
        else if (key > )
        else if (key >= a[mid]) {}}
    else {

    }
    };

    


    return index;
}



int main(){
    /*
    //input sorted fuction, or input array then sort...
    cout << "Give sorted array length" << endl;
    int n;
    cin >> n;
    int a[n];

    cout << "Give sorted values of array, in ascending order" << endl;

    for (int i = 0; i < n; i++){
        cout << "Input value " << (i+1) <<  ": " << endl;
        cin >> a[i];
    }

    cout << "Give key to search for" << endl;
    int key;
    cin >> key;

    sort(a,a+n);

    //pass rotated sorted array no duplicates
    */
    int a[100] = {6,8,9,10,1,2,3,4,5}; // rotated around 6
    int index;
    int r = 6;
    index = searchRSA(a, n, key);

    //return index of found key or report that the key was not found
    if (index == -1){
        cout << "key not found" << endl;
    }
    else {
        cout << "Key was found at index: " << index << endl;}
    
}
#include <iostream>

using namespace std;

bool ArraySorted(int c[], int n){
    if (n == 0 || n == 1) {return true;}
    else if (c[0]>c[1]){return false; } //this is doing the heavy lifting, arrays are loosing the first element due to Array sorted then being checked here. IF they pass they check the next element

    bool is_small_sorted = ArraySorted(c+1, n-1);
    /*
    if (is_small_sorted == true){
        return true;
    }
    else{
        return false;
    }

    bool is_bigger_sorted = false;
     if(is_small_sorted && c[n-1] < c[n]) {
        is_bigger_sorted = true;
        }
        return is_bigger_sorted;
        */
    return is_small_sorted;


}

bool ArraySorted2(int c[], int n){
    if (n == 0 || n == 1) {return true;}
    
    bool is_small_sorted = ArraySorted2(c+1, n-1);
    if (!is_small_sorted){
        return false;
    }  
    if (c[0]>c[1]){
        return false; 
    } //this is doing the heavy lifting, arrays are loosing the first element due to Array sorted then being checked here. IF they pass they check the next element
    else{
        return true;
    }
    return is_small_sorted;
}

bool ArraySorted3(int c[], int n){
    if (n == 0 || n == 1) {return true;} //this is the base value
    
    if (c[n-2]>c[n-1]){
        return false; //this is doing the heavy lifting
    } 
    return ArraySorted3(c, n-1);
}

int main(){
    cout << "Enter length of array, followed by values" << endl;
    int n;
    cin >> n; 
    int c[n];

    for(int i = 0; i < n; i++){
        cout << "Enter value "<< i << endl;
        cin >> c[i];
    }

    bool is_sorted = ArraySorted3(c,n);
    if (is_sorted == false){
        cout << "The array is not sorted" << endl; 
    }
    else {
        cout << "The array is sorted!" << endl;
    }

    

}
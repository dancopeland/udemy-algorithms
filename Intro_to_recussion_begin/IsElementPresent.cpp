#include <iostream>

using namespace std;

bool IsElementPresent(int c[], int n, int x){
    if (n==0){
        return false;
    }
    if (c[0]==x){
        return true;
    }
    return IsElementPresent(c+1, n-1, x);

}

bool IsElementPresent2(int c[], int n, int x){
    if (n==0){
        return false;
    }

    bool remArr = IsElementPresent2(c+1, n-1, x);
    if (remArr){
        return true;
    }
    if (c[0]==x){
        return true;
    }
    else{
        return false;
    }


}

bool IsElementPresent3(int c[], int n, int x){
    if (n==0){
        return false;
    }
    if (c[n-1]==x){
        return true;
    }
    return IsElementPresent3(c, n-1, x);

}


bool IsElementPresent3(int c[], int n, int x){
    if (n==0){
        return false;
    }
    if (c[n-1]==x){
        return true;
    }
    return IsElementPresent3(c, n-1, x);

}

int main(){
    cout << "Enter value to be searched for in an prebuilt array" << endl;
    int x ;
    cin >> x; 
    int c[] = {1,2,3,4,5};
    
    bool found = false;
    if (IsElementPresent3(c, 5, x)){found = true;}
    if (found == true){
        cout << "The value " << x << " was found!" << endl;
        }
    else {
        cout << "The value " << x << " was NOT FOUND..." << endl;
    }
    return 0;

}
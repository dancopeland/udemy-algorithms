#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getFirst(vector<int>& v, int key){
    int s = 0;
    int e = v.size() - 1;
    int mid = s + ((e - s)/2);
    int first = -1;

    while (s <= e){
        if (v[mid] == key){
            first = mid;
            e = mid - 1;
        }
        else if(key > v[mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + ((e - s)/2);

    }
    return first;

}

int getLast(vector<int>& v, int key){
    int s = 0;
    int e = v.size() - 1;
    int mid = s + ((e - s)/2);
    int last = -1;

    while (s <= e){
        if (v[mid] == key){
            last = mid;
            s = mid + 1;
        }
        else if(key > v[mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + ((e - s)/2);

    }
    return last;

}

int main(){
    cout << "test" << endl;
    int arr[11] = {1,2,3,4,5,5,5,6,8,9,10};
    vector<int> v;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    for (int i =0;i<=arrSize; i++){
        v.push_back(arr[i]);
    };
    // int answer = First_Occurance(a, 11, 5, -1);
    int answer = getFirst(v, 5);
    cout << "First occurance at poistion: " << answer <<  endl;
    // answer = Last_Occurance(a, 11, 5, -1);
    answer = getLast(v, 5);
    cout << "Last occurance at poistion: " << answer <<  endl;
    return 0;
};




/*
int First_Occurance(int a[], int n, int key, int first){
    int s = 0;
    int e = n - 1;
    int mid = (s + e)/2;

    while (e >= s){
        if (a[mid] == key){
            first = mid;
            e = mid - 1;
        }
        else if(key < a[mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = (s + e)/2;

    }
    return first;
};

int Last_Occurance(int a[], int n, int key, int last){
    int s = 0;
    int e = n - 1;
    int mid = (s + e)/2;

    while (e >= s){
        if (a[mid] == key){
            last = mid;
            s = mid + 1;
            mid = (s + e)/2;
        }
        else if(a[mid] > key){
            s = mid + 1;
            mid = (s + e)/2;
        }
        else{
            e = mid - 1;
            mid = (s + e)/2;
        }
    }
    return last;
};

*/

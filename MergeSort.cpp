#include <iostream>
#include <vector>

using namespace std;

int length(int input[]){
    if (input[0] == '\0'){
        return 0;
    }
    return 1 + length(input + 1);
};

//void mergeSortVec(vector<int> &vec){
//};

void mergeArrays(int x[], int y[], int a[], int s, int e){
    int m = (s+e)/2;
    int i = s, j = m+1, k = s; 
    while(i <= m && j <= e){
        if (x[i]<y[j]){
            a[k] = x[i];
            i++;
            k++;
        }
        else{
            a[k] = y[j];
            j++;
            k++;
        }
    }
        while(i<=m){
            a[k] = x[i];
            i++;
            k++;
        }
        while(j<=e){
            a[k] = y[j];
            j++;
            k++;
        }

    

};

void mergeSort(int a[], int s, int e){
    if (s >= e){
        return;
    }
    int m = (e+s)/2; // rounds down
    int x[100],y[100];
    for (int i = 0; i <= m; i++){
        x[i] = a[i];
    }
    for (int i = m+1; i <= e; i++){
        y[i] = a[i];
    }

    mergeSort(x,  s,  m);
    mergeSort(y,  m+1,  e);
    mergeArrays(x,y,a,s,e);

    return;

};

int main(){
    /*
    vector<int> vec;
    int size;
    cout << "input size of the vector" << endl;
    cin >> size; 

    for (int i = 0; i <= size; i++ ){
        int input ;
        cin >> input ;
        vec.push_back(input);
    }; 

    for (int i = 0; i <= vec.size(); i++ ){
        cout << vec[i] << endl;
    }; 
    

    cout << "Enter length of arrays, followed by values of array 2" << endl;
    int n;
    cin >> n; 
    int x[n];
  
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    cout << "Enter values of array 2" << endl;
    int y[n];
  
    for(int i = 0; i < n; i++){
        cin >> y[i];
    }
    int a[100];
    */

    int x[] = {2,2,1,5,4,9,4,5,3,2};
    //int y[5] = {9,4,5,3,2};
    //int a[10];

    mergeSort(x, 0, 9);
    for (int i = 0; i <= 9; i++){
        cout << x[i]<< " ";
    }

    return 0;
};
#include <iostream>

using namespace std;

int partition(int a[], int s, int e){
    int i = s;
    for (int j = s; j <= e-1 ; j++){
       if (a[j]<a[e]){
           swap(a[j], a[i]);
           i++;
       }
    }
    swap(a[i], a[e]);
    return i;
}

void quickSort(int a[], int s, int e){
    if (s>=e){
        return;
    }
    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
    return;

}

int main(){
    int a[] = {8,5,2,1,7,4,4};
    for (int i = 0; i <= 6; i++){
        cout << a[i]<< " ";
    }
    cout << endl;
    quickSort(a, 0, 6);
    for (int i = 0; i <= 6; i++){
        cout << a[i]<< " ";
    }
    cout << endl;

    return 0;
}
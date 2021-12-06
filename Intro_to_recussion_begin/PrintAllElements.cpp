#include <iostream>
#include <string>

using namespace std;

void PrintAllElements(int a[], int n){
    // base case
    
    if (n == 0){return;}

    cout << a[0] << " ";

    return PrintAllElements(a+1, n-1);
}

int main(){

    int c[] = {1,1,3,4,5};
    PrintAllElements(c, 5);

}

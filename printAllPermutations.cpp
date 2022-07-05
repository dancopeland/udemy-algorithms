#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int length(char input[]){
    if (input[0] == '\0'){
        return 0;
    }
    return 1 + length(input + 1);
};


void printPermutation(char str[], int index){
    if (str[index] == '\0'){
        cout << str << endl;
        return;
    }
    for (int i = index; str[i]!='\0'; i++){
        swap(str[i],str[index]);
        printPermutation(str, index + 1);
        swap(str[i],str[index]);
    }
    return;
};

int main(){
    char a[100] = "abc";

    printPermutation(a,0);


};
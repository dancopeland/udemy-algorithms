#include <iostream>
#include <vector>
#include <string>

using namespace std;

int length(char input[]){
    if (input[0] == '\0'){
        return 0;
    }
    return 1 + length(input + 1);
}

int convertStringtoInt(char input[], int len){
    if (len==0){
        return 0;
    }; 
    
    int smallans = convertStringtoInt(input, len - 1); 
    int lastDigit = input[len-1] - '0';  

    return smallans * 10 + lastDigit; 

}; 

int main(){

    cout << "Input a string of numbers" << endl;
    char n[100];
    cin >> n;
    int len = length(n);
    int output = convertStringtoInt(n, len) ;
    cout << output  ;
    cout << output * 2 ;
    

    return 0;
};
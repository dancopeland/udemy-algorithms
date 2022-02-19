#include <iostream>
#include <string>


// All combinations char arry len - n, then 2^n options
using namespace std;

void PrintSubseqString(string input, string output){
    if (input.length() == 0){
        cout << output << endl;
        return;}
    /// include recursion
    PrintSubseqString(input.substr(1), output + input[0]);
    /// exclude recursion
    PrintSubseqString(input.substr(1), output);
    
    
};

void PrintSubseqString2(char input[], char output[], int index){
    if (input[0] == '\0'){
        output[index] = '\0';
        cout << output << endl;
        return;}

    /// exclude recursion
    PrintSubseqString2(input + 1, output, index);
    /// include recursion
    output[index] = input[0];
    PrintSubseqString2(input + 1, output, index + 1);


};


int main(){

    string a;
    string o;
    cin >> a;

    char cha[100];
    char out[100];
    cin >> cha;

    PrintSubseqString(a, o);
    PrintSubseqString2(cha, out, 0);

    return 0;
};
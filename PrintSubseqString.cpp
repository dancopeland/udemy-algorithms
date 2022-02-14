#include <iostream>
#include <string>


// char arry len - n, then 2^n options
using namespace std;

void PrintSubseqString(string input, string output){
    if (input.length() == '\0'){
        cout << output << endl;
        return;}

    /// include recursion
    PrintSubseqString(input.substr(1), output + input[0]);
    /// exclude recursion
    PrintSubseqString(input.substr(1), output);
};

void PrintSubseqString2(char input[], char output[], int index){
    if (input[index] == '\0'){
        output[index] = '\0';
        cout << output << endl;
        return;}


    /// include recursion
    output[index] = input[0];
    PrintSubseqString2(input + 1, output, index + 1);
    /// exclude recursion
    PrintSubseqString2(input + 1, output, index);


};


int main(){
    /*
    string a;
    string o;
    cin >> a;
    PrintSubseqString(a, o);
    */
    char a[100];
    char o[100];
    cin >> a;
    PrintSubseqString2(a, o, 0);

    return 0;
}
#include <iostream>
#include <string>
#include <vector>


// All combinations char arry len - n, then 2^n options
using namespace std;

void PrintSubseqString(string input, string output, vector<string> &v){
    if (input.length() == 0){
        v.push_back(output);
        return;}
    /// include recursion
    PrintSubseqString(input.substr(1), output + input[0], v);
    /// exclude recursion
    PrintSubseqString(input.substr(1), output, v);

};

void PrintSubseqString2(char input[], char output[], int index, vector<string> &v){
    if (input[0] == '\0'){
        v.push_back(output);
        return;}

    /// exclude recursion
    PrintSubseqString2(input + 1, output, index, v);
    /// include recursion
    output[index] = input[0];
    PrintSubseqString2(input + 1, output, index + 1, v);
};


int main(){

    string a;
    string o;
    cin >> a;
    vector<string> v;


    char cha[100];
    char out[100];
    vector<string> vec;
    cin >> cha;

    PrintSubseqString(a, o, v);
    PrintSubseqString2(cha, out, 0, vec);

    for(int i = 0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    for(int i = 0; i<vec.size(); i++){
        cout << vec[i] << endl;
    }

    return 0;
};
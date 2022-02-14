#include <iostream>


using namespace std;


void RemoveConsecDuplicates(char input[]){
    if (input[0] == '\0'){return;}

    else if (input[0] != input[1]){
        RemoveConsecDuplicates(input + 1 );
    }
    
    else{
        for (int i = 0; input[i] != '\0'; i++){
            input[i] = input[i+1];
            
        }
    RemoveConsecDuplicates(input);
    }
};


int main(){
    char a[100];
    cin >> a;
    char f;
    RemoveConsecDuplicates(a);

    cout << a << endl; 

    return 0;
}
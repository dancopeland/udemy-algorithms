#include <iostream>
#include <vector>

using namespace std;

void AllPostitons(int a[], int n, int x,  int index, vector<int> answer){
    // base case
    
    if (n == 0){return;}

    if (a[0] == x){
        //answer.push_back(index);
        cout << index << " " << endl;
    }

    return AllPostitons(a+1, n-1, x, index+1, answer);
}

int main(){
    cout << "Enter a number to be searched for in a prebuilt array: ";
    int x;
    cin >> x;
    int c[] = {1,1,3,4,5};
    vector<int> answer;
    AllPostitons(c, 5, x, 0, answer);
    /*

    for (int i = 0; i < answer.size(); i++){
        cout << answer.at(i) << " ";
    } // v.push_back()
    */

}

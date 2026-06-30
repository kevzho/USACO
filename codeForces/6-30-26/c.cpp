#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        string s;
        cin >> n >> s;

        int transitions = 0;
        for (int i = 1; i < n; i++){
            if (s[i] != s[i - 1]){
                transitions++;
            }
        }
        if (transitions == 1){
            cout << "2" << endl;
        }
        else{
            cout << "1" << endl;
        }
    }
    return 0;
}
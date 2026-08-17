/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int L = 1;
        for (int i = 1; i < n; i++){
            if (s[i] != s[i - 1]) L++;
        }
        
        int best_reduc = 0;
        for (int i = 1; i + 1 < n; i++){
            if (s[i] != s[i - 1] && s[i] != s[i + 1]){
                if (s[i - 1] == s[i + 1]) { best_reduc = 2; break; }
                best_reduc = 1;
            }
        }
        cout << L - best_reduc << endl;
    }
    return 0;
}
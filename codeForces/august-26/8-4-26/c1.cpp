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
        string a, b;
        cin >> n >> a >> b;
        
        int ca[2] = {0, 0}, cb[2] = {0, 0};
        for (int i = 0; i < n; i++){
            if (a[i] == '1') ca[i % 2]++;
            if (b[i] == '1') cb[i % 2]++;
        }
        
        cout << (ca[0] == cb[0] && ca[1] == cb[1] ? "YES" : "NO") << endl;
    }
    return 0;
}
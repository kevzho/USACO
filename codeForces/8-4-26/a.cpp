/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        int v[3];
        cin >> v[0] >> v[1] >> v[2];
        int rounds = 0;
        while (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]) {
            int mx = 0, mn = 0;
            for (int i = 1; i < 3; i++) {
                if (v[i] > v[mx]) mx = i;
                if (v[i] < v[mn]) mn = i;
            }
            v[mx]--;
            v[mn]++;
            rounds++;
        }
        cout << rounds << endl;
    }
    return 0;
}
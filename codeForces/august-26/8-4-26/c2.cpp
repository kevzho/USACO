/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

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
        
        vector<int> pa[2], pb[2];
        for (int i = 0; i < n; i++){
            if (a[i] == '1') pa[i % 2].push_back(i);
            if (b[i] == '1') pb[i % 2].push_back(i);
        }
        if (pa[0].size() != pb[0].size() || pa[1].size() != pb[1].size()){
            cout << -1 << endl;
            continue;
        }
        long long operations = 0;
        for (int p = 0; p < 2; p++){
            for (size_t k =0; k < pa[p].size(); k++){
                operations += abs(pa[p][k] - pb[p][k]) / 2;
            }
        }
        cout << operations << endl;
    }
    return 0;
}
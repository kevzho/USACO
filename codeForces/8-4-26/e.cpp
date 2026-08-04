/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> b(n);
        
        long long total = 0;
        for (auto &x: b){
            cin >> x;
            total += x;
        }
        
        if (total < 1){
            cout << -1 << endl;
            continue;
        }
        
        multiset<ll> rem(b.begin(), b.end());
        ll P = 0;
        for (int i= 0; i < n; i++){
            auto it = rem.lower_bound(1 -P);
            P += *it;
            rem.erase(it);
            cout << P << " \n"[i == n - 1];
        }
    }
    return 0;
}
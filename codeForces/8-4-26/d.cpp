/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> b(n);
        for (auto &x : b) cin >> x;
        
        map<ll, ll> cnt;
        for (ll x: b) cnt[x]++;
        
        vector<ll> v, c;
        for (auto &[val, ct] : cnt) {v.push_back(val); c.push_back(ct);}
        int k = v.size();
        
        bool ok = (v[0] == 0);
        map<ll, ll> value;
        ll prev = 0;
        for (int g = 0; g < k && ok; g++){
            ll x;
            if (g + 1 < k){
                ll diff = v[g + 1] - v[g];
                if (diff % c[g] != 0) { ok = false; break;}
                x = diff / c[g];
            }else{
                x = prev + 1;
            }
            if (x <= prev) {ok = false; break;}
            value[v[g]] = x;
            prev = x;
        }
        
        if (!ok) { cout << -1 << endl; continue; }
        for (int i = 0; i < n; i++){
            cout << value[b[i]] << " \n"[i == n - 1];
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll S;
        int q;
        cin >> S >> q;
        
        vector<ll> d{0};
        
        for (ll i = 1; i * i <= S; i++){
            if (S % i == 0) {
                d.push_back(i);
                if (i != S / i){
                    d.push_back(S / i);
                }
            }
        }
        sort(d.begin(), d.end());
        
        vector<ll> P(d.size());
        for (size_t k = 1; k < d.size(); k++){
            P[k] = P[k - 1] + (d[k] - d[k - 1]) * (S / d[k]);
        }
        
        auto blk = [&](ll z){
            return lower_bound(d.begin() + 1, d.end(), z) - d.begin();
        };
        
        auto U = [&](ll z) -> ll{
            if (z <= 0) return 0;
            auto k = blk(z);
            return P[k - 1] + (z - d[k - 1]) * (S / d[k]);
        };
        
        while (q--){
            ll x, y;
            cin >> x >> y;
            ll c = min(x, d[blk((S + y - 1) / y) - 1]);
            cout << y * c + U(x) - U(c) << '\n';
        }
    }
    return 0;
}
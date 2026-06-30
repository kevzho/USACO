#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// fenwick tree
struct BIT{
    int n;
    vector<long long> bit;
    BIT(int n): n(n), bit(n + 1, 0) {}
    void add(int idx, long long val){
        for (idx++; idx <= n; idx += idx & -idx){
            bit[idx] += val;
        }
    }
    long long sum(int idx){
        long long r = 0;
        for (idx++; idx > 0; idx -= idx & -idx){
            r += bit[idx];
        }
        return r;
    }
};


int main(){
    int t;
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }

        vector<int> sa = a;
        sort(sa.begin(), sa.end());
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (sa[i] > b[i]) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            cout << -1 << endl;
            continue;
        }

        vector<bool> used(n, false);
        vector<int> pos(n);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (!used[j] && b[j] >= a[i]){
                    pos[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
        
        long long ans = 0;
        BIT ft(n);
        for (int i = n - 1; i >= 0; --i){
            int x = pos[i];
            ans += ft.sum(x-  1);
            ft.add(x , 1);
        }
        cout << ans << endl;
    }
    return 0;
}
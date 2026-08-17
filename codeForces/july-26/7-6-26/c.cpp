#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &x: a) cin >> x;

        vector<int> L;
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            L.push_back(j - i);
            i = j;
        }

        sort(L.begin(), L.end());

        long long s = 0;
        for (int x: L) s+= x;

        int c = L.size();
        int ans = 0;
        int idx = 0;

        while (idx < (int)L.size()){
            int tau = L[idx];
            int m = 1 - tau;

            if ((k - s) % c == 0){
                long long F = (k - s) / c;
                if (F >= m) ans++;
            }

            int cur = L[idx];
            while (idx < (int)L.size() && L[idx] == cur){
                s -= L[idx];
                c--;
                idx++;
            }
        }

        cout << ans << endl;
    }
}
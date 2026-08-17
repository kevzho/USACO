#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<long long> X(n), Y(n);
        for (int i = 0; i < n; i++){
            int x = (a[i] == 1) ? 1 : -1;
            int y = (a[i] == 3) ? -1 : 1;
            X[i] = x + (i > 0 ? X[i-1] : 0);
            Y[i] = y + (i > 0 ? Y[i-1] : 0);
        }

        vector<long long> suffixMaxY(n, LLONG_MIN);
        if (n >= 2) suffixMaxY[n-2] = Y[n-2];
        for (int i = n - 3; i >= 0; i--){
            suffixMaxY[i] = max(Y[i], suffixMaxY[i+1]);
        }

        bool ok = false;
        for (int i = 0; i <= n - 3; i++){
            if (X[i] >= 0 && suffixMaxY[i+1] >= Y[i]){
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
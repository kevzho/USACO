#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        long long a1 = 0;
        long long b1 = 0;
        long long x;
        
        for (int i = 0; i < n; i++){
            cin >> x; 
            if (i == 0) a1 = x;
        }
        
        for (int i = 0; i< m; i++){
            cin >> x;
            if (i==0) b1 = x;
        }
        
        cout << (a1 + n >= b1 + m ? 1 : 2) << '\n';
    }
    return 0;
}
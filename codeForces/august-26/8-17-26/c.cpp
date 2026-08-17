#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        
        for (int i = 2; i <= n; i++) cin >> x;
        
        int m;
        cin >> m;
        vector<int> a(m);
        for (int &v: a) cin >> v;
        
        int mn = *min_element(a.begin(), a.end());
        cout << m - 1;
        for (int v: a) if (v!= mn) cout << ' ' << v;
        cout << '\n';
    }
    return 0;
}
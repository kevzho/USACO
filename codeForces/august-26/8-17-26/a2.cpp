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

        bool have[26] = {};
        for (int i = 0; i < n; i++) {
            string w;
            cin >> w;
            have[w[0] - 'a'] = true;
        }

        bool ok = true;
        for (int i = 0; i < m; i++) {
            string a;
            cin >> a;
            for (char c : a)
                if (!have[c - 'A']) ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
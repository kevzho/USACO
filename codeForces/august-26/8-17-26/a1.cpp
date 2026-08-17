/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        
        vector<bool> have(26, false);
        for (int i = 0; i < n; i++){
            string w;
            cin >> w;
            have[toupper(w[0]) - 'A'] = true;
        }
        
        vector<string> a(m);
        for (int i = 0 ; i < m; i++) cin >> a[i];
        
        vector<bool> done(m, false);
        int count = 0;
        bool progress = true;
        while(progress){
            progress = false;
            for (int i = 0; i < m; i++){
                if (done[i]) continue;
                bool ok = true;
                for (char c: a[i]){
                    if (!have[c - 'A']) {ok = false; break;}
                }
                if (ok){
                    done[i] = true;
                    count++;
                    have[a[i][0] - 'A'] = true;
                    progress = true;
                }
            }
        }
        
        cout << (count == m ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
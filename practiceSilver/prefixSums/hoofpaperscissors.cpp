// https://usaco.org/index.php?page=viewproblem2&cpid=691

#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    int n;
    cin >> n;

    vector<char> fj(n);
    for (int i = 0; i < n; i++){
        cin >> fj[i];
    }

    vector<int> h(n);
    vector<int> p(n);
    vector<int> s(n);

    if (fj[0] == 'H'){
        p[0] = 1;
        h[0] = 0;
        s[0] = 0;
    }
    else if (fj[0] == 'P'){
        s[0] = 1;
        h[0] = 0;
        p[0] = 0;
    }
    else{
        h[0] = 1;
        p[0] = 0;
        s[0] = 0;
    }

    for (int i = 1; i < n; i++){
        
        h[i] = h[i - 1];
        p[i] = p[i - 1];
        s[i] = s[i - 1];

        if (fj[i] == 'H'){
            p[i]++;
        }
        else if (fj[i] == 'P'){
            s[i]++;
        }
        else{
            h[i]++;
        }
    }

    int max_wins = max({h[n - 1], p[n - 1], s[n - 1]});

    for (int i = 0; i < n; i++){
        int wins = 0;
        wins += max({h[i], p[i], s[i]});
        wins += max({h[n - 1] - h[i], p[n - 1] - p[i], s[n - 1] - s[i]});
        max_wins = max(wins, max_wins);
    }

    cout << max_wins << endl;
    return 0;
}
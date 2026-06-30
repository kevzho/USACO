#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool good(long long n){
    bool seen[10] = {};
    int cnt = 0;
    while (n > 0){
        int d = n % 10;
        if (!seen[d]){
            seen[d] = true;
            cnt++;
        }
        n /= 10;
    }
    return cnt <= 2;
}

int main(){
    vector<long long> ys;

    for (int y = 2; y <= 99; y++) {
        if (good(y)) ys.push_back(y);
    }

    long long p = 1;
    long long rep = 0;

    for (int k = 1; k <= 9; k++) {
        p *= 10;
        rep = rep * 10 + 1;

        ys.push_back(p);
        ys.push_back(p - 1);
        ys.push_back(p + 1);
        if (rep >= 2) ys.push_back(rep);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int t;
    cin >> t;

    while(t--){
        long long x;
        cin >> x;

        for (long long y: ys){
            if (good(x * y)){
                cout << y << "\n";
                break;
            }
        }
    }
}
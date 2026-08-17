#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        if (n == 2){
            cout << -1 << endl;
            continue;
        }

        vector<long long> a(n);
        a[0] = 1;
        a[1] = 2;
        
        // we can just take the sum of the previous numbers, and then add 
        // it as a new number.

        for (int i = 2; i < n; i++){
            a[i] = 3LL << (i - 2);
        }
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
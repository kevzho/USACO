#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector<long long> a(n), b(n), need(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++){
            need[i] = b[i] - a[i];
            if (i % 2 == 1) need[i] *= -1;
        }

        long long pos = 0, neg = 0;
        bool good = true;

        for (int i = 0 ; i < n; i++){
            if (i % 2 == 0){
                long long requiredNeg = max(0LL, -need[i]);

                if (neg < requiredNeg){
                    good = false;
                    break;
                }

                pos = neg + need[i];
            }
            else{
                long long requiredPos = max(0LL, need[i]);

                if (pos < requiredPos){
                    good = false;
                    break;
                }

                neg = pos - need[i];
            }
        }
        
        cout << (good ? "YES" : "NO") << endl;
    }
    return 0;
}
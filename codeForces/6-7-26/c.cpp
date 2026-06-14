#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector <long long> h(n);

        for (int i= 0; i < n; i++){
            cin >> h[i];
        }

        for (int empty = 0; empty < n; empty++){
            long long total = 0;

            for (int v = 0; v < n; v++){
                if(v == empty){
                    continue;
                }

                long long best = 0;

                long long current = static_cast<long long>(1e18);

                int x = v;
                while (x != empty) {
                    int edge = (x - 1 + n) % n;
                    current = min(current, h[edge]);
                    x = (x - 1 + n) % n;
                }

                best = max(best, current);

                current = static_cast<long long>(1e18);

                x = v;
                while (x != empty) {
                    int edge = x;
                    current = min(current, h[edge]);
                    x = (x + 1) % n;
                }

                best = max(best, current);

                total += best;
            }
            cout << total << " ";
        }
       cout << endl;
    }
    return 0;
}
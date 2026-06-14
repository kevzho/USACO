#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;

    // 10 is not a good number but 22 is (22 % 12 = 10)
    long long mods[12] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11
    };

    while (t--){
        long long n;
        cin >> n;
        long long a = mods[n % 12];

        if (a <= n){
            cout << a << " " << n - a << endl;
        }
        else{
            cout << - 1 << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int l = 0, r = n - 1;
        
        // getting rid of leading zeroes and trailing ones
        while (l < n && s[l] == '0') l++;
        while (r >= l && s[r] == '1') r--;

        bool alice_win = false;
        int i = l;
        while (i <= r){
            int j = i;

            while (j <= r && s[j] == s[i]){
                j++;
            }

            int len = j - i;

            // odd inflections -> alice wins
            if (len % 2 == 1){
                alice_win = true;
                break;
            }

            i = j;
        }

        cout << (alice_win ? "Alice" : "Bob") << endl;
    }
    return 0;
}
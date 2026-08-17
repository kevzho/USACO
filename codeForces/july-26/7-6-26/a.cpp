#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--){
        int k;
        cin >> k;
        vector<long long> c(k);
        long long n = 0;
        for (int i = 0; i < k; i++){
            cin >> c[i];
            n += c[i];
        }

        if (n <= 2){
            cout << "NO" << endl;
            continue;
        }

        bool has3 = false;
        int cnt2 = 0;
        for (int i = 0; i < k; i++){
            if (c[i] >= 3){
                has3 = true;
            }
            else if (c[i] == 2){
                cnt2++;
            }
        }

        if (has3 || cnt2 >= 2){
            cout << "YES" << endl;
            continue;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
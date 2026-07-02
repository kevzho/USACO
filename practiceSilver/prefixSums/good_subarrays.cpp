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
        int n;
        string s;
        cin >> n;
        cin >> s;
        
        int pref_sum = 0;

        unordered_map<int, int> pref_count;
        pref_count[0] = 1;

        long long good_subarrays = 0;
        
        for (int i = 0; i < n; i++){
            pref_sum += (s[i] - '0') - 1; // calculates prefix sum
            good_subarrays += pref_count[pref_sum]; // adds specific prefix sum to hashmap
            // the above looks at how many earlier prefix sums equal the current prefix sum
            // before we add the current one to the map. 

            pref_count[pref_sum]++; // adds specific prefix sum to hashmap
        }

        cout << good_subarrays << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--){
        // go through each testcase
        int a;
        cin >> a;

        vector<int> arr(a);
        for (int i = 0; i < a; i++){
            cin >> arr[i];
        }

        int sum = accumulate(arr.begin(), arr.end(), 0);
        int idx = 0;
        for (int i = 0; i < a; i++){
            if (arr[idx] < arr[i]){
                sum -= arr[i] - arr[idx];
                arr[i] = arr[idx]; // cut down
                idx = i;
            }
            else{
                idx = i;
            }
        }
        cout << sum << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int max_sum = float('-inf');
    int curr = 0;

    for (int i = 0; i < n; i++){
        curr += a[i];
        max_sum = max(max_sum, curr);
        if (curr < 0){
            curr = 0;
        }
    }
    cout << max_sum << endl;
    return 0;
}
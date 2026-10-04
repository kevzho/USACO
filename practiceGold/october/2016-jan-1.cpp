/* 
Problem: https://usaco.org/index.php?page=viewproblem2&cpid=597
Time: 1hr

Compile: clang++ -std=c++20 2016-jan-1.cpp -o 2016-jan-1
Run: ./2016-jan-1
*/

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= 2; // multiply by 2 to avoid dealing with fractions
    }

    sort(a.begin(), a.end());

    vector<long long> dp(n, 0); // initialize dp array for min radius
    for (int i = 1; i < n; i++){
        dp[i] = max(dp[i-1], a[i] - a[i-1]); // calculate the max distance between adjacent cows
        cout << dp[i] << "\n";
    }

    return 0;
}
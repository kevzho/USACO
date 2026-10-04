/* 
Problem: https://codeforces.com/contest/1201/problem/C 
Time: 1hr

Compile: clang++ -std=c++20 oct-4.cpp -o oct-4
Run: ./oct-4
*/

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;


// guessing the median
long long last_true(long long low, long long high, function<bool(long long)> check){
    low--;
    while (low < high){
        long long mid = low + (high - low + 1) / 2;
        if (check(mid)){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
	return low; // returns the last true value
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l = 0, r = a[n-1];

    cout << last_true(1, 2e9, [&](long long x) {
		long long ops_needed = 0;
		for (long long i = (n - 1) / 2; i < n; i++) {
			ops_needed += max(0LL, x - a[i]);
		}
		return ops_needed <= k;
	}) << endl;
}
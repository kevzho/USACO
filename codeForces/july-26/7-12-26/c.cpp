#include <iostream>
#include <vector>

using namespace std;

constexpr long long MOD = 1'000'000'007LL;

long long mod_pow(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) result = result * base % MOD;
        base = base * base % MOD;
        exponent >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (long long &x : a) cin >> x;

        int negative_count = 0;
        while (negative_count < n && a[negative_count] == -1) {
            ++negative_count;
        }

        int positive_groups = 0;
        int consecutive_group_pairs = 0;
        long long previous_value = -1;
        for (int i = negative_count; i < n;) {
            long long value = a[i];
            ++positive_groups;
            if (previous_value != -1 && value == previous_value + 1) {
                ++consecutive_group_pairs;
            }
            previous_value = value;
            while (i < n && a[i] == value) ++i;
        }

        const int positive_count = n - negative_count;

        const int all_groups = positive_groups + (negative_count > 0);
        long long answer = mod_pow(2, n - all_groups);

        if (negative_count > 0) {
            long long positive_choices = mod_pow(2, positive_count - positive_groups);
            long long negative_odd_choices = mod_pow(2, negative_count - 1);
            long long odd_length_ways = negative_odd_choices * positive_choices % MOD;
            odd_length_ways = odd_length_ways * consecutive_group_pairs % MOD;
            answer = (answer + odd_length_ways) % MOD;
        }

        cout << answer << '\n';
    }
}

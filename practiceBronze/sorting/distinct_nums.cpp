//Distinct Numbers (CSES Problem Set)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int count = 1; // Start with 1 to count the first unique element
    for (int i = 0; i < n - 1; i++){
        if (arr[i] != arr[i + 1]) {
            count++;
        }
    }
    cout << count;
    return 0;
}
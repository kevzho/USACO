//Kayaking (CodeForces)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n * 2);
    for (int i = 0; i < n * 2; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int count = 0; // Start with 1 to count the first unique element

    arr.pop_back();
    arr.pop_back();

    for (int i = 0; i < n; i+=2){
        count += arr[i+1] - arr[i];
    }
    cout << count;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int x, y;
        cin >> x >> y;
        
        cout << (x % y == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int tip;
    long long ans = 0;
    cin >> n;

    vector<int> arr;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<>());

    for (int i = 0; i < n; i++) {
        tip = arr[i] - i;
        if (tip < 0) tip = 0;
        ans += tip;
    }

    cout << ans;

    return 0;
}
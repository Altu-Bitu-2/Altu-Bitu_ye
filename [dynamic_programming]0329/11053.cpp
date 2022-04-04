#include <iostream>
#include <vector>

using namespace std;

int LIS(int n, vector<int> &a) {
    vector<int> dp(n, 0);

    if (n == 1) {
        return 1;
    }

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {    //이전 인덱스의 수보다 크면
                tmp = max(tmp, dp[j]);
            }
        }
        dp[i] = tmp + 1;
    }

    //가장 긴 증가하는 수열이 항상 수열의 마지막 원소와 이어져있는 것은 아님
    int dp_max;
    for (int i = 0; i < n; i++) {
        dp_max = max(dp_max, dp[i]);
    }
    return dp_max;
}

int main() {

    int n;  //수열 A의 크기
    cin >> n;

    vector<int> a(n, 0);  //수열 A

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << LIS(n, a);
    return 0;
}
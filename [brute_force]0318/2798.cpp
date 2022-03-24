#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, m, ans = 0;
    vector<int> v;
    cin >> n >> m;
    v.assign(n, 0);

    // 카드에 쓰여 있는 수 입력
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = v[i] + v[j] + v[k];   // 3장의 카드 합
                if (sum <= m && sum > ans) ans = sum;   // 합이 M을 넘지 않으면서 최댓값
            }
        }
    }

    cout << ans;

    return 0;
}
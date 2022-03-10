#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;  // 사람 수
    int tip;    // 팁
    long long ans = 0;  //오버플로우 방지를 위해 long long으로 저장
    cin >> n;

    vector<int> arr;    //주려고 하는 돈 저장
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //내림차순 정렬
    sort(arr.begin(), arr.end(), greater<>());

    for (int i = 0; i < n; i++) {
        tip = arr[i] - i;   //팁 = 주려고 했던 돈 - (받은 등수 - 1)
        if (tip < 0){   //팁이 음수일 때 팁을 주지 않음
            tip = 0;
            break;      //내림차순이므로 앞 사람의 팁이 음수랄면 다음 사람의 팁도 음수
        }
        ans += tip;
    }

    cout << ans;

    return 0;
}
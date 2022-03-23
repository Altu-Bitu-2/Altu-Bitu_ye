#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add(string &A, string &B) {

    vector<int> a, b;

    // 각 자리 숫자 저장
    for (int i = 0; i < A.length(); i++) {
        a.push_back(A[i] - '0');
    }
    // 자릿수가 없는 부분은 0으로 저장
    for (int i = 0; i < A.length() - B.length(); i++) {
        b.push_back(0);
    }
    for (int i = 0; i < B.length(); i++) {
        b.push_back(B[i] - '0');
    }

    vector<int> sum;
    sum.assign(a.size(), 0);

    for (int i = a.size() - 1; i >= 0; i--) {
        sum[i] += a[i] + b[i];
        //10을 넘으면 다음 자릿수 + 1
        if (sum[i] >= 10) {
            if (i == 0) continue;
            sum[i] -= 10;
            sum[i - 1]++;
        }
    }

    // 출력
    for (int i = 0; i < sum.size(); i++) {
        cout << sum[i];
    }
}

int main() {

    string A, B;
    cin >> A >> B;

    // 자릿수가 더 큰 수가 첫번째 인자로
    if (A.length() > B.length()) add(A, B);
    else add(B, A);

    return 0;
}
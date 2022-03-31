#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;  //N개의 수 저장
vector<int> num;    //수열
vector<bool> check;

void backtracking(int cnt) {    //cnt: 수열 인덱스
    if (cnt == m) { //m개 수 고름 (기저 조건)
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int before = 0; //바로 직전에 선택한 수. 중복 방지
    for (int i = 0; i < n; i++) {
        if (!check[i] && before != v[i]) {
            num[cnt] = v[i];
            before = v[i];
            check[i] = true;
            backtracking(cnt + 1);
            check[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;
    v.assign(n, 0);
    check.assign(n, false);
    num.assign(m, 0);

    //N개의 수 입력
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());   //정렬
    backtracking(0);
    return 0;
}
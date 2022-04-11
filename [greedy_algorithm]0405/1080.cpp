#include <iostream>
#include <vector>

using namespace std;

//행렬을 변환하는 연산
void flip(vector<vector<char>> &a, int row, int col) {
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (a[i][j] == '1') a[i][j] = '0';
            else a[i][j] = '1';
        }
    }
}

int func(vector<vector<char>> &a, vector<vector<char>> &b, int n, int m) {

    int ans = 0;

    //두 행렬의 문자가 다를 경우 바로 바꿔줌
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                flip(a, i, j);
                ans++;
            }
        }
    }

    //연산이 끝난 후에 행렬 A와 B가 다르면 바꿀 수 없음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j])
                return -1;
        }
    }

    return ans;
}

int main() {

    int n, m;
    cin >> n >> m;

    //공백 구분이 없으므로 char형으로 입력 받음
    vector<vector<char>> a(n, vector<char>(m, '0'));
    vector<vector<char>> b(n, vector<char>(m, '0'));

    //행렬 A와 B의 원소 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    //출력
    cout << func(a, b, n, m);

    return 0;
}
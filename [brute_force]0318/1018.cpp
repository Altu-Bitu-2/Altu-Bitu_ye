#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> board;

// 맨 왼쪽 위 칸이 흰색인 경우의 체스판과 비교
int wCnt(int x, int y) {
    vector<vector<char>> w;
    w.assign(8, vector<char>(8, ' '));

    // 맨 왼쪽 위 칸이 흰색인 경우의 체스판
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j += 2) {
            if (i % 2 == 0) {
                w[i][j] = 'W';
                w[i][j + 1] = 'B';
            } else {
                w[i][j] = 'B';
                w[i][j + 1] = 'W';
            }
        }
    }

    int cnt = 0;    // 다시 칠해야 하는 정사각형 개수

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (board[i][j] != w[i - x][j - y]) cnt++;
        }
    }

    return cnt;
}

// 맨 왼쪽 위 칸이 검은색인 경우의 체스판과 비교
int bCnt(int x, int y) {
    vector<vector<char>> b;
    b.assign(8, vector<char>(8, ' '));

    // 맨 왼쪽 위 칸이 검은색인 경우의 체스판
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j += 2) {
            if (i % 2 == 0) {
                b[i][j] = 'B';
                b[i][j + 1] = 'W';
            } else {
                b[i][j] = 'W';
                b[i][j + 1] = 'B';
            }
        }
    }

    int cnt = 0;    // 다시 칠해야 하는 정사각형 개수

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (board[i][j] != b[i - x][j - y]) cnt++;
        }
    }

    return cnt;
}

int main() {
    int n, m;
    int result = 64;  // 최댓값 = 8 * 8

    cin >> n >> m;
    board.assign(n, vector<char>(m, ' '));

    // 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 두 가지 경우의 체스판과 비교
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            result = min(result, min(wCnt(i, j), bCnt(i, j)));
        }
    }

    cout << result;

    return 0;

}
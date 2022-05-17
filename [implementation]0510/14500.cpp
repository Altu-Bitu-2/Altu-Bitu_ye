#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000;

int ans, n, m;  //테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값, 종이 가로, 세로
vector<vector<int>> board;  //종이에 쓰여 있는 수

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum);    //최댓값 저장
        return;
    }

    if (ans >= MAX * (4 - cnt) + sum) { //현재 탐색이 남은 칸을 모두 MAX라 해도 ans이 더 큰 경우 탐색할 필요 없음
        return;
    }

    for (int i = 0; i < 4; i++) {
        //다음 좌표
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) { //범위를 벗어나거나, 이미 방문했다면
            continue;
        }

        if (cnt == 2) { //보라색 블럭의 경우
            int save = board[nr][nc];   //현재 좌표 저장
            board[nr][nc] = 0;  //방문 처리
            backtracking(row, col, cnt + 1, sum + save);    //직전 좌표에서 다시 한 번 백트래킹
            board[nr][nc] = save;   //원래 상태로 돌려놓음
        }
        int save = board[nr][nc];   //원래 상태로 돌려놓기 위해 저장해 둠
        board[nr][nc] = 0;  //방문 처리
        backtracking(nr, nc, cnt + 1, sum + save);
        board[nr][nc] = save;   //원래 상태로 돌려놓음
    }
}

/**
 * [테트로미노]
 *
 * 1. 보라색 블럭을 제외하고는 모두 한붓 그리기로 그릴 수 있음
 *    -> 일반적인 백트래킹으로 모양을 만들 수 있음
 * 2. 보라색 블럭은 3개의 블럭이 결정된 이후에, 가운데에서 탐색을 해야 만들 수 있음
 *    -> 3번째 블럭을 결정하면서 현재 좌표를 갱신하지 않고, 직전 좌표에서 다시 한번 백트래킹을 진행하여 얻을 수 있음
 * 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신
 *
 * 방문처리 -> board를 활용해서 0을 저장하는 것으로
 * 가지치기 -> 현재 탐색이 남은 칸을 모두 MAX라 해도 ans이 더 큰 경우
 */

int main() {
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int save = board[i][j]; //원래 상태로 돌려놓기 위해 저장해 둠
            board[i][j] = 0;    //방문 처리
            backtracking(i, j, 1, save); //모양 처리
            board[i][j] = save; //원래 상태로 돌려놓음
        }
    }

    //출력
    cout << ans;
    return 0;
}
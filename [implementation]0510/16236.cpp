#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int min_dist = INF; //최단 거리를 최댓값으로 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1;    //현재 위치 방문 표기
    q.push(shark);  //상어 시작점 큐에 삽입
    while (!q.empty()) {    //큐가 빌 때까지
        //현재 위치 삽입
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue;
        }
        for (int i = 0; i < 4; i++) {
            //새로운 위치
            int nr = row + dr[i];
            int nc = col + dc[i];
            //새로운 좌표가 범위 안에 없음. 이미 방문한 곳. 아기 상어의 크기보다 큰 물고기가 있는 칸.
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {
                continue;
            }

            dist[nr][nc] = dist[row][col] + 1;  //한 칸 이동했으므로 거리 1 증가
            //빈 칸이 아님. 물고기의 크기가 아기 상어의 크기보다 작음
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc);  //먹을 수 있는 물고기 위치 저장
                min_dist = dist[nr][nc];    //물고기를 먹을 수 있는 최단 거리
                continue;
            }
            q.push({nr, nc});   //현재 위치 변경
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}};
    }

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) {
            return p1.first < p2.first; //가장 위에 있는 물고기를 먹음
        }
        return p1.second < p2.second;   //가장 왼쪽에 있는 물고기를 먹음
    });
    return {min_dist - 1, list[0]}; //최단 거리, 우선 순위가 가장 높은 위치 리턴
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0; //물고기를 잡아먹을 수 있는 시간, 아기 상어의 크기, 먹은 물고기 개수
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board);
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        }
        ans += result.first;    //이동한 거리만큼 시간 증가
        cnt++;  //먹은 물고기의 개수 증가
        if (cnt == size) { //상어 크기 증가
            cnt = 0;
            size++;
        }

        //상어 이동
        board[shark.first][shark.second] = 0;   //원래 있던 칸을 빈 칸으로 표시
        shark = result.second;  //상어가 있는 칸을 이동한 칸으로 표시
    }
    return ans; //시간 리턴
}

/**
 * [아기 상어]
 *
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

int main() {
    int n;  //공간의 크기
    pair<int, int> shark_pos;   //아기 상어의 위치

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));   //공간의 상태
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j);
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
    return 0;
}
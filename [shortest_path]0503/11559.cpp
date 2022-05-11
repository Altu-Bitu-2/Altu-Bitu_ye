#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
//행과 열을 바꿔줄 것이므로 ROW를 6으로 설정
const int ROW = 6;
const int COL = 12;

bool bfs(int r, int c, vector<vector<char>> &board) {
    int dr[4] = {-1, 1, 0, 0};  //상, 하
    int dc[4] = {0, 0, -1, 1};  //좌, 우

    queue<ci> q;
    queue<ci> puyo; //포함된 좌표 저장할 큐
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));    //방문 체크

    //시작 초기화
    q.push({r, c}); //큐에 탐색 시작점 삽입
    puyo.push({r, c});  //뿌요 좌표 삽입
    visited[r][c] = true;   //방문 표기
    int cnt = 1; //모여있는 뿌요의 개수
    while (!q.empty()) {    //큐가 빌 때까지
        int cr = q.front().first;   //뿌요의 행 위치
        int cc = q.front().second;  //뿌요의 열 위치
        q.pop();    //탐색한 뿌요 좌표 제거

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];    //상, 하
            int nc = cc + dc[i];    //좌, 우
            //주어진 범위에서 벗어나거나 이미 방문했다면 다음으로 넘어가기
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue;
            }
            if (board[nr][nc] == board[cr][cc]) {   //같은 색의 뿌요가 있음
                q.push({nr, nc});   //다음 탐색할 뿌요 좌표 저장
                puyo.push({nr, nc});    //같은 색의 뿌요가 있는 좌표 저장
                visited[nr][nc] = true; //방문 체크
                cnt++;  //모여 있는 뿌요 개수 증가
            }
        }
    }
    if (cnt < 4) { //뿌요 안터짐
        return false;
    }
    while (!puyo.empty()) {
        int cr = puyo.front().first;    //터진 뿌요의 행 좌표
        int cc = puyo.front().second;   //터진 뿌요의 열 좌표
        puyo.pop(); //큐에서 제거

        board[cr][cc] = '.';    //뿌요가 터졌으므로 빈 칸으로 표시
    }
    return true;    //뿌요 터짐
}

//뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
vector<vector<char>> makeNewBoard(vector<vector<char>> &board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.'));    //새로운 필드 저장
    for (int i = 0; i < ROW; i++) {
        queue<char> temp; //남아있는 뿌요 모으는 큐
        for (int j = 0; j < COL; j++) {
            if (board[i][j] != '.') {   //빈칸이 아닌 필드
                temp.push(board[i][j]); //남아 있는 뿌요 좌표 큐에 삽입
            }
        }
        int index = 0;  //뿌요를 떨어트린 상태로 만들기 위해 열의 0번째 index부터 삽입
        while (!temp.empty()) { //남아 있는 뿌요 없을 때까지
            new_board[i][index++] = temp.front();   //남아있는 뿌요 새로운 위치에 저장
            temp.pop(); //큐에서 제거
        }
    }
    return new_board;   //새로운 필드 리턴
}

int simulation(vector<vector<char>> &board) {
    int answer = 0;
    while (true) {  //flag를 통해 터뜨릴 수 없을 때까지 반복
        bool flag = false; //뿌요가 터졌는지 확인
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == '.') {   //빈 칸이라면 넘어가기
                    continue;
                }
                if (bfs(i, j, board)) { //한 번이라도 뿌요 터졌다면
                    flag = true;
                }
            }
        }
        if (!flag) {    //뿌요가 터지지 않았다면
            break;  //반복문 빠져나옴
        }
        board = makeNewBoard(board);    //뿌요를 터뜨린 후 새 필드 작성
        answer++;   //뿌요가 터졌으므로 연쇄 횟수 증가
    }
    return answer;  //연쇄 횟수 리턴
}

/**
 * [Puyo Puyo] - bfs, 시뮬레이션 문제
 *
 * 1. bfs 탐색을 통해 4개 이상의 뿌요가 모였는지 확인
 * 2. 4개 이상의 뿌요가 모였다면, 해당되는 영역을 '.'으로 바꾸어 비워줌
 * 3. 전체 필드에 대해 1~2를 다 수행한 후, 뿌요를 떨어뜨림
 *    - 바닥부터 시작해서 남아있는 뿌요들을 모으고, 남은 부분은 '.'으로 채우는 방식
 * 4. 터뜨릴 수 없을 때까지 반복
 *
 * 여기서, 3번 과정을 편하게 하기 위해 12*6으로 들어오는 입력을 6*12로 바꾸어준다.
 * 같은 열에 있는 데이터를 다루는 것보다 같은 행에 있는 데이터를 다루는 것이 편하기 때문이다.
 */

int main() {
    //입력
    char input;
    vector<vector<char>> board(ROW, vector<char>(COL)); //필드
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++) {
            cin >> input;
            board[j][COL - i - 1] = input;  //열의 입력을 거꾸로 받음
        }
    }

    //연산 & 출력
    cout << simulation(board);
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings;
vector<int> order(10, 0); //타순
vector<bool> check(10, false);  //타자가 정해졌는지 여부를 저장
int n, ans; //이닝 수

//각 루타마다 얻는 점수
int hitScore(int hit, vector<bool> &baseman) {
    int score = 0;
    for (int i = 3; i >= 0; i--) {
        if (!baseman[i]) {  //루에 선수가 없다면 반복 처음부터 진행
            continue;
        }
        if (i + hit >= 4) { //주자가 홈에 도착하면 1점 득점
            score ++;
        } else {    //현재 선수의 공격만큼 진루
            baseman[i + hit] = true;
        }
        baseman[i] = false; //기존 루에 선수가 없음으로 표시
    }
    if (hit == 4) { //홈런이면 타자도 홈까지 진루하므로 득점
        score++;
    } else {
        baseman[hit] = true; //새로운 선수들 홈에 도착
    }
    return score;   //점수 리턴
}

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) {   //3아웃이 발생하면 이닝 종료
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10) {    //인덱스 번호 다시 1로 돌려놓음
                idx = 1;
            }
            if (state == 0) {   //아웃 카운트
                out++;
            } else {
                score += hitScore(state, baseman);  //현재 점수 더하기
            }
        }
    }
    return score;   //점수 리턴
}

//백트래킹
//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1); //다음 타자로 넘어감
        return;
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score);  //최대 점수 저장
        return;
    }
    for (int i = 2; i <= 9; i++) {
        if (!check[i]) {    //i번 선수가 정해지지 않았으면
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자
            check[i] = false;   //i번 선수가 정해지지 않은 상태로 다시 돌려놓음
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    //입력
    cin >> n;
    innings.assign(n, vector<int>(10, 0));  //각 선수가 각 이닝에서 얻는 결과
    for (int i = 0; i < n; i++) {   //1번 이닝부터 N번 이닝까지
        for (int j = 1; j < 10; j++) {  //9명의 선수
            cin >> innings[i][j];
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    array(1);

    //출력
    cout << ans;
    return 0;
}
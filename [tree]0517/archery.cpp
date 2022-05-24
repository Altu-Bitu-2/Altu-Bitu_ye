#include <vector>
#include <iostream>

using namespace std;
const int SIZE = 10;    //과녁 점수

vector<int> answer = {-1}; //라이언이 가장 큰 점수 차이로 우승하는 경우
int max_diff = 0; //가장 큰 점수 차이

//가장 낮은 점수를 더 많이 맞힌 경우 찾는 함수
bool cmp(vector<int> &ryan) {
    for (int i = SIZE; i >= 0; i--) {   //0점 인덱스부터
        if (answer[i] > ryan[i]) {  //저장되어 있는 과녁이 가장 낮은 점수를 더 많이 맞힌 경우
            return false;   //false 반환하여 과녁 정보 갱신하지 않음
        } else if (answer[i] < ryan[i]) {   //이번에 탐색한 과녁이 가장 낮은 점수를 더 많이 맞힌 경우
            return true;    //true 반환하여 과녁 정보 갱신
        }
    }
}

int calcDiff(vector<int> &ryan, vector<int> &apeach) {
    int score_r = 0, score_a = 0;   //라이언 점수, 어피치 점수
    for (int i = 0; i <= SIZE; i++) {   //0번 인덱스부터 10번 인덱스까지 검사
        int score = SIZE - i;   //i번째는 (10-i)점
        if (ryan[i] > apeach[i]) {  //라이언이 더 많이 쏜 경우
            score_r += score;   //라이언 점수 증가
        } else if (ryan[i] < apeach[i]) {   //어피치가 더 많이 쏜 경우
            score_a += score;   //어피치 점수 증가
        }
    }
    return score_r - score_a;   //라이언 점수와 어피치 점수 차 반환
}
//매개변수: 탐색할 인덱스, 남은 화살 개수, 라이언의 과녁 정보, 어피치의 과녁 정보
void backtracking(int cnt, int extra_arrows, vector<int> &ryan, vector<int> &apeach) {
    if (cnt == SIZE + 1 || extra_arrows == 0) { //(기저조건) 0점 과녁까지 탐색 or 남은 화살 없음
        ryan[SIZE] = extra_arrows; //화살 남아있을 수 있으므로
        int curr_diff = calcDiff(ryan, apeach); //현재 점수 차 계산
        if (max_diff < curr_diff) { //현재 점수 차가 더 크다면
            max_diff = curr_diff;   //최대 점수 차 값 갱신
            answer = ryan;  //라이언이 우승하므로 정답 배열에 라이언의 과녁 정보 저장
        } else if (curr_diff != 0 && max_diff == curr_diff && cmp(ryan)) {
          //점수 차가 0이 아니고, 저장되어 있는 최대 점수 차와 같으면
          //가장 낮은 점수를 더 많이 맞힌 경우를 저장
            answer = ryan;  //과녁정보 갱신
        }
        return;
    }
    if (extra_arrows > apeach[cnt]) { //남은 화살로 라이언이 점수를 얻을 수 있다면
        ryan[cnt] = apeach[cnt] + 1;    //어피치보다 한 발 더 쏨
        backtracking(cnt + 1, extra_arrows - apeach[cnt] - 1, ryan, apeach);    //다음 인덱스 수 호출
                                //남은 화살 개수 = 어피치보다 한 발 더 쏜 후 남은 화살 개수
        ryan[cnt] = 0;  //다시 돌아왔을 때 원래 상태로 돌려놓음
    }
    backtracking(cnt + 1, extra_arrows, ryan, apeach);  //다음 인덱스 수 호출
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(SIZE + 1, 0); //라이언의 과녁 정보
    backtracking(0, n, ryan, info); //연산
    return answer;  //정답 반환
}

/**
 * [양궁대회]
 *
 * 1. 가능한 모든 경우를 백트래킹 탐색을 통해 검사
 * -> 라이언이 점수를 얻어가려면 어피치보다 1개 더 쏘는 경우가 최적. 어피치보다 적게 화살 쏘는 건 점수 못 얻어가므로 어차피 의미가 없음.
 * -> 따라서 라이언이 각 점수에 화살을 아래와 같이 쏘는 2가지 경우만 고려해서 만들어지는 모든 경우를 백트래킹으로 탐색
 *    - 어피치가 점수 획득을 하는 경우: 해당 점수에는 화살을 한 발도 쏘지 않는 것이 이득
 *    - 라이언이 점수 획득을 하는 경우: 필요한 최소 화살을 사용하는 것이 이득이므로 어피치보다 정확히 한 발 더 쏨
 *
 * 2. 가장 큰 점수 차이가 동일한 경우, 낮은 점수를 더 많이 맞힌 경우를 조건문으로 따로 해결
 * -> 단순 탐색하다가 갱신되는 값으로 하면 코너케이스 생김
 * -> 직접 0점 과녁부터 개수 비교해서 가장 낮은 점수를 더 많이 맞힌 경우 선택할 수 있도록 함
 *
 * !주의! 0번 인덱스가 10점 과녁임을 주의
 */

//디버깅을 위한 메인 코드 - 프로그래머스에는 제출 X
int main() {
    int n = 5;  //화살 개수 = 5개
    vector<int> info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};   //어피치의 과녁 정보
    vector<int> result = solution(n, info); //라이언의 과녁 정보
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';   //라이언의 과녁 정보 출력
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int> &belt) {
    vector<int> sushi(d + 1, 0);    //초밥 먹은 개수
                                    //배열의 크기는 초밥의 가짓수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;
    sushi[c]++; //쿠폰 번호에 적힌 초밥의 종류 먹음 표시

    //윈도우 초기화
    for (int i = 0; i < k; i++) {   //연속해서 먹는 접시의 수만큼 반복
        if (!sushi[belt[i]]) {  //벨트에 있는 초밥 종류 중 먹지 않은 초밥 종류이면
            section_sushi++;    //첫번째 슬라이딩 윈도우에서 먹을 수 있는 초밥 종류 증가
        }
        sushi[belt[i]]++;   //벨트에 있는 초밥 먹음 표시
    }

    int ans = section_sushi;    //첫번째 슬라이딩 윈도우에서 먹을 수 있는 초밥 종류로 정답 초기화
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--;   //이번 윈도우에서 제외되는 초밥 종류는 먹은 개수 1 감소
        if (!sushi[belt[i - k]]) {  //이번 윈도우에서 제외되는 초밥 종류를 표시한 후에 먹은 개수가 0개이면
            section_sushi--;        //먹을 수 있는 초밥 종류 감소
        }
        if (!sushi[belt[i % n]]) {  //이번 윈도우에서 추가되는 초밥이 먹지 않은 종류라면
            section_sushi++;        //먹을 수 있는 초밥 종류 증가
        }
        sushi[belt[i % n]]++;   //이번 윈도우에서 추가되는 초밥 먹음 표시
        ans = max(ans, section_sushi);  //저장되어 있는 정답과 크기 비교하여 최댓값 저장
    }
    return ans; //정답 리턴
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    int n, d, k, c; //벨트에 놓인 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0); //벨트에 놓인 초밥 종류
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);
    return 0;
}
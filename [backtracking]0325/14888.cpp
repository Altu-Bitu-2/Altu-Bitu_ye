#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;    //결과의 최댓값
const int SIZE = 11;    //N의 최대 개수

int n;  //수의 개수
vector<int> num(SIZE + 1);  //수열
vector<int> expression(4); //0: +, 1: -, 2: *, 3: / 연산자의 개수
int max_value = -INF_MAX, min_value = INF_MAX;  //만들 수 있는 식의 결과의 최댓값, 최솟값

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum);    //연산 결과의 최댓값 구하기
        min_value = min(min_value, sum);    //연산 결과의 최솟값 구하기
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {    //연산자의 수가 0이상이면
            expression[i]--;    //연산자의 수 1 감소
            int new_sum = 0;    //하나의 연산 후의 결과 값
            switch (i) {    //연산자 종류에 따라 연산
                case 0: // + 연산
                    new_sum = sum + num[cnt + 1];
                    break;
                case 1: // - 연산
                    new_sum = sum - num[cnt + 1];
                    break;
                case 2: // * 연산
                    new_sum = sum * num[cnt + 1];
                    break;
                case 3: // / 연산
                    new_sum = sum / num[cnt + 1];
                    break;
            }
            backtracking(cnt + 1, new_sum); //다음 수 연산
            expression[i]++;    //연산자의 수 원래 상태로
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;   //수의 개수
    for (int i = 0; i < n; i++) {   //수열
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {   //연산자의 개수
        cin >> expression[i];
    }

    //연산
    backtracking(0, num[0]);    //수열의 0번째 인덱스부터

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}
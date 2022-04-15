#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int childNum(int len, vector<int> &snacks) {
    int cnt = 0;    //과자를 나눠줄 수 있는 조카의 수
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) { //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break;
        }
        //(존재하는 과자의 길이/나누어주려는 과자의 길이) = 과자를 나누어 줄 수 있는 조카의 수이므로
        //계산한 값을 더함
        cnt += (snacks[i] / len);
    }

    return cnt; //과자를 나눠줄 수 있는 조카의 수 리턴
}

//인자: 과자 길이의 최솟값, 과자 길이의 최댓값, 과자의 수, 과자의 길이 배열
int upperSearch(int left, int right, int target, vector<int> &snacks) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 반복 종료
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(mid, snacks); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1;
        } else {    //target보다 더 적은 아이들에게 나눠준다면 -> 과자 길이를 줄여야 함
            right = mid - 1;
        }
    }
    return left - 1;    //과자 길이의 최댓값 리턴
                        //m명의 조카에게 나눠줄 수 있는 과자의 길이 중 최댓값
}

/**
 * [과자 나눠주기]
 *
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {
    int m, n, left = 1, right = 0;  //조카의 수, 과자의 수, 과자 길이의 최솟값, 과자 길이의 최댓값

    //입력
    cin >> m >> n;
    vector<int> snacks(n, 0);   //과자 n개의 길이
    for (int i = 0; i < n; i++) {
        cin >> snacks[i];
    }

    //연산
    sort(snacks.begin(), snacks.end()); //오름차순 정렬
    right = snacks[n - 1];  //과자 길이의 최댓값 = 마지막 인덱스에 해당하는 과자의 길이

    //연산 & 출력
    cout << upperSearch(left, right, m, snacks);
    return 0;
}
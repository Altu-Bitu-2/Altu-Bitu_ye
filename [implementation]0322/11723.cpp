#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;    //집합에는 1~20의 숫자만 입력되므로 SIZE를 21로 설정

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    //시간초과 방지를 위해 cin 실행속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, num; //수행해야 하는 연산의 수, 연산에 필요한 값 x
    string cmd; //수행해야 하는 연산
    vector<bool> s(SIZE, false);    //1~20까지 그 숫자가 S에 존재하면 ture, 존재하지 않으면 false
                                    //공집합으로 초기화

    cin >> m;   //입력
    while (m--) {   //연산의 수만큼 반복
        cin >> cmd; //입력
        if (cmd == "all") {     //S를 {1, 2, ..., 20}으로 바꿈
            s.assign(SIZE, true);   //모든 원소가 존재하므로 전체를 true로 초기화
            continue;   //다음 연산으로 넘어감
        }
        if (cmd == "empty") {   //S를 공집합으로 바꿈
            s.assign(SIZE, false);  //모든 원소가 존재하지 않으므로 전체를 false로 초기화
            continue;
        }

        cin >> num; //입력. 앞의 두 연산에는 x가 필요 없음.
        if (cmd == "add") { //S에 x를 추가
            s[num] = true;  //x에 해당하는 인덱스에 접근하여 ture로 변경
            continue;
        }
        if (cmd == "remove") {  //S에서 x를 제거
            s[num] = false; //x에 해당하는 인덱스에 접근하여 fasle로 변경
            continue;
        }
        if (cmd == "check") {   //S가 있으면 1, 없으면 0을 출력
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        if (cmd == "toggle") {  //S에 x가 있으면 x를 제거하고, 없으면 x를 추가
            s[num] = !s[num];   //S의 상태를 반대로 변경(true->false / false->true)
            continue;
        }
    }
    return 0;
}
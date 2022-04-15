#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
    string ans = "";
    int start = arrow_point;    //화살표가 가리키는 지점의 인덱스
    do {
        ans += wheel[arrow_point];  //해당 인덱스의 바퀴에 적혀있는 알파벳 저장
        arrow_point = (arrow_point + 1) % n;    //인덱스를 다음으로 넘김
                                                //바퀴의 칸수를 초과할 수 있으므로 바퀴의 칸수만큼 나눔
    } while (arrow_point != start); //화살표가 가리키는 지점의 인덱스로 다시 돌아올 때까지 반복
    return ans; //바퀴에 적힌 알파벳 리턴
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) {
        int rot = record[i].first;  //화살표가 가리키는 글자가 몇 번 바뀌었는지
        char alpha = record[i].second;  //회전을 멈추었을 때 가리키던 글자
        idx = (idx - rot % n + n) % n;
        //시계 방향으로 회전하므로 기존 인덱스에서 - 연산
        //바퀴의 칸수만큼 회전하면 기존 인덱스로 돌아오므로, rot에서 바퀴의 칸수만큼 나눈 나머지를 뺌
        //인덱스가 음수가 될 수 있으므로 + 바퀴의 칸수
        //이 값을 다시 바퀴의 칸수만큼 나눔
        if (wheel[idx] == alpha) {  //이미 알파벳이 써 있는 경우 같은 알파벳이면 계속 진행
            continue;
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) {   //알파벳이 중복되므로 행운의 바퀴 없음
            return "!";
        }
        wheel[idx] = alpha; //위 조건에 해당하지 않으면 알파벳을 바퀴에 적음
        is_available[alpha - 'A'] = true;   //중복되지 않도록 중복 여부 체크
    }
    //인자: 마지막 회전을 멈추었을 때 화살표가 가리키는 인덱스, 바퀴의 칸수, 바퀴의 상태를 나타내는 배열
    return arrowStartWheel(idx, n, wheel);
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k;   //바퀴의 칸수, 바퀴를 돌리는 횟수

    //입력
    cin >> n >> k;
    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second;
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0;
}
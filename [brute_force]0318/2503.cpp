#include <iostream>
#include <vector>

using namespace std;

const int MAX_NUM = 988;    // 가능한 마지막 숫자는 987
vector<bool> num;

void conditionCheck() {

    for (int i = 0; i < 100; i++) num[i] = false;    // 세 자리 수가 아닌 수는 false
    for (int i = 100; i < MAX_NUM; i++) {  //세 자리 수 중에서 검토
        string s = to_string(i);    // i를 문자열로 변환하여 비교
        for (int j = 0; j < 3; j++) {     // 0이 들어가면 false
            if (s[j] == '0') {
                num[i] = false;
                break;
            }
        }
        if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) {
            num[i] = false; // 중복된 수가 있으면 false
        }
    }
}

void baseballCheck(string &str, int strike, int ball) {

    for (int i = 123; i < MAX_NUM; i++) {   // 123~987까지 체크
        if (num[i] == false) continue;   // 가능성이 없는 수 건너뛰기

        string temp = to_string(i); // i를 string으로 변환하여 num과 비교
        int strikeTemp = 0, ballTemp = 0;   // strike, ball의 개수 비교를 위한 변수

        for (int j = 0; j < 3; j++) { // 위치와 숫자가 같으면 strike
            if (str[j] == temp[j]) strikeTemp++;
        }
        //위치는 다른데 숫자가 같으면 ball
        if (str[0] == temp[1] || str[0] == temp[2]) ballTemp++;
        if (str[1] == temp[2] || str[1] == temp[0]) ballTemp++;
        if (str[2] == temp[0] || str[2] == temp[1]) ballTemp++;

        // strike, ball의 개수가 모두 일치하지 않으면 가능성이 없는 수
        if (!(strike == strikeTemp) || !(ball == ballTemp)) num[i] = false;
    }
}

int main() {

    int n, ans = 0;
    cin >> n;

    num.assign(MAX_NUM, true); // 모두 가능성이 있는 상태로 초기화
    conditionCheck();   // 조건에 맞게 false 저장

    while (n--) {
        int strike, ball;
        string str;

        // 세 자리 수, 스트라이크 개수, 볼 개수 입력
        cin >> str >> strike >> ball;
        baseballCheck(str, strike, ball);
    }

    for (int i = 123; i < MAX_NUM; i++) {
        if (num[i] == true) ans++;
    }
    cout << ans;

    return 0;
}
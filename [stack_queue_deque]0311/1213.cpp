#include <iostream>
#include <deque>

using namespace std;

void palindrome(string str) {

    int alp[26] = {0,};   //알파벳의 개수
    int odd = 0;    //홀수 알파벳의 개수
    deque<char> dq;

    for (int i = 0; i < str.size(); i++) {    //알파벳의 개수 저장
        alp[str[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alp[i] % 2 != 0) {   //홀수인 알파벳이 존재할 경우
            odd++;
            if (odd > 1) {    //홀수인 알파벳의 개수가 2개 이상일 경우 불가능
                cout << "I'm Sorry Hansoo";
                return;
            }
            dq.push_front(i + 'A');   //홀수인 알파벳부터 삽입
            alp[i]--;  //개수 차감
        }
    }

    //앞뒤로 알파벳 개수만큼 삽입
    for (int i = 25; i >= 0; i--) { //사전순
        while (alp[i] != 0) {
            dq.push_front(i + 'A');
            dq.push_back(i + 'A');
            alp[i] = alp[i] - 2;   //개수 차감
        }
    }

    while (!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
};

int main() {

    string str;
    cin >> str;

    palindrome(str);

    return 0;
}

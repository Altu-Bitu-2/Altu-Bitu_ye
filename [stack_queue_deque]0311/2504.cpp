#include <iostream>
#include <stack>

using namespace std;

void calculate(string &s) {
    stack<char> st;
    int tmp = 1, ans = 0;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '(':
                tmp *= 2;
                st.push(s[i]);
                break;
            case '[':
                tmp *= 3;
                st.push(s[i]);
                break;
            case ')':
                if (st.empty() || st.top() != '(') {    //올바르지 못한 괄호열
                    cout << 0;
                    return;
                }
                if (s[i - 1] == '(') ans += tmp; //괄호가 닫혔으므로 뒤부터는 + 연산
                st.pop();
                tmp /= 2;
                break;
            case ']':
                if (st.empty() || st.top() != '[') { //올바르지 못한 괄호열
                    cout << 0;
                    return;
                }
                if (s[i - 1] == '[') ans += tmp; //괄호가 닫혔으므로 뒤부터는 + 연산
                st.pop();
                tmp /= 3;
                break;
        }
    }

    if (!st.empty()) {
        cout << 0;
        return;
    }

    cout << ans;
}

int main() {

    string s;
    cin >> s;

    calculate(s);

    return 0;
}
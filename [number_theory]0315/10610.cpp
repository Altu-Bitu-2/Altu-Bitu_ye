#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    string s;
    cin >> s;

    //내림차순 정렬
    sort(s.begin(), s.end(), greater<>());

    //마지막 수가 0이 아니면 존재하지 않는다.
    if (s[s.length()-1] != '0')  cout << -1;
    else {
        int sum = 0;    //각 자리 수의 합
        for (int i = 0; i < s.length(); i++) {
            sum += s[i] - '0';
        }
        //각 자리 수의 합이 3의 배수가 아니면 존재하지 않는다.
        if (sum % 3 != 0) cout << -1;
        else cout << s;
    }


    return 0;
}
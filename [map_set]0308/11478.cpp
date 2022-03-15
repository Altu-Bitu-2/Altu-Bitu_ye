#include <iostream>
#include <set>

using namespace std;

int main() {

    string s;   //입력받을 문자열 S
    set<string> sub_s; //부분 문자열을 저장할 set
    string temp = "";    //set에 저장할 부분문자열

    cin >> s;
    for (int i = 0; i < s.size(); i++) {  //문자열 S만큼 반복
        for (int j = i; j < s.size(); j++) {  //부분문자열의 문자열 길이를 늘여주면서 반복
            temp += s[j];
            sub_s.insert(temp); //ababc의 경우 a, ab, aba, ...
        }
        temp = "";  //초기화
    }
    cout << sub_s.size();

    return 0;
}
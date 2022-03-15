#include <iostream>
#include <map>

using namespace std;

int main() {

    int n;  //파일의 개수
    string s, exe;  //파일명, 확장자명
    int dot, cnt = 0;    //점(.)의 위치, 확장자 개수

    map<string, int> file; //확장자 이름, 개수

    cin >> n;

    while (n--) {
        cin >> s;
        dot = 1000;
        for (int i = 0; i < s.size(); i++) {    //확장자명만 남기기
            if (s[i] == '.') dot = i;    //'.'이후로 확장자명
            if (i > dot) exe += s[i];    //확장자명 저장
        }
        file[exe]++;
        exe = "";
    }

    //출력
    for (auto iter: file) {
        cout << iter.first << ' ' << iter.second << '\n';
    }

    return 0;
}
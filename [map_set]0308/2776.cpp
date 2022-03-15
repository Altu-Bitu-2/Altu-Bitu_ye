#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;  //테스트케이스 개수
    cin >> t;

    while (t--) {

        unordered_set<int> note;    //수첩 1
        int n, m;   //수첩 1 정수 개수, 수첩 2 정수 개수
        int num;    //수첩에 저장할 정수

        cin >> n;    //수첩 1 정수 개수 입력

        for (int i = 0; i < n; i++) {   //수첩 1 정수 입력
            cin >> num;
            note.insert(num);
        }

        cin >> m;    //수첩 2 정수 개수 입력
        while (m--) {
            cin >> num;
            if(note.find(num) != note.end()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}
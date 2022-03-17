#include <iostream>
#include <queue>

using namespace std;

int main() {

    int n, k;
    queue<int> q;
    int num;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }

    cout << '<';
    while (q.front() != q.back()) { //1명이 남을 때까지
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());  //맨 앞 원소를 맨 뒤로
            q.pop();            //맨 앞 원소 삭제
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.back() << '>';

    return 0;
}
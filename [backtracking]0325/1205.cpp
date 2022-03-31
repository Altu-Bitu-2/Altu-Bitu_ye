#include <iostream>
#include <vector>

using namespace std;

vector<int> list;

int countRank(int score) {

    for (int i = 1; i < list.size(); i++) {
        if (list[i] <= score) {   //새로운 점수가 리스트의 점수보다 높으면 등수
            return i;
        }
    }
    return -1;
}

int main() {

    //리스트에 있는 점수 개수, 새로운 점수, 리스트에 올라갈 수 있는 점수의 개수
    int n, score, p;

    cin >> n >> score >> p;
    list.assign(p + 1, -1); //점수의 최솟값은 0이므로 -1로 초기화

    for (int i = 1; i <= n; i++) {    //등수는 1부터 시작
        cin >> list[i];
    }

    //리스트에 점수가 없으면 1등
    if (n == 0) cout << 1;
        //리스트가 꽉 차 있을 때, 새 점수가 이전 점수와 같으면 리스트에 올라갈 수 없음
    else if (list[p] == score) cout << -1;
    else cout << countRank(score);

    return 0;
}
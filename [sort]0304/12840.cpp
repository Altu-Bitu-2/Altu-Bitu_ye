#include <iostream>

using namespace std;

int main() {

    int h, m, s, q, T, c;   //현재 시간(h, m, s), 쿼리의 개수(q), 쿼리(T), 초(c)
    int time;   // 현재 시간을 초 단위로 저장
    int day = 86400;    //하루 24시간 = 86400초

    // cin 사용 시 시간 초과
    scanf("%d %d %d %d", &h, &m, &s, &q);   //현재 시간, 쿼리 수 입력
    time = h * 3600 + m * 60 + s;  //현재 시간을 초 단위로 변환
    for (int i = 0; i < q; i++) {
        scanf("%d", &T);    //쿼리 입력
        if (T == 1) {   //T가 1일 때 시계를 앞으로 c초 돌림
            scanf("%d", &c);    //c 입력
            time = (time + c) % day;  //현재 시간에 c초 더하기, 하루가 넘어갈 수 있으므로 day로 나누기
        } else if (T == 2) {    //T가 2일 때 시계를 뒤로 c초 돌림
            scanf("%d", &c);
            time = (time - c) % day;  //현재 시간에 c초 빼기
            while (time < 0) {  //현재 시간이 음수면 하루 전으로 간 것이므로 day 더하기
                time += day;
            }
        } else {    //T가 3일 때 시간 출력
            cout << time / 3600 << ' ' << (time / 60) % 60 << ' ' << time % 60 << '\n';
        }
    }
    return 0;
}
#include <iostream>

using namespace std;

int main() {

    int h, m, s, q, T, c;
    int time;
    scanf("%d %d %d %d", &h, &m, &s, &q);
    time = h * 3600 + m * 60 + s;
    for (int i = 0; i < q; i++) {
        scanf("%d", &T);
        if (T == 1) {
            scanf("%d", &c);
            time = (time + c) % 86400;
        } else if (T == 2) {
            scanf("%d", &c);
            time = (time - c) % 86400;
            while (time < 0) {
                time += 86400;
            }
        } else {
            cout << time / 3600 << ' ' << (time / 60) % 60 << ' ' << time % 60 << '\n';
        }
    }
    return 0;
}
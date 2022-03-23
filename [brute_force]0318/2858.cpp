#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int r, b, room_size, l, w;   // 가장자리 타일 수, 안쪽 타일 수, 방의 크기 (l > w)
    cin >> r >> b;

    room_size = r + b; // 방의 크기 = 전체 타일의 개수의 합
    // 방의 크기의 최솟값 = 9 = 3 * 3
    for (int i = 3; i <= sqrt(room_size); i++) {
        int tempL, tempW;
        if (room_size % i == 0) { // i로 나누어 떨어질 때
            tempL = room_size / i;  // 큰 수가 l
            tempW = room_size / tempL;
        }
        if (r == tempL * 2 + tempW * 2 - 4) { // 가장자리 타일 수 = 가로 * 2 + 세로 * 2
            l = tempL;
            w = tempW;
        }
    }

    // 출력
    cout << l << ' ' << w;

    return 0;
}
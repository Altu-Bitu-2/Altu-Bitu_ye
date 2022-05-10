#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int mineLand(int n, int m, int b, int height, vector<vector<int>> &land) {
    int tot_time = 0;   //땅을 고르는 데 걸리는 시간
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //블록 제거
            if (land[i][j] > height) { //만드려는 높이보다 크다면
                b += (land[i][j] - height); //제거한 블록 인벤토리에 추가
                tot_time += 2 * (land[i][j] - height);  //한 블록 제거하는 데 2초 걸림
                //블록 쌓기
            } else if (land[i][j] < height) { //만드려는 높이보다 작다면
                b -= (height - land[i][j]); //인벤토리에서 블록을 꺼냄
                tot_time += (height - land[i][j]);  //블록을 쌓는 데 1초 걸림
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1;
    return tot_time;    //걸리는 시간 리턴
}

/**
 * [마인크래프트]
 *
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 * !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
 */

int main() {
    //집터의 세로, 가로, 작업 시작 전 인벤토리에 들어있는 블록 수
    //가장 낮은 땅의 높이, 가장 높은 땅의 높이(이후에 비교하기 위해 최대 높이, 최소 높이로 초기화)
    int n, m, b, min_height = 256, max_height = 0;

    //입력
    cin >> n >> m >> b;
    vector<vector<int>> land(n, vector<int>(m, 0)); //땅의 높이
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> land[i][j];
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0; //땅을 고르는 데 걸리는 시간, 땅의 높이
    //땅의 높이의 후보: (가장 낮은 땅) ~ (가장 높은 땅)
    for (int i = min_height; i <= max_height; i++) {
        int t = mineLand(n, m, b, i, land); //범위 내에서 높이에 따른 시간 계산
        if (t <= min_time) { //가장 빨리 작업이 끝나는 높이
            min_time = t;
            height = i;
        }
    }

    //출력
    cout << min_time << ' ' << height;
    return 0;
}
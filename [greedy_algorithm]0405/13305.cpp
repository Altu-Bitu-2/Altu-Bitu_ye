#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

//인자는 1. 도로의 길이 2. 주유소의 리터당 가격을 나타내는 배열, 도시의 개수
ll greedyOil(vector<pair<ll, ll>> &city, int n) {
    ll cur_cost = city[0].second, tot_cost = 0;
    //현재까지 가장 싼 가격을 나타내는 변수. 첫 번째 도시의 가격으로 초기화
    //총 비용. 0으로 초기화

    for (int i = 0; i < n; i++) {
        if (city[i].second < cur_cost) { //이 도시의 기름값이 더 저렴하면 교체
            cur_cost = city[i].second;
        }
        tot_cost += (cur_cost * city[i].first); //이동 비용
                    //가장 저렴한 비용 * 이동에 필요한 기름(도로의 길이)
    }
    return tot_cost;    //최소 비용 리턴
}

/**
 * [주유소]
 *
 * 최대한 가격이 싼 곳에서 많은 기름을 넣어야 한다.
 * 따라서 첫번째 도시부터 현재까지 가장 싼 가격을 저장하고, 이동에 필요한만큼만 기름을 채운다.
 * 이렇게 하면 지금까지 지나 온 도시 중 가장 싼 곳에서 최대한 많이 살 수 있다.
 *
 * !주의! 도시 사이의 간격이 최대 10^9이고, 리터당 가격이 최대 10^9이므로
 *       가능한 정답의 최댓값은 10^18으로 int 범위 넘어감! -> long long 써야 함
 */

int main() {
    int n;  //도시의 개수

    //입력
    cin >> n;
    vector<pair<ll, ll>> city(n, {0, 0});   //도로의 길이, 주유소의 리터당 가격
    for (int i = 0; i < n - 1; i++) {   //도로의 길이 입력. (n - 1)개
        cin >> city[i].first;
    }
    for (int i = 0; i < n; i++) {   //주유소의 리터당 가격 입력
        cin >> city[i].second;
    }

    //연산 & 출력
    cout << greedyOil(city, n);
    return 0;
}
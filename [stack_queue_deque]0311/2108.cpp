#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    map<int, int> m;
    vector<int> v;
    int num;
    double sum; //N개의 수들의 합

    for (int i = 0; i < n; i++) { //N개의 수들 저장
        cin >> num;
        v.push_back(num);
        m[num]++;
        sum += num;
    }

    //1. 산술평균 출력
    cout << floor(sum / n + 0.5) << '\n';

    //2. 중앙값 출력
    sort(v.begin(), v.end());
    cout << v[n / 2] << '\n';

    //3. 최빈값 출력
    int max = 0, most, cnt = 0;  //빈도수, 최빈값, 최빈값의 개수
    for (auto iter: m) {
        if (max < iter.second) {
            max = iter.second;
            most = iter.first;
        }
    }
    for(auto iter:m){   //빈도수가 같은 수가 있는지 찾기
        if(max == iter.second)  cnt++;
        if(cnt > 1){
            most = iter.first;
            break;
        }
    }

    cout << most << '\n';

    //4. 범위 출력
    cout << v[v.size() - 1] - v[0] << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;  //세 용액을 섞은 값을 최댓값으로 초기화

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll> &arr, ll fixed, int left, int right) {
    pair<ll, ll> ans;   //세 용액 중 고정된 용액을 제외한 용액
    ans = make_pair(INF, INF);  //최댓값으로 초기화

    while (left < right) {  //포인터가 교차되면 반복문 종료
        ll mix = fixed + arr[left] + arr[right];    //세 용액을 섞은 값
        if (mix == 0) { //값이 0이면 정답으로 리턴
            return make_pair(arr[left], arr[right]);
        }
        if (abs(mix) < min_diff) {  //섞은 값의 절댓값이 저장된 최솟값보다 작으면(0에 가까우면) 값 갱신
            min_diff = abs(mix);    //세 용액을 섞은 값을 현재 값으로 저장
            ans = make_pair(arr[left], arr[right]); //두 용액을 정답으로 저장
        }
        if (mix > 0) {  //섞은 값이 양수이면 값을 줄이기 위해 오른쪽 포인터를 왼쪽으로 이동
            right--;
        } else {    //섞은 값이 음수이면 값을 늘리기 위해 왼쪽 포인터를 오른쪽으로 이동
            left++;
        }
    }
    return ans; //정답 리턴
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n;  //용액의 수

    //입력
    cin >> n;
    vector<ll> arr(n, 0);   //용액의 특성값
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(), arr.end());   //정렬
    tuple<ll, ll, ll> ans;  //정답(세 용액의 특성값)
    for (int i = 0; i < n - 2; i++) {
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second);
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}
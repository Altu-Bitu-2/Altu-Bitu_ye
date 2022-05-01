#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {   //idx: 현재 만드려는 수의 인덱스
    while (left < right) {  //포인터가 교차되면 반복문 종료
        if (left == idx) {  //현재 만드려는 수를 가리키고 있으므로 다음 위치(오른쪽)로 이동
            left++;
            continue;
        }
        if (right == idx) { //현재 만드려는 수를 가리키고 있으므로 다음 위치(왼쪽)로 이동
            right--;
            continue;
        }

        if (num[left] + num[right] == num[idx]) {   //현재 수를 만드는 두 수가 존재하므로 true 리턴
            return true;
        }
        if (num[left] + num[right] > num[idx]) {    //두 수의 합이 만드려는 수보다 크므로 오른쪽 포인터를 왼쪽으로 이동
            right--;
        } else {    //두 수의 합이 만드려는 수보다 작으므로 왼쪽 포인터를 오른쪽으로 이동
            left++;
        }
    }
    return false;   //반복문이 종료되었는데 현재 수를 만들 수 없었으므로 false 리턴
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0; //수의 개수, 좋은 수의 개수

    //입력
    cin >> n;
    vector<int> num(n, 0);  //주어진 수
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    //연산
    sort(num.begin(), num.end());   //정렬
    for (int i = 0; i < n; i++) {
        if (isGood(num, 0, n - 1, i)) { //좋은 수이면 정답(좋은 수의 개수) 1 증가
            ans++;
        }
    }

    //출력
    cout << ans;
    return 0;
}
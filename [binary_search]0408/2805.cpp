#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {
    ll sum = 0;
    for (int i = 0; i < tree.size(); i++) { //나무의 수만큼 반복
        if (height >= tree[i]) {    //절단기의 높이가 나무의 높이보다 높으면
            return sum;             //내림차순이므로 뒤의 나무도 절단기보다 낮음
                                    //더이상 sum에 더해질 값이 없으므로 리턴
        }
        sum += (tree[i] - height);  //(나무의 높이 - 절단기의 높이)를 더함
    }
    return sum; //가져갈 수 있는 나무의 길이 리턴
}

//인자: 절단기의 최소 높이, 최대 높이, 가져가려고 하는 나무의 길이, 나무의 높이 배열
int upperSearch(int left, int right, int target, vector<int> &tree) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 반복 종료
        int mid = (left + right) / 2;   //중간값
        ll tree_cnt = cntTree(mid, tree);   //가져갈 수 있는 나무의 길이 계산

        //절단기의 높이가 높을 수록, 가져갈 수 있는 나무의 길이가 줄어듦
        if (tree_cnt >= target) {   //가져갈 수 있는 나무의 길이 >= 가져가려고 하는 나무의 길이(target)
                                    //절단기의 높이를 늘여야 함
                                    //target이 오른쪽에 있음
                                    //target과 같으면 오른쪽에 target과 같은 값이 더 있을 수 있음
            left = mid + 1; //
        } else {    //가져갈 수 있는 나무의 길이 < 가져가려고 하는 나무의 길이(target)
                    //절단기의 높이를 줄여야 함
                    //target이 왼쪽에 있음
            right = mid - 1;
        }
    }
    //left가 target을 초과하는 순간의 바로 전의 인덱스값이 절단기 높이의 최댓값
    return left - 1;
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m;   //나무의 수, 가져가려고 하는 나무의 길이

    //입력
    cin >> n >> m;
    vector<int> tree(n, 0); //나무의 높이
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    //내림차순 정렬
    sort(tree.begin(), tree.end(), greater<>());

    //연산 & 출력
    //인자: 절단기의 최소 높이, 최대 높이, 가져가려고 하는 나무의 길이, 나무의 높이 배열
    cout << upperSearch(0, tree[0], m, tree);
    //찾고자 하는 값인 X를 초과하는 수가 처음으로 나오는 위치
    //가져가려고 하는 나무의 길이에 해당하는 절단기의 높이 중 최댓값
    return 0;
}
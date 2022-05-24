#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const pair<int, ci> &c1, const pair<int, ci> &c2) {
    if (c1.second.first != c2.second.first) {   //추천 수가 다를 경우
        return c1.second.first < c2.second.first;   //추천 수가 가장 작은 학생 삭제
    }
    return c1.second.second < c2.second.second; //추천수가 같을 경우 게시 시간이 오래된 학생 삭제
}

/**
 * [후보 추천하기]
 *
 * 1. 비어있는 사진틀이 없는 경우, 가장 추천수가 작은 학생 중 게시 시간이 오래된 학생을 삭제
 * -> min_element() 함수를 활용해서 조건을 만족하는 학생 찾기
 * -> min_element(x.begin(), x.end(), cmp): x 컨테이너 내에서 최솟값을 찾아주는 함수로 정렬과 비슷하게 cmp함수 써서 조건 설정 가능!
 *
 * 2. 후보 학생을 바로 찾기 위해 본 풀이는 map 컨테이너를 사용해 구현
 *
 * !주의! 게시 시간 정보 저장 시, 후보로 올라간 가장 첫 시간을 저장. 이미 후보에 있는데 게시 시간이 갱신되지 않도록 주의.
 */

int main() {
    int n, m, input;    //사진틀의 개수, 전체 학생의 총 추천 횟수, 추천받은 학생의 번호

    //입력 & 연산
    cin >> n >> m;  //사진틀의 개수, 전체 학생의 총 추천 횟수 입력
    map<int, ci> candidate; //first: 후보 학생, second: {추천 횟수, 게시 시간}
    for (int i = 0; i < m; i++) {   //추천 횟수만큼 반복
        cin >> input;   //추천받은 학생의 번호 입력
        //비어있는 사진틀이 없는 경우
        //find() 함수: 원소가 존재하지 않으면 end() 반환
        //후보 학생 수가 사진틀의 개수와 같고, 현재 입력된 학생이 후보에 존재하지 않음
        if (candidate.size() == n && candidate.find(input) == candidate.end()) {
            //가장 추천수가 작은 학생 중 게시 시간이 오래된 학생 삭제
            candidate.erase(min_element(candidate.begin(), candidate.end(), cmp));
        }
        //첫 게시라면
        if (candidate.find(input) == candidate.end()) { //input이 존재하지 않으면 candidate.end() 반환 -> 첫 게시
            candidate[input].second = i;    //게시 시간 저장
        }
        candidate[input].first++; //추천 횟수 증가
    }

    //출력
    for (auto iter = candidate.begin(); iter != candidate.end(); iter++) {
        cout << iter->first << ' '; //후보의 학생 번호 출력
    }
    return 0;
} 
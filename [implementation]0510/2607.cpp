#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;    //알파벳 개수

//알파벳별 등장횟수 저장
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0);    //A~Z 등장 횟수
    for (int i = 0; i < str.size(); i++) {
        result[str[i] - 'A']++; //해당되는 알파벳 위치에 접근하여 횟수 1증가
    }
    return result;
}

/**
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

int main() {
    int n, ans = 0; //단어의 개수, 첫 번째 단어와 비슷한 단어의 개수
    string source, target;  //첫 번째 단어, 첫 번째 단어와 비교할 단어

    //입력
    cin >> n >> source;

    //연산
    vector<int> source_alpha = alphaMap(source);    //첫 번째 단어의 알파벳 등장 횟수 저장
    while (--n) {   //(단어의 개수 -1)만큼 반복
        cin >> target;

        int diff = 0;
        vector<int> target_alpha = alphaMap(target);    //비교할 단어의 알파벳 등장 횟수 저장
        for (int i = 0; i < SIZE; i++) { //두 단어의 차이
            diff += abs(source_alpha[i] - target_alpha[i]); //알파벳 별로 등장 횟수 비교
        }
        //diff가 0일 경우, 같은 구성을 가짐
        //diff가 1일 경우, 한 문자를 더하거나 빼면 같은 구성이 됨
        //diff가 2이고 문자열의 길이가 같을 경우, 한 문자를 바꾸면 같은 구성이 됨
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) { //문자를 더하거나, 빼거나, 바꾸거나
            ans++;  //비슷한 단어의 개수 1 증가
        }
    }

    //출력
    cout << ans;
    return 0;
}
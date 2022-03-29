#include <iostream>
#include <vector>

using namespace std;

bool isGroup(string str) {  //그룹 단어가 맞으면 true를 리턴하는 함수
    char cur = NULL;    //현재의 문자
                        //다음에 나타난 문자와 비교하기 위한 변수
    vector<bool> alphabet(26, false);   //각 알파벳의 등장 여부를 체크

    for (int i = 0; i < str.size(); i++) {  //단어의 길이만큼 반복하여 한 문자씩 체크
        if (str[i] == cur) { //연속해서 나타난 문자
            continue;   //그룹 단어가 맞으므로 다음 문자로 넘어감
        }
        //이전의 문자와 다른 문자가 나타났을 때
        if (alphabet[str[i] - 'a']) {   //이전에 등장했던 문자면 떨어져서 나타난 것
                                        //true인 상태면 이전에 등장했던 문자
                                        //char를 int로 변환하여 배열의 인덱스에 접근 가능
            return false;   //그룹 단어가 아니므로 false 리턴
        }
        cur = str[i];   //현재의 문자가 바뀌었으므로 저장함
        alphabet[str[i] - 'a'] = true;  //새로운 알파벳이 등장했다고 표시하기 위해 true로 변경
    }
    return true;    //반복문 내에서 false로 리턴되지 않았으므로 그룹단어가 맞음
}

/**
 * [그룹 단어 체커] - 단순 구현 문제
 * - 이미 등장한 알파벳을 배열의 인덱스(알파벳)를 활용해서 정보 true/false로 저장
 * - set으로 체크할 수도 있겠지만 검색, 삽입 시마다 O(logN)의 시간복잡도가 걸리므로 인덱스 접근이 가능한 배열이 효율적
 * - 처음 등장하는 알파벳은 배열 정보 업데이트 하고, 무리에서 떨어졌는데 이미 등장한 알파벳이면 그룹 단어가 아니다.
 */

int main() {
    int n, result = 0;  //단어의 개수, 그룹 단어의 개수

    //입력
    cin >> n;
    while (n--) {   //단어의 개수를 다시 사용하지 않음
        string word;
        cin >> word;    //단어 입력

        //연산
        if (isGroup(word)) { //그룹 단어인지 확인
            result++;   //그룹 단어가 맞으면 그룹 단어의 개수를 나타내는 변수 1 증가
        }
    }

    //출력
    cout << result;
    return 0;
}
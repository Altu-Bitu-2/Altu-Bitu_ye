#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int num) {  //일의 자리 패턴을 구하여 배열로 리턴하는 함수
    vector<int> pattern = {num};    //배열의 첫 번째 값은 num

    int temp = num; //현재 수를 num으로 초기화
    while (num != (temp * num) % 10) {  //현재 수의 일의 자리 수가 num과 같으면 한 패턴이 종료된 것
        temp *= num;    //현재의 수에 num을 곱함
        temp %= 10;     //일의 자리수만 남기기
        pattern.push_back(temp);    //패턴을 저장하는 배열에 추가
    }
    return pattern; //패턴이 저장된 배열을 리턴
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;    //테스트 케이스의 개수, 정수 a, b

    //0 ~ 9까지 일의 자리 패턴 미리 구하기
    vector<vector<int>> last_digit(10, vector<int>(0)); //0~9까지 일의 자리의 패턴을 저장하기 위한 배열
    vector<int> pattern_size(10, 1);    //패턴의 길이를 저장하기 위한 배열
    for (int i = 0; i < 10; i++) {  //0~9까지 반복
        last_digit[i] = findPattern(i); //패턴을 구하여 저장
        pattern_size[i] = last_digit[i].size(); //패턴의 길이 저장
    }

    //입력
    cin >> t;
    while (t--) {   //테스트 케이스의 수만큼 반복
        cin >> a >> b;  //입력
        a %= 10;    //일의 자리 수만 남기기

        if (a == 0) {   //일의 자리가 0이면
            cout << "10\n"; //10번째 컴퓨터가 처리함
            continue;   //다음 케이스로 넘어감
        }
        //인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        //a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수 출력
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n';
    }
    return 0;
}
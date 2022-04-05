#include <iostream>
#include <vector>

using namespace std;

//LCS 길이 구하는 함수
int lcs(string str1, string str2) { //두 문자열을 인자로 받음
    int n = str1.length();  //첫 번째 문자열의 길이
    int m = str2.length();  //두 번째 문자열의 길이
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));   //LCS 저장
    //가능한 이전 문자열들의 조합에 대한 공통 부분 수열의 최대 길이를 저장
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                //공통 부분 문자열에 속하지 않으므로 그전의 길이 최댓값 그대로 가져옴
                //위쪽과 왼쪽 중 더 큰 쪽
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            } else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면
                //공통 부분 문자열에 추가되므로 해당 문자들이 포함되기 전의 길이 + 1
                //좌상향 대각선 + 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    return dp[n][m]; //LCS 길이 리턴
}

/**
 * LCS (해당 풀이는 "08. 동적계획법.pdf" 참고)
 *
 * 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
 */

int main() {
    string str1, str2;  //두 문자열

    //입력
    cin >> str1 >> str2;

    //연산 & 출력
    cout << lcs(str1, str2); //lcs
    return 0;
}
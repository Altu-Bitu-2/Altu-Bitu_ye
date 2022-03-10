#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n, s = 0; //배열의 길이, 배열끼리 곱해서 더한 값
    cin >> n;

    vector<int> A;
    vector<int> B;

    int num;    //배열에 저장할 원소
    for (int i = 0; i < n; i++) {   //A의 원소 입력
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < n; i++) {   //B의 원소 입력
        cin >> num;
        B.push_back(num);
    }

    //큰 수와 작은 수끼리 곱하면 최솟값
    sort(A.begin(), A.end());   //오름차순 정렬
    sort(B.begin(), B.end(), greater<int>());   //내림차순 정렬

    //연산
    for (int i = 0; i < n; i++) {
        s += A[i] * B[i];
    }

    cout << s;

    return 0;
}
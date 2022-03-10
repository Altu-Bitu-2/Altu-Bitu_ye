#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> arr; //시리얼 번호를 저장하는 배열

//비교 함수
bool cmp(const string& A, const string& B){
    if(A.size() != B.size()){   //1. A와 B의 길이가 다르면 짧은 것 먼저
        return A.size() < B.size();
    }
    int A_sum=0, B_sum=0;   // A와 B의 자리수 저장
    for(int i=0; i<A.size(); i++){  // 자리수 계산
        if('0' <= A[i] && A[i] <= '9')  A_sum += A[i] - '0';
        if('0' <= B[i] && B[i] <= '9')  B_sum += B[i] - '0';
    }
    if(A_sum != B_sum){   //2. (길이는 같고) 자리수의 합이 작은 것 먼저
        return A_sum < B_sum;
    }
    return A < B;   //3. (길이, 자리수의 합 같고) 사전순 정렬
}

int main(){

    int n;  //기타의 개수
    cin >> n;
    arr.assign(n, "");
    for(int i =0; i<n; i++) {   //시리얼 번호
        cin >> arr[i];
    }
    //연산
    sort(arr.begin(), arr.end(), cmp);
    //출력
    for(int i=0; i<n; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}
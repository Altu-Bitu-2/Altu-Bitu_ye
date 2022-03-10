#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;    //카드(1~20) 저장

//카드 역배치
void reverseArr(int a, int b) {
    for (int i = 0; i < (b - a + 1)/2; i++) {
        swap(arr[a + i - 1], arr[b - i - 1]);   // 두 원소 바꾸기
    }
}

int main() {

    int a, b;
    arr.assign(20, 0);
    for (int i = 0; i < 20; i++) {  //1~20 저장
        arr[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;  //구간 입력
        reverseArr(a, b);   //구간 내 역배치
    }
    //출력
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
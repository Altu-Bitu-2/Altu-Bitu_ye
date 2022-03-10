#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, sorted;

void reverseArr(int a, int b) {
    for (int i = 0; i < b - a + 1; i++) {
        sorted[a + i - 1] = arr[b - i - 1];
    }
    for (int i = a - 1; i < b; i++) {
        arr[i] = sorted[i];
    }
}

int main() {

    int a, b;
    arr.assign(20, 0);
    sorted.assign(20, 0);
    for (int i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        reverseArr(a, b);
    }
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
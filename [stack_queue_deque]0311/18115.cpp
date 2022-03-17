#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {

    int n;
    vector<int> v;
    deque<int> dq;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    reverse(v.begin(), v.end());    //벡터를 거꾸로

    for (int i = 0; i < n; i++) {
        switch (v[i]) {
            case 1: //1. 맨 위 카드 1장을 바닥에
                dq.push_back(i+1);
                break;
            case 2: //2. 위에서 두 번째 카드를 바닥에
                int tmp;
                tmp = dq.back();
                dq.pop_back();
                dq.push_back(i+1);
                dq.push_back(tmp);
                break;
            case 3: //3. 제일 밑에 있는 카드를 바닥에
                dq.push_front(i+1);
                break;
        }
    }

    while(!dq.empty()){
        cout << dq[dq.size()-1] << ' ';
        dq.pop_back();
    }

    return 0;
}
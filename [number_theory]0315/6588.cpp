#include <iostream>
#include <cmath>

using namespace std;

bool is_prime[1000001];

void isPrime() {

    //배열 true로 초기화
    for(int i=0; i<1000001; i++){
        is_prime[i] = true;
    }

    //0과 1은 소수가 아니므로 false
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= sqrt(1000000); i++) {
        if (is_prime[i]) {    //i가 소수라면
            for (int j = i * i; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    isPrime();

    int num = 1;

    while (1) {
        cin >> num;
        if(num==0) break;

        bool check = false;

        for (int a = 3; a <= num; a += 2) {
            if (!is_prime[a]) continue;
            //a가 소수이면
            int b = num - a;
            if (!is_prime[b]) continue;
            //b가 소수이면
            cout << num << " = " << a << " + " << b << '\n';
            check = true;
            break;
        }
        //두 홀수 소수의 합으로 나타낼 수 없는 경우
        if (!check) cout << "Goldbach's conjecture is wrong." << '\n';
    }
    return 0;
}

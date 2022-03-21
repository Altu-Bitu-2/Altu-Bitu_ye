#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}

int main(){

    string s;
    cin >> s;

    int n, m, g;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ':'){
            n = stoi(s.substr(0,i));
            m = stoi(s.substr(i+1, s.length()));
        }
    }

    g = gcd(max(n, m), min(n, m));  //n과 m의 최대공약수
    n /= g;
    m /= g;

    cout << n << ':' << m;

    return 0;
}
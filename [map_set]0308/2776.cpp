#include <iostream>
#include <algorithm>
//#include <set>

using namespace std;

int main() {

    int t;  //테스트케이스 개수
    scanf("%d", &t);

    int n, m;   //수첩 1 정수 개수, 수첩 2 정수 개수
    //set<int> note;  //수첩 1
    int *note;  //수첩 1
    int num;    //수첩 2에 저장할 정수

    while (t--) {

        scanf("%d", &n);    //수첩 1 정수 개수 입력
        note = new int[n];

        for (int i = 0; i < n; i++) {   //수첩 1 정수 입력
            scanf("%d", &note[i]);
        }

        sort(note, note + n); //수첩 1 정렬

        scanf("%d", &m);    //수첩 2 정수 개수 입력
        while (m--) {
            scanf("%d", &num);
            printf("%d\n", binary_search(note, note + n, num));
        }

        //시간 초과
        /*
        bool exist;
        while(m--) {
            exist = false;
            scanf("%d", &num);
            for (auto iter:note) {
                if (iter == num) {
                    exist = true;
                    printf("1\n");   //있으면 1 출력
                    note.erase(iter);
                    break;
                }
            }
            if (!exist) printf("0\n");  //없으면 0 출력
        }
         */
    }

    return 0;
}
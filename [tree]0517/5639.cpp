#include <iostream>

using namespace std;

struct node_info {  //노드 정보를 저장하는 구조체
    int data;   //노드의 키
    node_info *left;    //왼쪽 서브트리
    node_info *right;   //오른쪽 서브트리
};

node_info *makeTree(node_info *node, int data) {
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); //동적 할당
        node->data = data;  //입력으로 받은 키 값 저장
        node->left = node->right = NULL;    //서브트리 NULL값으로 초기화
    } else if (node->data > data) { //현재 노드의 키가 이번에 들어갈 노드의 키보다 작다면
        node->left = makeTree(node->left, data);    //왼쪽 서브트리로
    } else if (node->data < data) { //현재 노드의 키가 이번에 들어갈 노드의 키보다 크다면
        node->right = makeTree(node->right, data);  //오른쪽 서브트리로
    }
    return node;    //저장 끝난 후 루트 노드 반환
}

//후위 순회
//왼쪽-오른쪽-루트
void postorder(node_info *node) {
    if (node == NULL) { //NULL을 만나면 종료
        return;
    }
    postorder(node->left);  //왼쪽 서브트리부터 출력
    postorder(node->right); //왼쪽 서브트리 출력 후 오른쪽 서브트리 출력
    cout << node->data << '\n'; //키 값 출력
}

/**
 * 맵과 셋 PPT 중 BST 노드 삽입 과정 참고
 *
 * [이진 검색 트리]
 *
 * 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 * 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 * 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 * 4. 완성한 트리를 후위 순회
 */

int main() {
    int input;  //입력(전위 순회한 결과)

    //입력 & 연산
    node_info *root = NULL; //루트 노드 초기화
    while (cin >> input) {  //입력 개수만큼 반복
        root = makeTree(root, input);   //입력으로 받은 키 값을 갖는 노드 저장
    }

    //출럭
    postorder(root);    //저장된 트리 후위 순회한 결과 출력
    return 0;
}
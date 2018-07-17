#include <iostream>
using namespace std;

class Node {
public:
	char ch;
	Node *prev;
	Node *next;
	Node() {
		ch = NULL;
		prev = NULL;
		next = NULL;
	}
};

const int MAX_INPUT_LENGTH = 1000000;

int main() {
	int testCases = 0;

	cin >> testCases;

	char* tempInput = new char[MAX_INPUT_LENGTH];
	Node** log = new Node*[testCases];
	for (int j = 0; j < testCases; j++) {
		cin >> tempInput;
		log[j] = new Node();
		Node* ptr = log[j];
		for (int i = 0; i < MAX_INPUT_LENGTH && tempInput[i] != NULL; i++) {
			if (tempInput[i] == '-') {
				if (ptr->next) { //뒤에 노드가 있으면
					ptr->next->prev = ptr->prev;
					ptr->prev->next = ptr->next;
					Node* prev = ptr->prev;
					delete ptr;
					ptr = prev;
				}else{
					ptr = ptr->prev;
					delete ptr->next;
					ptr->next = NULL;
				}
			}else if (tempInput[i] == '<') {
				if(ptr->prev)
					ptr = ptr->prev;
			}else if (tempInput[i] == '>') {
				if (ptr->next)
					ptr = ptr->next;
			}else {
				if (ptr->ch != NULL) {//헤드가 아닐 때만 새 노드 생성
					if (ptr->next){//노드 오른쪽에 삽입
						Node* newNode = new Node();
						newNode->prev = ptr;
						newNode->next = ptr->next;
						ptr->next->prev = newNode;
						ptr->next = newNode;
						ptr = newNode;
					}else{//맨끝에 추가
						ptr->next = new Node();
						Node* prev = ptr;
						ptr = ptr->next;
						ptr->prev = prev;
					}
				}
				ptr->ch = tempInput[i];
			}
		}
	}
	
	//출력
	for (int j = 0; j < testCases; j++) {
		Node* node = log[j];
		do {
			cout << node->ch;
		} while (node = node->next);
		cout << endl;
	}

	//메모리 해제
	for (int j = 0; j < testCases; j++) {
		Node* node = log[j];
		Node* next;
		do {
			next = node->next;
			delete node;
		} while (node = next);
		log[j] = NULL;
	}
	return 0;
}
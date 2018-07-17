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
		for (int i = 0; i < MAX_INPUT_LENGTH; i++) {
			Node* prev;
			if (tempInput[i] == '-') {
				prev = ptr->prev->prev;
				delete ptr;
				ptr = prev;
				ptr->next = NULL;
				if (tempInput[i + 1] == NULL) break;
				ptr->next = new Node();
				Node* newPtr = ptr->next;
				newPtr->prev = ptr;
				ptr = newPtr;
			}else if (tempInput[i] == '<' && ptr->prev) {
				if (tempInput[i + 1] == NULL) break;
				ptr->next = new Node();
				Node* newPtr = ptr->next;
				newPtr->prev = ptr;
				ptr = newPtr;
			}else if (tempInput[i] == '>') {

			}else {
				ptr->ch = tempInput[i];
				if (tempInput[i + 1] == NULL) break;
				ptr->next = new Node();
				Node* newPtr = ptr->next;
				newPtr->prev = ptr;
				ptr = newPtr;
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
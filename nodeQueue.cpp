#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Queue {
private:
	struct Node
	{
		T data;
		Node* link;

		Node() {}
		Node(T data) : data(data), link(NULL) {};
	};

	int size;
	Node* head, *tail;

public:
	Queue() {
		head = tail = NULL;
		size = 0;
	}

	bool empty() {
		return size == 0 ? true : false;
	}
	int count() {
		return size;
	}
	void push(T data) {
		Node *node = new Node(data);
		if (size == 0) {
			head = tail = node;
		}
		else {
			tail->link = node;
			tail = node;
		}
		size++;
	}
	T back() {
		if (empty()) return -1;
		else return tail->data;
	}
	void pop() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			cout << head->data << endl;
			Node* node = head;
			head = head->link;

			delete node;
			size--;
		}
	}
	T front() {
		if (empty()) return -1;
		else return head->data;
	}
};

int main() {

	Queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (str == "pop") {
			q.pop();
		}
		else if (str == "size") {
			cout << q.count() << endl;
		}
		else if (str == "empty") {
			cout << q.empty() << endl;
		}
		else if (str == "front") {
			cout << q.front() << endl;
		}
		else if (str == "back") {
			cout << q.back() << endl;
		}
	}

	return 0;
}
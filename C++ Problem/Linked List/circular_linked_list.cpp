#include <iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

int getLength(Node* &h, Node* &t){
	Node* temp = h;
	int count=0;
	while(temp != t){
		count++;
		temp = temp->next;
	}
	return count+1;
}

void InsertAtHead(Node* &h, Node* &t, int data){
	if(!h){
		h = t = new Node(data);
		t->next = h;
		return;
	}
	Node* temp = new Node(data);
	temp->next = h;
	h = temp;
	t->next = h;
}

void InsertAtTail(Node* &h, Node* &t, int data){
	if(!h){
		h = t = new Node(data);
		t->next = h;
		return;
	}
	Node* temp = new Node(data);
	t->next = temp;
	t = temp;
	t->next = h;
}

void InsertAtPos(Node* &h, Node* &t, int data, int pos){
	if(pos<1){
		cout << "Invalid position. Cannot insert" << endl;
		return;
	}
	if(pos == 1){
		InsertAtHead(h, t, data);
		return;
	}
	Node* temp = h;
	int count = 1;
	while(temp && count < pos-1){
		temp = temp->next;
		count++;
	}

	if(!temp || count > getLength(h, t)){
		cout << "Current position is out of bounds" << endl;
		return;
	}

	Node* newNode = new Node(data);
	newNode->next = temp->next;
	temp->next = newNode;
}

void DeleteAtHead(Node* &h, Node* &t){
	if(h == NULL){
		cout << "List is empty. Nothing to delete" << endl;
		return;
	}
	Node* temp = h;
	h = h->next;
	t->next = h;
	delete temp;
}

void DeleteAtTail(Node* &h, Node* &t){
	if(h == NULL){
		cout << "List is empty. Nothing to delete" << endl;
		return;
	}
	Node* temp = h;
	while(temp->next != t)
		temp = temp->next;

	temp->next = h;
	delete t;
	t = temp;
	t->next = h;
}

void DeleteAtPos(Node* &h, Node* &t, int pos){
	if(pos<1){
		cout << "Invalid position, unable to delete" << endl;
		return;
	}
	if(pos == 1){
		if (h == t) {
            delete h;
            h = t = NULL;
        } else {
            DeleteAtHead(h, t);
        }
		return;
	}
	Node* temp = h;
	int count = 1;

	while(temp && count < pos-1){
		temp = temp->next;
		count++;
	}
	
	if(!temp || count >= getLength(h, t)){
		cout << "Position is out of bounds" << endl;
		return;
	}

	Node* deleteNode = temp->next;
	temp->next = deleteNode->next;

    if (deleteNode == t) {
        t = temp;
    }
	delete deleteNode;
}

void print(Node* h){
	if(h == NULL){
		cout << "List is empty. Nothing to delete" << endl;
		return;
	}
	Node* temp = h;
	cout << "Linked List: ";
	while(temp->next != h){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << endl;
}

int main(){
	Node* h = NULL;
	Node* t = NULL;
	InsertAtHead(h, t, 30);
	InsertAtHead(h, t, 20);
	InsertAtHead(h, t, 10);
	InsertAtTail(h, t, 40);
	print(h);
	// InsertAtPos(h, t, 50, 10);
	// print(h);
	// DeleteAtHead(h, t);
	// print(h);
	// DeleteAtTail(h, t);
	// print(h);
	DeleteAtPos(h, t, 10);
	print(h);
	return 0;
}

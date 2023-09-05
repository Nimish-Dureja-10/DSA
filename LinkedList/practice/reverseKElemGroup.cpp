//reverse linked list of k element groups.
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int val) {
    if(head == NULL) {
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }else{
        Node* temp = new Node(val);
        tail -> next = temp;
        tail = temp;
    }
}

void print(Node* &head) {
    if (head == NULL) {
        cout<<"Linked List is empty"<<endl;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void printReversedKGroups(Node* head, int k) {
    Node* current = head;
    Node* prevTail = nullptr;

    while (current != nullptr) {
        int count = 0;
        Node* groupStart = current;
        Node* groupEnd = nullptr;

        // Traverse k elements or until the end of the list
        while (current != nullptr && count < k) {
            Node* nextNode = current->next;
            current->next = groupEnd;
            groupEnd = current;
            current = nextNode;
            count++;
        }

        if (prevTail != nullptr) {
            prevTail->next = groupEnd; // Connect previous group to the current reversed group
        } else {
            head = groupEnd; // Update the head for the first group
        }

        prevTail = groupStart;
    }

    print(head);
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while(temp!=NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    // Node* curr = head;
    // Node* prev = NULL;
    int n,x,k;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        insertAtTail(head,tail,x);
    }
    print(head);
    cout<<getLength(head)<<endl;
    cout<<"Enter K no elements to be reversed ";
    cin>>k;
    // reverseKElem(head,curr,prev,k);
    // reverseKNodes(head,k);
    cout << "Reversed Linked List: ";
    printReversedKGroups(head, k);
    // print(head);
    return 0;
}
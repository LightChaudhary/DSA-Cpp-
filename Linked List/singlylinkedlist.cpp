#include<iostream>
using namespace std;

class LinkedList{
    struct Node{
        int data;
        Node* next;
    };

    Node* head;

    Node* createNode(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        return newNode;
    }

    public: 
        LinkedList(){
            head = NULL;
        }

        void insertBegin(int x){
            Node* newNode = createNode(x);
            newNode->next = head;
            head = newNode;
        }

        void insertEnd(int x){
            Node* newNode = createNode(x);
            
            if(head == NULL){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void insertAtPos(int x, int pos){
            Node* newNode = createNode(x);
            Node* temp = head;
            
            for(int i = 1; i < pos -1; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void deleteBegin(){
            if(head == NULL) return;
            
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void deleteEnd(){
            if(head == NULL) return;

            if(head->next == NULL){
                delete head;
                head = NULL;
                return;
            }

            Node* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }

        void deleteAtPos(int pos){
            Node* temp = head;

            for(int i = 1; i< pos -1; i++){
                temp = temp->next;
            }

            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp ->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
};
int main(){
    LinkedList list;
    
    list.insertBegin(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertAtPos(15, 2);

    list.display();

    list.deleteBegin();
    list.deleteEnd();
    list.deleteAtPos(2);
    
    list.display();
    return 0;
}
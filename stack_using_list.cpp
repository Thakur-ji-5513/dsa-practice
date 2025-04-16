#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* top;
    Node* mintop;
    
public:
    Stack() {
        top = NULL;
        mintop=NULL;
    }

    void push(int val) {
            Node* newNode = new Node(val);
            if(mintop==NULL){
                Node* newnode2= new Node(val);
                newnode2->next=mintop;
                mintop=newnode2;
                newNode->next = top;
                top = newNode;
            }
            else{
                newNode->next = top;
                top = newNode;
                if(mintop->data>val){
                    Node* newnode2= new Node(val);
                    newnode2->next=mintop;
                    mintop=newnode2;
                }
                else{
                    int k= mintop->data;
                    Node* newnode2= new Node(k);
                    newnode2->next=mintop;
                    mintop=newnode2;
                }
            }
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        Node* temp2= mintop;
        top = top->next;
        mintop=mintop->next;
        delete temp;
        delete temp2;
    }

    int peek() {
        if (top == NULL) return -1;
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
    int getmin(){
        return mintop->data;
    }
};
int main(){
    Stack wass;
    wass.push(12);
    wass.push(17);
    wass.push(12);
    wass.push(13);
    wass.pop();
    wass.push(1);
    cout<<wass.getmin();
}
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    Node* head;
    Node* tail; 
    public:
    list(){
        head=tail=NULL;
    }
    
    void add_front(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    void print_lst(){
        Node* temp=head;
        if(head&&tail&&NULL){
            cout<<"no elements to display"<<endl;
        }
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
};
int main() {
    list ll;
    ll.add_front(1);
    ll.add_front(4);
    ll.add_front(3);
    ll.print_lst();
    
    return 0;
}
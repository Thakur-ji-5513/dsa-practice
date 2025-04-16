#include <iostream>
using namespace std;
 class cq{
     public:
     int* arr;
     int size;
     int front;
     int rear;
     cq(int a){
         size=a;
         arr=new int[size];
         front=rear=-1;
     }
     bool is_full(){
         if((front==(rear+1)%size)){
             return true;
         }
         return false;
     }
     bool is_empty(){
         if(front==-1){
             return true;
         }
         return false;
     }
     void enqueue(int val){
         if(is_full()){
             cout<<"the queue is full!"<<endl;
             return;
         }
         else if(is_empty()){
             rear=front=0;
             arr[0]=val;
             cout<<"done!";
             return;
         }
         else{
             rear=(rear+1)%size;
             arr[rear]=val;
             cout<<"done!";
             return;
         }
     }
     void dequeue(){
         if(is_empty()){
             cout<<"the queue is already empty!"<<endl;
             return;
         }
         else if(front==rear){
             front=rear=-1;
             return;
         }
         else{
             front=(front+1)%size;
             return;
         }
     }
     int peak(){
         return arr[front];
     }
 };
int main() {
    cq a(5);
    a.enqueue(12);
    a.enqueue(13);
    a.enqueue(14);
    a.enqueue(15);
    a.dequeue();
    cout<<a.peak();
    return 0;
}
#include <iostream>
#include<cstring>
using namespace std;
class stack{
    int top;
    int size;
    char* arr;
    public:
    stack(int len){
        size=len;
        arr=new char[size];
        top=-1;
    }
    void push(char value){
        if(top==(size-1)){
            cout<<"unexpected error!"<<endl;
            return;
        }
        top++;
        arr[top]=value;
    }
    bool pop(){
        if(top==-1){
            cout<<"invalid expression"<<endl;
            return false;
        }
        else{
            top--;
            return true;
        }
    }
    bool is_empty(){
        return top==-1;
    }
};
bool check_par(char array[], int size){
    stack Stack(size);
    for(int i=0;i<size;i++){
        if(i=='('){
            Stack.push(i);
        }
        else if(i == ')') {
            if (!Stack.pop()) return false;
            }
    }
    return Stack.is_empty();
};
int main() {
    char array[]="3+2+(4-1)";
    int size = strlen(array);
    cout << check_par(array, size);
}
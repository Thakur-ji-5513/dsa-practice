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


//second code
// #include <iostream>
// #include<stack>
// #include<cstring>
// using namespace std;
// bool check_par(const char* str);
// int main() {
//     const char* str="3+2(2-3(5+7))";
//     cout<<check_par(str)<<endl;
//     return 0;

// }
// bool check_par(const char* str){
//     stack<char> stk;
//     for(int i=0;str[i]!='\0';i++){
//         if(str[i]=='('){
//             stk.push(str[i]);
//         }
//         else if(str[i]==')'){
//             if(stk.empty())return false;
//             stk.pop();
//         }
//     }
//     return stk.empty();
// };
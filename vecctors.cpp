#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    int len;
    cout<<"Enter the length of the vector: ";
    cin>>len;
    for(int i=0;i<len;i++){
        int x;
        cout<<"Enter the element: ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"The elements of the vector are: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    while (v.size()>0)
    {
        cout<<"we just popped:"<<v.back()<<endl;
        v.pop_back();
    }
    
    
    
}
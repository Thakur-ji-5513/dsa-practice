#include<iostream>
#include<map>
#include<map>
using namespace std;

map<int,int> freqi(int arr[],int size){
    map<int,int> freq;
    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]+=1;
    }
    return freq;

}

int main(){
int arr[]={1,1,1,3,4,5,6,5,4,7,8,9,7,8,0,4,5,6};
int n=18;
map<int,int> asnwer= freqi(arr,n);
for(auto x:asnwer){
    cout<<"number: "<<x.first<<" has: "<<x.second<<" occurance"<<endl;
}

return 0;
}
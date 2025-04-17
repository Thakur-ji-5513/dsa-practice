#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    int arr[]={3,4,2,5,3,6,7,8,56,3466,345,54,56};
    int size=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+size);
    for(auto x:arr){
        cout<<x<<endl;
    }
    return 0;
}
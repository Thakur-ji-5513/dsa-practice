#include <vector>
#include <iostream>
using namespace std;
int partition(vector <int> &arr,int str,int end){
    int index=str-1;
    int pivot=arr[end];
    for(int i=str;i<end;i++){
        if(arr[i]<=pivot){
            index++;
            swap(arr[i],arr[index]);
        }
    }
    index++;
    swap(arr[index],arr[end]);
    return index;
}
void quicksort(vector <int> &arr,int str,int end){
    if(str<end){
        int ind=partition(arr,str,end);
        
        quicksort(arr,str,ind-1);
        quicksort(arr,ind+1,end);
    }
}

int main() {
    vector <int>arr={2,5,3,1,7,4,9};
    quicksort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
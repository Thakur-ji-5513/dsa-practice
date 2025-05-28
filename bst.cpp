#include<iostream>
#include<vector>
using namespace std;

class minheap{
    int size;
    int capacity;
    vector<int> heap;

    int parent(int i){
        return (i-1)/2;
    }

    int right_child(int i){
        return ((2*i)+2);
    }

    int left_child(int i){
        return ((2*i)+1);
    }
    public:

    minheap(int capacity){
        size=0;
        this->capacity=capacity;
        heap.resize(capacity);
    }

    void minheap::insert(int k){
        if (size==capacity)
        {
            cout<<"the size is full"<<endl;
            return;
        }

        size++;
        int i= size-1;
        heap[i]=k;
        

    }

};

int main(){

    return 0;
}
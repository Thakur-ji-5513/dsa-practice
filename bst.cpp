#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class minheap{
    int size;
    int capacity;
    vector<int> heap;

    int parent(int i){
        return (i-1)/2;
    };
    int right_child(int i){
        return (2*i)+2;
    };
    int left_child(int i){
        return (2*i)+1;
    };

    public:

    minheap(int capacity){
        size=0;
        this->capacity=capacity;
        heap.resize(capacity);
    }
    //inserting key to heap
    void insert(int k){
        if (size==capacity)
        {
            cout<<"the size is full"<<endl;
            return;
        }

        size++;
        int i= size-1;
        heap[i]=k;

        while (i!=0 && heap[i]<heap[parent(i)])
        {
            swap(heap[i],heap[parent(i)]);
            i=parent(i);
        }
        return;
    }
    //recursive fnc to maintain the heap's heappness :)
    void heapify(int i){
        int l=left_child(i);
        int r=right_child(i);
        int smallest=i;

        if ((l<size) && (heap[l]<heap[smallest]))
        {
            smallest=l;
        }
        if ((r<size) && (heap[r]<heap[smallest]))
        {
            smallest=r;
        }

        if (smallest!=i)
        {
            swap(heap[smallest],heap[i]);
            heapify(smallest);
        }
        
    }

    int extractmin(){
        if (size==0)
        {
            cout<<"the heap is empty :)"<<endl;
            return -1;
        }
        else if (size==1)
        {
            size--;
            return heap[0];
        }
        else{
            int root=heap[0];

            heap[0]=heap[size-1];
            size--;
            heapify(0);

            return root;
        }
        
    }
    void print_heap(){
        int value=1;
        int power=0;
        for (int i = 0; i < size; i++)
        {
            if (value==i)
            {
                cout<<endl;
                value += (1 << power); // Left shift: 1 * 2^power
                power+=1;
            }
            cout<<heap[i]<<" ";  
        }
        
    }

};


int main(){
    int N = 15;

    // Declare a heap with space for 10 elements
    minheap heap(N);

    // Insert N random numbers
    for(int i = 0; i < N; i++){
        cout << "Inserting element " << i+1 << endl;
        heap.insert(rand() % 100);
        heap.print_heap();
        cout << endl;
    }

    return 0;
}
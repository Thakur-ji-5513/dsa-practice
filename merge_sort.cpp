#include <iostream>
#include <vector>
using namespace std;

vector <int> merge(const vector<int> & left,const vector<int> & right ){
    vector<int> sorted_arr;
    int i=0,j=0;
    while (i<left.size() && j<right.size()) 
    {
        if (left[i]<=right[j])
        {
            sorted_arr.push_back(left[i]);
            i++;
        }
        else{
            sorted_arr.push_back(right[j]);
            j++;
        }
        
    }
    while (j<right.size())      
    {
        sorted_arr.push_back(right[j]);
        j++;
    }
    while (i<left.size())
    {
        sorted_arr.push_back(left[i]);
        i++;
    }
    return sorted_arr;
}

vector <int> merge_sort(const vector <int> &arr){
    if (arr.size()<=1)
    {
        return arr;
    }

    int mid=arr.size()/2;
    vector<int> left_half(arr.begin(),arr.begin()+mid);
    vector<int> right_half(arr.begin()+mid,arr.end());

    return merge(merge_sort(left_half),merge_sort(right_half));
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    // Call merge_sort and store the sorted result
    vector<int> sorted_arr = merge_sort(arr);

    // Print the sorted array
    for (int num : sorted_arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

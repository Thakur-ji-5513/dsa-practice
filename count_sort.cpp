#include <iostream>
using namespace std;

void count_sort(int arr[], int n);

int main()
{
    int arr[] = {1, 5, 4, 7, 6, 5, 4, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    count_sort(arr, n);
    for (int i = 0; i < n-1; i++)
    {
        cout << arr[i]<<",";
    }

    return 0;
}

void count_sort(int arr[], int n)
{
    int maxval = 0;
    for (int i = 0; i < n; i++)
    {
        maxval = max(arr[i], maxval);
    }
    int *count = new int[maxval + 1]();
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i < maxval; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    int *final = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        final[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = final[i];
    }
    delete[] final;
    delete[] count;
}
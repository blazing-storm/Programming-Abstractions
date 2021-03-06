#include <climits>

int findSecondLargest(int *arr, int n)
{
    int l = INT_MIN, sl = INT_MIN;

    for(int i=0; i<n; i++) {
        if(arr[i] > l) {
            sl = l;
            l = arr[i];
        }
        else if(arr[i] != l && arr[i] > sl) {
            sl = arr[i];
        }
    }
    
    return sl;
}
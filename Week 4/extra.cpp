int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    int count=0;
    sort(arr,arr+n);
    
    for(int i=0;i<n-2;i++){
        
        int l=i+1;int h=n-1;
        
        while(l<h){
            
            if(arr[i]+arr[l]+arr[h]==num){
                for(int x=h; x>l && arr[x]==arr[h];x--){
                    count++;   
                }
                l++;
            }
            else if(arr[i]+arr[l]+arr[h]<num){
                l++;
            }
            else h--;
        }
    }
    return count;
}
int pairSum(int *arr, int start, int end, int target) {


   int finalCount = 0;
	while (start < end) {
		
		if (arr[start] + arr[end] > target) {
			end--;
		}
		
		else if (arr[start] + arr[end] < target) {
			start++;
		}
			else {
			int startIndex = start;
			int endIndex = end;
		 	if (arr[start] == arr[end]) {
				int betweenIndexes = (end - start) + 1;
				finalCount += (betweenIndexes * (betweenIndexes - 1)) / 2;
				return finalCount;
			}
		
			int newStart = start + 1;
			int newEnd = end - 1;

			while (newStart <= newEnd && arr[newStart] == arr[start])
				newStart++;
			while (newStart <= newEnd && arr[newEnd] == arr[end])
				newEnd--;

			int eleFromStart = newStart - start;
			int eleFromEnd = end - newEnd;

			finalCount += (eleFromStart * eleFromEnd);

			start = newStart;
			end = newEnd;
		}
	}

	return finalCount;
}

int tripletSum(int *arr, int n, int num) {
	if (n == 0)
		return 0;

	sort(arr, arr + n);

	int finalCount = 0;

	for (int i = 0; i < n; i++) {
		int pairSumFor = num - arr[i];
		finalCount +=  pairSum(arr, i + 1, n - 1, pairSumFor);
	}

	return finalCount;
}
/*#include<unordered_map>
using namespace std;

int tripletSum(int *arr, int n, int x) {
    int ctr = 0;
    for(int i=0; i<n; i++) {
        
        unordered_map<int, int> m;
 
    	// Store counts of all elements in map m
    	for (int j = i+1; j < n; j++)
        	m[arr[j]]++;
 
    	int twice_count = 0;
 
    	// iterate through each element and increment the
    	// count (Notice that every pair is counted twice)
    	for (int i = 0; i < n; i++) {
        	twice_count += m[x - arr[i]];
 
        	// if (arr[i], arr[i]) pair satisfies the condition,
        	// then we need to ensure that the count is
        	// decreased by one such that the (arr[i], arr[i])
        	// pair is not considered
        	if (x - arr[i] == arr[i])
            	twice_count--;
    	}
 
    	// return the half of twice_count
    	return twice_count / 2;
    }
}*/
// Sorting and Two Pointer Technique
/*#include<algorithm>

int tripletSum(int *arr, int n, int x)
{
	if(n <= 2)
        return 0;
    
    sort(arr, arr+n);
    int ctr = 0;
    
    for(int i=0; i<n; i++){
             
    	/*if(i>0 && arr[i] == arr[i-1])  // avoid duplicate triplets count
        	continue;
             
        int num = arr[i];
        int target = x - num;
             
        for(int l=i+1, r=n-1; l<r; ) {
            if(arr[l] + arr[r] > target)                    
                r--;
                 
            else if (arr[l] + arr[r] < target)
                l++;
                 
            else {
                // arr[l] + arr[r] == target
                ctr++;
 
                // skip duplicates
                while( l<n-1 && arr[l] == arr[l+1]) l++;
                while( r>0 && arr[r] == arr[r-1]) r--;
                                             
                // l++;
                r--;                   
                     
            }                
        }                                     
    }
    
    return ctr;
}*/
/*
#include <bits/stdc++.h>
using namespace std;
 
// function to print triplets with given sum
int tripletSum(int arr[], int n, int sum)
{
    int ctr = 0;
    for (int i = 0; i < n - 1; i++) {
        // Find all pairs with sum equals to
        // "sum-arr[i]"
        unordered_set<int> s;
        for (int j = i + 1; j < n; j++) {
            int x = sum - (arr[i] + arr[j]);
            if (s.find(x) != s.end()) {
                ctr++;
                // printf("%d %d %d\n", x, arr[i], arr[j]);
            }
            else
                s.insert(arr[j]);
        }
    }
    return ctr;
} */
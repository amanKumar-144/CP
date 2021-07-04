// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int pt1=l;int pt2=m+1;
        int n=r-l+1;

        int newArr[n];int newArrPtr=0;
        while(pt1<=m && pt2<=r)
        {
            if(arr[pt1]>arr[pt2])
            {
               newArr[newArrPtr]=arr[pt2];
               newArrPtr++;
               pt2++;
            }
            else if(arr[pt1]<=arr[pt2])
            {
               newArr[newArrPtr]=arr[pt1];
               newArrPtr++;
               pt1++; 
            }
        }
        
        while(pt1<=m){
            newArr[newArrPtr]=arr[pt1];
            pt1++;
            newArrPtr++;
        }
        
        while(pt2<=r){
            newArr[newArrPtr]=arr[pt2];
            pt2++;
            newArrPtr++;
        }
         
        newArrPtr=0;
        for(int i=l;i<=r;i++){
            arr[i]=newArr[newArrPtr];
            newArrPtr++;
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)return ;
        
        int middle=l+(r-l)/2;
        if(l<=middle)mergeSort(arr,l,middle);
        if(middle+1<=r)mergeSort(arr,middle+1,r);
        
        merge(arr,l,middle,r);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
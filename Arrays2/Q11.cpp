// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

const int N=1e5+1;
int counting[N];
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int maxVal=0;
      for(int i=0;i<N;i++)maxVal=max(maxVal,arr[i]);
      
      for(int i=0;i<N;i++)counting[arr[i]]=1;
      int ans=0;int temp=0;
      for(int i=1;i<=maxVal;i++)
      {
          if(counting[i]==1)temp++;
          else 
          {
              ans=max(ans,temp);
              temp=0;
          }
          
          counting[i]=0;
      }
      ans=max(ans,temp);
      
      return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends
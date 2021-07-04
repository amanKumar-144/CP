// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

int calc(int arr[],int n,int val)
{
    int ans=0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>val)k--;
            else{
                ans+=(k-j);
                j++;
            }
        }
    }
    return ans;
}
class Solution {
  public:
    int countTriplets(int Arr[], int N, int L, int R) {
        int ans=0;
        ans=calc(Arr,N,R)-calc(Arr,N,L-1);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends
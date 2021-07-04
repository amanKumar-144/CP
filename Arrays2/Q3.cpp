#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> increment(vector<int> a ,int N) {
        // code here
        int quotient=(a[N-1]+1)/10;
        a[N-1]=(a[N-1]+1)%10;
        for(int i=N-2;i>=0;i--)
        {
            a[i]=a[i]+quotient;
            quotient=a[i]/10;
            a[i]=a[i]%10;
        }
        vector<int>ans;
        if(quotient!=0)
        {
            ans.push_back(quotient);
        }
        for(int i=0;i<N;i++)ans.push_back(a[i]);
        return ans;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
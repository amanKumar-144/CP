// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};

int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
#define vii vector<int>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int maxChainLen(struct val p[],int n)
{
//Your code here
    vector<pii>a;
    for(int i=0;i<n;i++)
    {
        int x=p[i].first;
        int y=p[i].second;
        a.pb(mp(x,y));
    }
    sort(a.begin(),a.end());
    int dp[n];
    for(int i=0;i<n;i++)dp[i]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j].se<a[i].fi)
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    return dp[n-1];
}
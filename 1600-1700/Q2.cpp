#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define int long long
#define vii vector<int>
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
vector<int>matrix[10];
int32_t main()
{
    FAST;
    int n=5;
    int row=0;int col=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;cin>>x;
            matrix[i].pb(x);
            if(x==1)
            {
                row=i;col=j;
            }
        }
    }
    int ans=abs(n/2-row)+abs(n/2-col);
    cout<<ans<<endl;
    return 0;
}
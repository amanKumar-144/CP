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
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    vii a;
    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        a.pb(x);
    }
    sort(a.begin(),a.end());
    
    int answer=-1;
    for(int i=1000;i>=0;i--)
    {
        int diff=i;
        for(int j=0;j<m;j++)
        {
            for(int k=j+1;k<m;k++)
            {
                if(a[k]-a[j]==diff && k-j+1>=n)
                {
                    answer=diff;
                }
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}
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
    }
    cout<<endl;
}
const int N=201;
int grid[N][N];//Image available,post available//n,x

int32_t main()
{
    FAST;
    int n,k,x;cin>>n>>k>>x;
    vii a;a.pb(-1);//Dummy Value
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;a.pb(x);
    }
    //pre-processing;
    for(int i=1;i<=k;i++)
    {
        grid[i][1]=a[i];
    }
    for(int j=2;j<=x;j++)
    {   
        for(int i=1;i<=n;i++)
        {
            for(int p=max(1ll,i-k);p<i;p++)
            {
                if(grid[p][j-1]>0)
                {
                    grid[i][j]=max(grid[i][j],a[i]+grid[p][j-1]);
                }
            }
        }
    }
    cout<<"The matrix is "<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            cout<<grid[i][j]<<" ";
        }cout<<endl;
    }
    int ans=0;
    for(int i=n-k+1;i<=n;i++){
        ans=max(ans,grid[i][x]);
    }
    if(ans==0)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
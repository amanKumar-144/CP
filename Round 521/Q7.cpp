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
const int N=5005;
int grid[N][N];//Image available,post available//n,x
deque<int>dq;

int32_t main()
{
    FAST;
    int n,k,x;cin>>n>>k>>x;
    vii a;
    a.pb(-1);//Dummy Value
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
        int top=1;
        for(int i=1;i<=n;i++)
        {
            //No popping always
            if(i==1)dq.push_front(grid[i][j-1]);

            else if(i<=k)
            {
                int maxi=dq.back();
                if(maxi>0)grid[i][j]=maxi+a[i];
                while(dq.size()>0 && dq.front()<=grid[i][j-1])dq.pop_front();
                dq.push_front(grid[i][j-1]);
            }
            else if(i>k)
            {
                int maxi=dq.back();
                if(maxi>0)grid[i][j]=maxi+a[i];
                if(maxi==grid[top][j-1]){
                    dq.pop_back();
                    int maxi=dq.back();
                }
                top++;
                while(dq.size()>0 && dq.front()<=grid[i][j-1])dq.pop_front();
                dq.push_front(grid[i][j-1]);
            }
        }
        dq.clear();
    }
    int ans=0;
    for(int i=n-k+1;i<=n;i++){
        ans=max(ans,grid[i][x]);
    }
    if(ans==0)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
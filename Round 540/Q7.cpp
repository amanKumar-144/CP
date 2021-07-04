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
const int N=300001;
vector<int>graph[N];
vector<bool>check(N,false);
int storeDP[N][3];
vii a;
vector<int>closeToOne(N,0);
vector<pii>storeEdges;

void dfs(int start)
{
    check[start]=true;
    storeDP[start][a[start-1]]+=1;
    for(int i=0;i<graph[start].size();i++)
    {
        int v=graph[start][i];
        if(check[v]==false)
        {
            closeToOne[v]=closeToOne[start]+1;
            dfs(v);
            storeDP[start][0]+=storeDP[v][0];
            storeDP[start][1]+=storeDP[v][1];
            storeDP[start][2]+=storeDP[v][2];
        }
    }
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    for(int i=1;i<=n-1;i++){
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
        storeEdges.pb(mp(x,y));
    }
    closeToOne[1]=0;
    dfs(1);

    int answer=0;
    for(int i=0;i<storeEdges.size();i++)
    {
        int v1=storeEdges[i].fi;
        int v2=storeEdges[i].se;
        int val1=closeToOne[v1];
        int val2=closeToOne[v2];
        if(val2>val1)swap(v1,v2);

        if(storeDP[v1][1]==0 && storeDP[1][2]==storeDP[v1][2])     {answer++;}
        else if(storeDP[v1][2]==0 && storeDP[1][1]==storeDP[v1][1]){answer++;}
        
    }
    cout<<answer<<endl;
    return 0;
}
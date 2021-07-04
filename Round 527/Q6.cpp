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
const int N=200001;
vector<pii>graph[N]; //(Vertex,Weights)
vector<int>a(N,0);

vector<bool>checkDistSum(N,false);
vector<bool>checkSum(N,false);
vector<int>parent(N,-1);
vector<int>subTreeSum(N,-1);
vector<int>distSum(N,0);

void print(vii &a,int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}

int dfsDistSum(int start)
{
    checkDistSum[start]=true;
    for(int i=0;i<graph[start].size();i++)
    {
        int child=graph[start][i].fi;
        if(checkDistSum[child]==false)
        {
            dfsDistSum(child);
            distSum[start]=distSum[start]+a[child]+2*distSum[child];
            graph[start][i].se=distSum[child]+a[child];
        }
    }
}
int dfsSum(int start)
{
    int sum=a[start];
    checkSum[start]=true;
    for(int i=0;i<graph[start].size();i++)
    {
        int child=graph[start][i].fi;
        if(checkSum[child]==false)
        {
            parent[child]=start;
            int subTSum=dfsSum(child);
            subTreeSum[child]=subTSum;
            sum+=subTSum;
        }
    }
    if(start==1)subTreeSum[start]=sum;
    return sum;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        a[i]=x;
    }
    for(int i=1;i<=n-1;i++)
    {
        int x,y;cin>>x>>y;
        graph[x].pb(mp(y,0));
        graph[y].pb(mp(x,0));
    }
    parent[1]=1;
    subTreeSum[1]=dfsSum(1);
    cout<<"The subtree sum is "<<endl;
    print(subTreeSum,n);

    dfsDistSum(1);
    cout<<"The dist sum is "<<endl;
    print(distSum,n);
    return 0;
}
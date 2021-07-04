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
//Meet in the middle technique
const int N=21;
map<int,int>countPaths[N][N];//Stores XOR,count for x,y cell
int grid[N][N];
int answer=0;
int n,m,k;

void calculate1(int x,int y,int moves,int value)
{
    value=value^(grid[x][y]);
    if(moves==0)//Store the result
    {
        auto itr=countPaths[x][y].find(value);
        if(itr==countPaths[x][y].end())countPaths[x][y].ins(mp(value,1));
        else itr->se++;
    }
    else if(moves>0)
    {
        if(x+1<n)
        {
            calculate1(x+1,y,moves-1,value);
        }
        if(y+1<m)
        {
            calculate1(x,y+1,moves-1,value);
        }
    }
}
void calculate2(int x,int y,int moves,int value)
{
    if(moves==0)
    {
        int requiredXOR=k^value;

        auto itr=countPaths[x][y].find(requiredXOR);
        if(itr!=countPaths[x][y].end())
            answer+=itr->se;   
    }
    else if(moves>0)
    {
        if(x-1>=0)
        {
            calculate2(x-1,y,moves-1,value^grid[x][y]);
        }
        if(y-1>=0)
        {
            calculate2(x,y-1,moves-1,value^grid[x][y]);
        }
    }
}
int32_t main()
{
    FAST;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;cin>>x;
            grid[i][j]=x;
        }
    }
    int mid=(n+m-2)/2;
    int leftMoves=n+m-2-mid;

   
    calculate1(0,0,mid,0);
    calculate2(n-1,m-1,leftMoves,0);
    cout<<answer<<endl;
    return 0;
}
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
const int N=51;
vector<vector<int>>graph;
vector<vector<bool>>check;
vector<vector<pii>>parent;
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
int n,m;
int valid=0;
bool isValid(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m)return true;
    else return false;
}
void dfs(int i,int j)
{
    check[i][j]=true;
    if(graph[i][j]==0)return;

    for(int k=0;k<4;k++)
    {
        int newCoordX=i+X[k];
        int newCoordY=j+Y[k];
        if(isValid(newCoordX,newCoordY) && graph[i][j]==graph[newCoordX][newCoordY] && check[newCoordX][newCoordY]==false)
        {
            parent[newCoordX][newCoordY]=mp(i,j);
            dfs(newCoordX,newCoordY);
        }
        else if(isValid(newCoordX,newCoordY) && graph[i][j]==graph[newCoordX][newCoordY] && check[newCoordX][newCoordY]==true)
        {
            
            if(parent[i][j]!=mp(newCoordX,newCoordY))valid=1;
        }
    }
}
int32_t main()
{
    FAST;
    
    cin>>n>>m;
    vector<string>store;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        store.pb(s);
    }
    //Initialize 
    for(int i=0;i<n;i++){
        vector<bool>temp;
        vector<int>hello;
        vector<pii>hello2;
        for(int j=0;j<m;j++)
        {
            temp.pb(false);
            hello.pb(0);
            hello2.pb(mp(i,j));
        }
        check.pb(temp);
        graph.pb(hello);
        parent.pb(hello2);
    }

    //Construct Graph
    for(int j=1;j<m;j++)
    {
        int i=0;
        if(store[i][j]==store[i][j-1]){
                graph[i][j]=1+store[i][j];
                graph[i][j-1]=1+store[i][j-1];
            }
    }
    for(int j=1;j<n;j++)
    {
        if(store[j][0]==store[j-1][0]){
            graph[j][0]=1+store[j][0];
            graph[j-1][0]=1+store[j][0];
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(store[i][j]==store[i-1][j]){
                graph[i][j]=1+store[i][j];
                graph[i-1][j]=1+store[i][j];
            }
            if(store[i][j]==store[i][j-1]){
                graph[i][j]=1+store[i][j];
                graph[i][j-1]=1+store[i][j-1];
            }
        }
    }
    

   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(check[i][j]==false)
            {
                dfs(i,j);
            }
        }
    }

    if(valid==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
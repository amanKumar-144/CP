// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
const int N=1001;
bool check[N][N];
int dist[N][N];

void bfs(vector<pii>&a,int n,int m,vector<vii>&hosp)
{
    deque<pii>dq;
    for(int i=0;i<a.size();i++){
        dq.pb(a[i]);
        check[a[i].fi][a[i].se]=true;
        dist[a[i].fi][a[i].se]=0;
    }
    while(dq.size()>0)
    {
        pii top=dq.front();
        dq.pop_front();
        int d=dist[top.fi][top.se];
        for(int i=0;i<4;i++){
            int newX=top.fi+X[i];
            int newY=top.se+Y[i];
            if(newX>=0 && newY>=0 && newX<n && newY<m && hosp[newX][newY]==1 && check[newX][newY]==false)
            {
                check[newX][newY]=true;
                dist[newX][newY]=1+d;
                dq.pb(mp(newX,newY));
            }
            else if(newX>=0 && newY>=0 && newX<n && newY<m && hosp[newX][newY]==1 && check[newX][newY]==true)
            {
                if(1+d<dist[newX][newY]){
                    dist[newX][newY]=1+d;
                    dq.pb(mp(newX,newY));
                }
            }
        }
    }
}


class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int n=hospital.size();
        int m=hospital[0].size();
        vector<pii>start;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(hospital[i][j]==2)start.pb(mp(i,j));
                check[i][j]=false;
                dist[i][j]=0;
            }
        }
        bfs(start,n,m,hospital);
        int valid=1;int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(hospital[i][j]==1)
                {
                    if(dist[i][j]==0)valid=0;
                    else ans=max(ans,dist[i][j]);
                }
            }
        }
        if(valid==0)ans=-1;
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
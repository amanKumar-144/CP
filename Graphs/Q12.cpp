// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

int moveX[4]={0,1,0,-1};
int moveY[4]={-1,0,1,0};
const int N=501;
bool check[N][N];

bool isValid(int i,int j,int n)
{
    if(i>=0 && j>=0 && i<n && j<n)return true;
    else return false;
}
void dfs(pii start,int n,vector<vector<int>>& grid)
{
    int x=start.fi;
    int y=start.se;
    check[x][y]=true;

    for(int i=0;i<4;i++)
    {
        int newX=x+moveX[i];
        int newY=y+moveY[i];
        if(isValid(newX,newY,n) && (grid[newX][newY]==3 || grid[newX][newY]==2) && check[newX][newY]==false)
        {
            dfs(mp(newX,newY),n,grid);
        }
    }
}


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        pii start;
        pii end;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                check[i][j]=false;
                if(grid[i][j]==1)start=mp(i,j);
                else if(grid[i][j]==2)end=mp(i,j);
            }
        }
        dfs(start,n,grid);
        if(check[end.fi][end.se]==true)return true;
        else return false;
    }
};




// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
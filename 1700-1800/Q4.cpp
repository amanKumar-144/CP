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
#define endl "\n"
using namespace std;
int32_t main()
{
    FAST;
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    int maxLength=-1;
    //ax+by+cz=n
    for(int x=0;x<=4000;x++)
    {
        for(int y=0;y<=4000;y++)
        {
            int val=a*x+b*y;
            int z=(n-val)/c;
            if(a*x+b*y+c*z==n && z>=0)
            {
                maxLength=max(maxLength,x+y+z);
            }
        }
    }
    cout<<maxLength<<endl;
    return 0;
}
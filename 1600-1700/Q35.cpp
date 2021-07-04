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
const int N=1e6+1;
int rankArray[N];
const int M=4001;
int dp[M][M];
int indexArray[M][M];

int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    set<int>s;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
        s.ins(x);
    }
    int val=0;
    for(auto it=s.begin();it!=s.end();it++)
    {
        rankArray[*it]=val;
        val++;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=rankArray[a[i]];
    }

    memset(indexArray,sizeof(indexArray),-1);
    memset(dp,sizeof(dp),0);
   }
    }
    return 0;
}
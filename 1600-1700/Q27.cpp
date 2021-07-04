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
int32_t main()
{
    FAST;
    int n,a,b,c;cin>>n>>a>>b>>c;
    int finalAns=0;
    for(int x=0;x<=4000;x++)
    {
        for(int y=0;y<=4000;y++)
        {
            
            int total=a*x+b*y;
            int diff=n-total;
            if(diff>=0 && diff%c==0)
                finalAns=max(finalAns,x+y+diff/c);
        }
    }
    cout<<finalAns<<endl;
    return 0;
}
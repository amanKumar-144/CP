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
    int valid=0;
    int n,m;cin>>n>>m;

    int p=1;
    int x,y;
    int finalLength=LLONG_MAX;

    for(int mul=m;mul<=n;mul=m*p)
    {
        int length=mul;
        for(int i=0;i<=n;i++)
        {
            y=i;
            int diff=length-i;
            x=diff;
            if(2*x+y==n && x>=0 && y>=0)
            {
                finalLength=min(finalLength,length);
                valid=1;
                
            }
        }
        p++;
    }
    if(finalLength==LLONG_MAX)finalLength=-1;

    cout<<finalLength<<endl;
    return 0;
}
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
    int n;cin>>n;
    vii a;
    for(int i=1;i<=n*n;i++)
        a.pb(i);

    int start=0;
    int end=a.size()-1;
    vector<int>answer[n];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j=j+2)
        {
            answer[i].pb(a[start]);
            answer[i].pb(a[end]);
            start++;end--;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<answer[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
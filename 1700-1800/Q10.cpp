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
const int N=100005;

vii a(N,0);
vector<pair<pii,int>>query(N,mp(mp(0,0),0));
vii storeOperations(N,0);
vii answer(N,0);
int32_t main()
{
    FAST;
    int n,m,k;cin>>n>>m>>k;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    for(int i=1;i<=m;i++){
        int l,r,d;cin>>l>>r>>d;
        query[i].fi.fi=l;
        query[i].fi.se=r;
        query[i].se=d;
    }

    for(int i=1;i<=k;i++){
        int start,end;
        cin>>start>>end;
        storeOperations[start]++;
        storeOperations[end+1]--;
    }

    for(int i=2;i<=m;i++)storeOperations[i]+=storeOperations[i-1];

    for(int i=1;i<=m;i++){

        int s=query[i].fi.fi;
        int e=query[i].fi.se;
        int val=query[i].se;

        answer[s]+=val*storeOperations[i];
        answer[e+1]-=val*storeOperations[i];
    }

    for(int i=2;i<=n;i++)answer[i]+=answer[i-1];
    for(int i=1;i<=n;i++)answer[i]+=a[i];

    for(int i=1;i<=n;i++)
    {
        cout<<answer[i]<<" ";
    }cout<<endl;
    return 0;
}
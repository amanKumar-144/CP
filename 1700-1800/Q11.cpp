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
    int a,b,c;cin>>a>>b>>c;
    vii store;
    store.pb(a);store.pb(b);store.pb(c);

    sort(store.begin(),store.end());
    if(store[0]+store[1]<=store[2]/2)
    {
        cout<<store[0]+store[1]<<endl;
    }
    else cout<<(store[0]+store[1]+store[2])/3<<endl;
    return 0;
}
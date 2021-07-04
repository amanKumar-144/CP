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
    vii array;
    array.pb(a);array.pb(b);array.pb(c);
    sort(array.begin(),array.end());

    if(array[0]+array[1]<=array[2]/2)cout<<array[0]+array[1]<<endl;
    else cout<<(array[0]+array[1]+array[2])/3<<endl;
    return 0;
}
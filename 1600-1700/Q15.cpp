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
    int n;cin>>n;
    vii a={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    int valid=0;
    for(int i=0;i<a.size();i++)
    {
        if(n%a[i]==0)valid=1;
    }
    if(valid==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
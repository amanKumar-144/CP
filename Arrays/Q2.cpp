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
const int N=1e6;
vector<pii>counting(N,mp(0,0));
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
        counting[x]=mp(1,i);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {
            int sum=a[i]+a[j];
            if(counting[sum].fi==1)
            {
                count++;
            }
        }
    }
    return 0;
}
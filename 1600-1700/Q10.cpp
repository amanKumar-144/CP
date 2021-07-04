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
    int n,k;cin>>n>>k;
    if(n%2==1)n++;
    int polarity=1;
    if(k>n/2)
    {
        k=k-n/2;
        polarity=0;
    }
    if(polarity==0)
    {
        cout<<2*k<<endl;
    }
    else
    {
        cout<<2*k-1<<endl;
    }
    return 0;
}
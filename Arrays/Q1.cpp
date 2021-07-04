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
    int n,s;cin>>n>>s;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    int start=0;int end=-1;
    int sum=0;int valid=-1;
    vii ans;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==s)
        {
            valid=1;
            end=i;
            break;
        }
        while(sum>s)
        {
            sum-=a[start];
            start++;
        }
        if(sum==s)
        {
            valid=1;
            end=i;
            break;
        }
    }
    if(valid==-1)ans.pb(-1);
    else{
        ans.pb(start+1);
        ans.pb(end+1);
    }
    return 0;
}
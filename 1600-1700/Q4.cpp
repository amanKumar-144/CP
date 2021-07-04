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
    string a,b;cin>>a>>b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==b[i])continue;
        else if(a[i]<b[i])
        {
            ans=-1;break;
        }
        else{
            ans=1;break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
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
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
    }
    int ans=0;
    vii cumLeft;cumLeft.pb(a[0]);
    for(int i=1;i<n;i++)
        cumLeft.pb(cumLeft[i-1]+a[i]);

    vii cumRight;cumRight.pb(a[n-1]);
    int p=0;
    for(int i=n-2;i>=0;i--)
    {
        cumRight.pb(cumRight[p]+a[i]);
        p++;
    }
    reverse(cumRight.begin(),cumRight.end());
    for(int i=0;i<n;i++)
    {
        int start=i+1;int end=n-1;
        int val=cumLeft[i];
        while(start<=end)
        {
            int middle=start+(end-start)/2;
            if(val==cumRight[middle]){ans=val;break;}
            else if(val<cumRight[middle])
            {
                start=middle+1;
            }
            else end=middle-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
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
    vii a;
    set<int>s;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
        s.ins(x);
    }
    sort(a.begin(),a.end());
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        int elem=a[i];
        int nextElem=a[i]+5;
        int start=i;
        int end=n-1;
        int gap=0;
        while(start<=end)
        {
            int middle=start+(end-start)/2;
            if(a[middle]<=nextElem)
            {
                gap=middle;
                start=middle+1;
            }
            else if(a[middle]>nextElem)
            {
                end=middle-1;
            }
        }
        ans=max(ans,gap-i+1);
    }
    cout<<ans<<endl;
    return 0;
}
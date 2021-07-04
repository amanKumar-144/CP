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
vii a;
bool valid(int days)
{
    int temp=a.size()*days;
    for(int i=0;i<a.size();i++)
    {
        if(temp<=0)return false;
        else temp-=a[i];
    }
    if(temp>=days)return true;
    else return false;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
        sum+=x;
    }
    sort(a.begin(),a.end());
    
    int start=1;
    int end=sum;
    int ans=-1;

    while(start<=end)
    {
        int middle=start+(end-start)/2;
        bool check=valid(middle);
        if(check==true)
        {
            ans=middle;
            end=middle-1;
        }
        else 
        {
            start=middle+1;
        }
    }
    ans=max(ans,a[a.size()-1]);
    cout<<ans<<endl;
    return 0;
}
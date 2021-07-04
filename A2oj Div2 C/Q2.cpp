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
    int valid=1;int sum=0;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
        sum+=x;
    }
    if(sum%3!=0)valid=0;
    
    if(valid==0)
    {
        cout<<0<<endl;
    }
    else if(valid==1 && sum!=0)
    {
        int first=sum/3;
        int second=2*first;
        int third=3*first;

        vii storeSecond(n,0);
        vii markSecond(n,0);
        vii index;
        int temp=0;

        for(int i=0;i<n;i++)
        {
            temp+=a[i];
            if(temp==first)index.pb(i);
            if(temp==second)markSecond[i]=1;
        }
       
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)storeSecond[i]=markSecond[i];
            else storeSecond[i]=storeSecond[i+1]+markSecond[i];
        }
        int ans=0;
        for(int i=0;i<index.size();i++)
        {
            ans=ans+storeSecond[index[i]];
        }
        cout<<ans<<endl;
    }
    else if(valid==1 && sum==0)
    {
        int pts=0;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=a[i];
            if(temp==0)pts++;
        }
        pts--;
        int ans=pts*(pts-1);ans/=2;
        cout<<ans<<endl;
    }
    return 0;
}
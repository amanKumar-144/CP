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
    for(int i=0;i<a.size();++i)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    map<int,int>s;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);

        auto itr=s.find(x);
        if(itr==s.end())s.ins(mp(x,1));
        else itr->se++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int valid=0;
        for(int j=0;j<31;j++)
        {
            int sum=pow(2,j);
            int left=sum-a[i];
            auto itr=s.find(left);
            if(itr!=s.end())
            {
                if(a[i]==left && itr->se > 1)
                {
                    valid=1;break;
                }
                else if(a[i]!=left)
                {
                    valid=1;break;
                }
            }
        }
        if(valid==0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
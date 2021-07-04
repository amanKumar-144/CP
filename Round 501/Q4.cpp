#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
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
    int n,k,s;cin>>n>>k>>s;
    int gap=n-1;
    int valid=1;

    int jumps=s/gap;
    int walks=s%gap;
    int add=0;
    if(walks>0)add=1;
    
    if(k>s || jumps+add>k)valid=0;
    if(valid==0)cout<<"NO"<<endl;
    else
    {
        vii ans;
        for(int i=0;i<jumps;i++)
        {
            if(i%2==0)ans.pb(n);
            else ans.pb(1);
        }
        if(walks!=0)
        {
            if(ans.size()!=0 && ans[ans.size()-1]==n)
                ans.pb(n-walks);
            else ans.pb(walks+1);
        }
        if(ans.size()>k){valid=0;cout<<"NO"<<endl;}
        if(valid==1)
        {
            int coverLeft=k-ans.size();
            vii newAns;
            int ptr=0;
            int start=2;
            int inc=1;
            while(coverLeft>0)
            {
                if(start==ans[ptr])
                {
                    newAns.pb(start);
                    if(start==1){inc=1;start++;}
                    else {inc=0;start--;}
                    ptr++;
                }
                else
                {
                    newAns.pb(start);
                    coverLeft--;
                    if(inc==1)
                        start++;
                    else
                        start--;
                }
            }
            for(int i=ptr;i<ans.size();i++)newAns.pb(ans[i]);
            cout<<"YES"<<endl;
            print(newAns);
        }
    }
    return 0;
}
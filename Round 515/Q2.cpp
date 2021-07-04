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
    int n,r;cin>>n>>r;
    vii a;
    vii storeIndex;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        if(x==1)storeIndex.pb(i);
    }
    vector<int>storeLantern(n,0);
    for(int i=0;i<storeIndex.size();i++)
    {
        //Left
        for(int j=storeIndex[i];j>storeIndex[i]-r && j>=0;j--)
        {
            storeLantern[j]++;
        }
        //Right
        for(int j=storeIndex[i]+1;j<storeIndex[i]+r && j<n;j++)
        {
            storeLantern[j]++;
        }
    }
    int valid=1;
    for(int i=0;i<n;i++)
    {
        if(storeLantern[i]==0)valid=0;
    }
    if(valid==0)cout<<-1<<endl;
    else 
    {
        set<int>ans;
        for(int i=0;i<storeIndex.size();i++)//Store Lantern index
        {
            //Left
            int check=0;
            for(int j=storeIndex[i];j>storeIndex[i]-r && j>=0;j--)
            {
                if(storeLantern[j]==1){ans.ins(storeIndex[i]);check=1;break;}
            }
            //Right
            for(int j=storeIndex[i]+1;j<storeIndex[i]+r && j<n && check==0;j++)
            {
                if(storeLantern[j]==1){ans.ins(storeIndex[i]);check=1;break;}
            }

            //We dont include heater
            if(check==0)
            {
                //Left
                for(int j=storeIndex[i];j>storeIndex[i]-r && j>=0;j--)
                {
                    storeLantern[j]--;
                }
                //Right
                for(int j=storeIndex[i]+1;j<storeIndex[i]+r && j<n ;j++)
                {
                    storeLantern[j]--;
                }
            }
        }
        cout<<ans.size()<<endl;
    }
    return 0;
}
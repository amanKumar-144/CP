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
    stack<int>s;
    vii a;
    vector<int>deathTime(n,0); //For each index
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    s.push(0);
    deathTime[0]=-1;

    for(int i=1;i<n;i++)
    {
        int element=a[i];
        deathTime[i]=0;//Probably dead in first move

        while(s.size()>0 && a[s.top()]<element)
        {
            deathTime[i]=max(deathTime[i],deathTime[s.top()]+1);
            s.pop();
        }
        if(s.size()==0)
        {
            deathTime[i]=-1;
            s.push(i);
        }
        else s.push(i);
    }
    int ans=-1;
    for(int i=0;i<deathTime.size();i++){
        ans=max(ans,deathTime[i]);
    }
    cout<<ans+1<<endl;
    return 0;
}
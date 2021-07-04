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
    int n,k;cin>>n>>k;
    vii a;
    set<pii>s;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        s.ins(mp(a[i],i+1));
    }
    
    vii answer;
    for(auto itr=s.rbegin();itr!=s.rend();itr++)
    {
        pii p=mp(itr->fi,itr->se);
        if(k>0)
        {
            answer.pb(p.se);
            k--;
        }
    }
    int total=0;
    sort(answer.begin(),answer.end());
    vii index;
    for(int i=0;i<answer.size();i++)
    {
        total+=a[answer[i]-1];
        if(answer.size()==1){index.pb(n);break;}
        
        if(i==0)index.pb(answer[i]);
        else if(i==answer.size()-1)index.pb(n-answer[i-1]);
        else index.pb(answer[i]-answer[i-1]);
    }
    cout<<total<<endl;
    print(index);
    return 0;
}
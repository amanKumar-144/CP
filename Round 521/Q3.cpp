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
    int sum=0;
    map<int,int>freq;//Element,Freq
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        sum+=x;
        auto itr=freq.find(x);
        if(itr==freq.end())freq.ins(mp(x,1));
        else itr->se++;
    }
    
    vii ans;
    for(int i=0;i<n;i++)
    {
        int sumPresent=sum-a[i];
        if(sumPresent%2==1)continue;

        int elementWeWant=sumPresent/2;
        auto itr1=freq.find(a[i]);
        itr1->se--;
        auto itr2=freq.find(elementWeWant);
        if(itr2!=freq.end() && itr2->se>0)
        {
            ans.pb(i+1);
        }
        itr1->se++;
    }
    cout<<ans.size()<<endl;
    print(ans);
    return 0;
}
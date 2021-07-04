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
vector<pii>answerPairs;
vector<pii>finalPairs;
int32_t main()
{
    FAST;
    int n,k;cin>>n>>k;

    int v1=1;
    int v2=2;
    while(true)
    {
        answerPairs.pb(mp(v1,v2));
        v2++;
        if(v2==k+1)
        {
            v1++;
            v2=v1+1;
        }
        if(v1==k)break;
        if(answerPairs.size()==n)break;
    }
    for(int i=0;i<answerPairs.size();i++)
    {
        pii a=answerPairs[i];
        finalPairs.pb(mp(a.fi,a.se));
        finalPairs.pb(mp(a.se,a.fi));
    }
    if(finalPairs.size()<n)cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<finalPairs[i].fi<<" "<<finalPairs[i].se<<endl;
        }
    }
    return 0;
}
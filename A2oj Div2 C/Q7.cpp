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

int32_t main()
{
    FAST;
    int n,m;cin>>n>>m;
    int minValue=min(n,m);

    vector<pii>answers;
    for(int i=0;i<=minValue;i++)
    {
        answers.pb(mp(i,minValue-i));
    }
    cout<<answers.size()<<endl;
    for(int i=0;i<answers.size();i++)
    {
        cout<<answers[i].fi<<" "<<answers[i].se<<endl;
    }
    return 0;
}
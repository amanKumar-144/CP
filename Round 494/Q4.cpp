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
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
}
int32_t main()
{
    FAST;
    int n,k;cin>>n>>k;
    map<int,int>storeFreq;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        auto itr=storeFreq.find(x);
        if(itr==storeFreq.end())
        {
            storeFreq.ins(mp(x,1));
        }else itr->se++;
    }
    vii answer;
    for(int i=1;i<=k;i++)
    {
        int x;cin>>x;
        int moves=0;
        for(auto itr=storeFreq.rbegin();itr!=storeFreq.rend();itr++)
        {
            int total=itr->fi;
            int count=itr->se;
            int quotient=x/total;
            if(quotient<=count)
            {
                x=x-total*quotient;
                moves=moves+quotient;
            }
            else 
            {
                x=x-total*count;
                moves=moves+count;
            }
        }
        if(x==0)answer.pb(moves);
        else answer.pb(-1);
    }
    print(answer);
    return 0;
}
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
    int n,m;cin>>n>>m;
    int required=n/m;

    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }

    vector<int>graph[m];//Has index;
    for(int i=0;i<n;i++)
    {
        int rem=a[i]%m;
        graph[rem].pb(i);
    }
    set<int>less;
    set<int>more;

    for(int i=0;i<m;i++)
    {
        int size=graph[i].size();
        if(size>required){
            more.ins(i);
        }
        else if(size<required){
            less.ins(i);
        }
    }
    auto itrLow=less.begin();
    auto itrHigh=more.begin();

    int ans=0;
    while(true)
    {
        if(itrLow==less.end() || itrHigh==more.end())break;

        int lessRemainder=*itrLow;
        int moreRemainder=*itrHigh;
        if(moreRemainder<lessRemainder)
        {
            int addRequired=required-graph[lessRemainder].size();
            int canGive=graph[moreRemainder].size()-required;
            //Less satisfied
            if(canGive>addRequired)
            {
                int weTake=addRequired;
                int addMoves=(lessRemainder-moreRemainder)*weTake;
                ans+=addMoves;
                while(weTake--)
                {
                    int lastIndex=graph[moreRemainder].back();
                    graph[moreRemainder].pop_back();
                    graph[lessRemainder].pb(lastIndex);
                    a[lastIndex]+=(lessRemainder-moreRemainder);
                }
                itrLow++;
            }
            //Less not satisfied
            else if(canGive<=addRequired)
            {
                int weTake=canGive;
                int addMoves=(lessRemainder-moreRemainder)*weTake;
                ans+=addMoves;
                while(weTake--)
                {
                    int lastIndex=graph[moreRemainder].back();
                    graph[moreRemainder].pop_back();
                    graph[lessRemainder].pb(lastIndex);
                    a[lastIndex]+=(lessRemainder-moreRemainder);
                }
                itrHigh++;
                if(canGive==addRequired)
                {
                    itrLow++;
                }
            }
        }


        else if(moreRemainder>lessRemainder)
        {
            int addRequired=required-graph[lessRemainder].size();
            int canGive=graph[moreRemainder].size()-required;
            //Less satisfied
            if(canGive>addRequired)
            {
                int weTake=addRequired;
                int addMoves=(m-moreRemainder+lessRemainder)*weTake;
                ans+=addMoves;
                while(weTake--)
                {
                    int lastIndex=graph[moreRemainder].back();
                    graph[moreRemainder].pop_back();
                    graph[lessRemainder].pb(lastIndex);
                    a[lastIndex]+=(m-moreRemainder+lessRemainder);
                }
                itrLow++;
            }
            //Less not satisfied
            else if(canGive<=addRequired)
            {
                int weTake=canGive;
                int addMoves=(m-moreRemainder+lessRemainder)*weTake;
                ans+=addMoves;
                while(weTake--)
                {
                    int lastIndex=graph[moreRemainder].back();
                    graph[moreRemainder].pop_back();
                    graph[lessRemainder].pb(lastIndex);
                    a[lastIndex]+=(m-moreRemainder+lessRemainder);
                }
                itrHigh++;
                if(canGive==addRequired)
                {
                    itrLow++;
                }
            }
        }
    }
    cout<<ans<<endl;
    print(a);
    return 0;
}
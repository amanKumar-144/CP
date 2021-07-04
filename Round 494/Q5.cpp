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
const int N=400001;
vector<int>graph[N];
set<pii>storeAddOns;
set<pii>edges;

int32_t main()
{
    FAST;
    int n,d,k;
    cin>>n>>d>>k;
    int valid=1;
    if(d>=n)valid=0;
    if(k==1 && n>2)valid=0;
    else
    {
        int startVertex=1;
        int dia=d;
        while(dia--)
        {
            graph[startVertex].pb(startVertex+1);
            graph[startVertex+1].pb(startVertex);
           
            int extra=min(startVertex-1,d+1-startVertex);
            pii a=mp(extra,startVertex);
            if(extra>0)storeAddOns.ins(a);
            startVertex+=1;
        }
        startVertex+=1;
        while(startVertex<=n)
        {
            if(storeAddOns.size()==0)break;

            auto topItr=storeAddOns.begin();
            int minCount=topItr->fi;
            int parentVertex=topItr->se;
            int degree=graph[parentVertex].size();
            if(degree<k)
            {
                if(minCount>0)
                {
                    minCount--;
                    graph[parentVertex].pb(startVertex);
                    graph[startVertex].pb(parentVertex);
                    pii a=mp(minCount,startVertex);
                    storeAddOns.ins(a);
                    startVertex+=1;
                }
                else if(minCount==0)
                {
                    storeAddOns.erase(topItr);
                }
            }
            else if(degree>=k)
            {
                storeAddOns.erase(topItr);
            }
        }
        if(startVertex!=n+1)valid=0;
    }
    if(valid==0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                pii e=mp(i,graph[i][j]);
                pii f=mp(graph[i][j],i);
                auto findItr1=edges.find(e);auto findItr2=edges.find(f);
                if(findItr1==edges.end() && findItr2==edges.end())
                {
                    cout<<i<<" "<<graph[i][j]<<endl;
                    edges.ins(e);edges.ins(f);
                }
            }
        }
    }
    return 0;
}
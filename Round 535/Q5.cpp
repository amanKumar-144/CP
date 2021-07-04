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
vii a;
vector<pii>query;
vii getIndex;
int getSequences(int posMin,int posMax)
{
    int ans=0;
    for(int i=0;i<query.size();i++)
    {
        int l=query[i].fi;
        int r=query[i].se;
        if(l<=posMin && posMin<=r)
        {
            if(!(l<=posMax && posMax<=r)){
                ans++;
                getIndex.pb(i+1);
            }
        }
    }
    return ans;
}
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
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }

    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        query.pb(mp(x,y));
    }
    int answer=0;vii queryIndex;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                int minElement=a[i];
                int maxElement=a[j];
                int seq1=getSequences(i+1,j+1);
                int val=maxElement-(minElement-seq1);
                if(val>answer)
                {
                    answer=val;
                    queryIndex=getIndex;
                }
                getIndex.clear();
            }
        }
    }
    cout<<answer<<endl;
    cout<<queryIndex.size()<<endl;
    print(queryIndex);
    return 0;
}
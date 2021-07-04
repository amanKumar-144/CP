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
    vector<pii>coordinates;
    map<int,int>xCoord;
    map<int,int>yCoord;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        coordinates.pb(mp(x,y));

        auto itr=xCoord.find(x);
        if(itr==xCoord.end())xCoord.ins(mp(x,1));
        else itr->se++;

        auto itr2=yCoord.find(y);
        if(itr2==yCoord.end())yCoord.ins(mp(y,1));
        else itr2->se++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x=coordinates[i].fi;
        int y=coordinates[i].se;

        auto itr=xCoord.find(x);
        if(itr->se==1)xCoord.erase(itr);

        auto itr2=yCoord.find(y);
        if(itr2->se==1)yCoord.erase(itr2);

        auto maxX=xCoord.rbegin();
        auto minY=yCoord.begin();
        
        if(maxX->fi <= minY->fi)
        {
            ans=max(ans,minY->fi-maxX->fi);
        }

        itr=xCoord.find(x);
        if(itr==xCoord.end())xCoord.ins(mp(x,1));
        itr2=yCoord.find(y);
        if(itr2==yCoord.end())yCoord.ins(mp(y,1));
    }
    cout<<ans<<endl;
    return 0;
}
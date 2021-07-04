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
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.pb(x);
    }
    vii storeFreq(n,0);
    set<pii,greater<pii>>s;
    int badZeros=0;
    map<int,int>indexToFreq;//Index->Freq
    for(int i=0;i<n;i++)
    {
        if(a[i]==0 && i-1>=0 && a[i-1]==1 && i+1<n && a[i+1]==1)
        {
            storeFreq[i-1]++;
            storeFreq[i+1]++;
            badZeros++;
        }
    }
    for(int i=0;i<n;i++){
        if(storeFreq[i]>0)
        {
            s.ins(mp(storeFreq[i],i));

            indexToFreq[i]=storeFreq[i];
        }
    }
    int ans=0;
    while(badZeros>0)
    {
        auto a=s.begin();
        int freq=a->fi;
        int index=a->se;
        if(freq==2)
        {
            badZeros-=2;
            s.erase(mp(freq,index));
            auto capacityLeft=indexToFreq.find(index-2);
            auto capacityRight=indexToFreq.find(index+2);

            s.erase(mp(capacityLeft->se,index-2));
            s.erase(mp(capacityRight->se,index+2));
            
            if(capacityLeft->se-1 >0)
                s.ins(mp(capacityLeft->se-1,index-2));

            if(capacityRight->se-1 >0)
                s.ins(mp(capacityRight->se-1,index+2));

            ans++;
        }
        else if(freq==1)
        {
            badZeros--;
            s.erase(mp(freq,index));
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
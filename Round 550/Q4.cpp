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
int storeIndex;
void print(vector<vii>&a)
{
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i][0]<<" "<<a[i][1]+1<<" "<<a[i][2]+1<<endl;
    }
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    map<int,int>storeFreq;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
        auto itr=storeFreq.find(x);
        if(itr==storeFreq.end())storeFreq.ins(mp(x,1));
        else itr->se++;
    }
    int maxElement=-1;
    int count=0;
    for(auto itr=storeFreq.begin();itr!=storeFreq.end();itr++)
    {
        if(itr->se > count)
        {
            count=itr->se;
            maxElement=itr->fi;
        }
    }
    storeIndex=-1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==maxElement)
        {
            storeIndex=i;
            break;
        }
    }
    //if(storeIndexRight==-1)storeIndexRight=storeIndexLeft;

    vector<vii>answer;
    for(int i=storeIndex;i>=0;i--)
    {
        if(a[i]<maxElement)
        {
            vii x={1,i,i+1};
            answer.pb(x);
        }
        else if(a[i]>maxElement)
        {
            vii x={2,i,i+1};
            answer.pb(x);
        }
    }
    for(int i=storeIndex;i<n;i++)
    {
        if(a[i]==maxElement)
        {
            storeIndex=i;
        }
        else if(a[i]<maxElement)
        {
            vii x={1,i,storeIndex};
            answer.pb(x);
            storeIndex=i;
        }
        else if(a[i]>maxElement)
        {
            vii x={2,i,storeIndex};
            answer.pb(x);
            storeIndex=i;
        }
    }
    print(answer);
    return 0;
}
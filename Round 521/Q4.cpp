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
    int n,k;cin>>n>>k;
    vii a;
    map<int,int>freq;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        auto itr=freq.find(x);
        if(itr==freq.end())freq.ins(mp(x,1));
        else itr->se++;
    }

    set<pii,greater<pii>>s;
    for(auto itr=freq.begin();itr!=freq.end();itr++)
    {
        s.ins(mp(itr->se,itr->fi));
    }

    int start=1;
    int end=1e9;
    int ans=0;
    while(start<=end)
    {
        int middle=start+(end-start)/2;
        int count=0;
        //Form answer from middle
        //We need middle copies
        int size=0;
        int valid=0;
        for(auto itr=s.begin();itr!=s.end();itr++)
        {
            int element=itr->se;
            int freq=itr->fi;
            int contrib=freq/middle;
            size+=contrib;
            if(size>=k)
            {
                valid=1;
                break;
            }
            if(contrib==0)break;
        }
        if(valid==1)
        {
            ans=middle;
            start=middle+1;
        }
        else if(valid==0)
        {
            end=middle-1;
        }
    }
    //Form the answer
    vii answer;
    int size=0;
    for(auto itr=s.begin();itr!=s.end();itr++)
    {
        int element=itr->se;
        int freq=itr->fi;
        int contrib=freq/ans;
        for(int i=0;i<contrib;i++)
        {
            answer.pb(element);
        }
        size+=contrib;
        if(size>=k)
        {
            break;
        }
    }
    
    //The copies possible are 
    for(int i=0;i<k;i++)
    {
        cout<<answer[i]<<" ";
    }cout<<endl;
    return 0;
}
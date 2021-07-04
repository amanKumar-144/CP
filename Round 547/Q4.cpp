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
map<char,vii>storeIndex;
vii storeQA;
vii storeQB;
int32_t main()
{
    FAST;
    int n;cin>>n;
    string a;
    string b;
    cin>>a>>b;

    vii blockIndex(n+1,-1);//-1 means not blocked
    //1 means blocked 

    //Setting B
    for(int i=0;i<n;i++)
    {
        char l=b[i];
        if(l=='?')
        {
            storeQB.pb(i);
            continue;
        }
        auto itr=storeIndex.find(l);
        if(itr==storeIndex.end())
        {
            storeIndex[l].pb(i);
        }
        else itr->se.pb(i);
    }

    vector<pii>answer;
    for(int i=0;i<n;i++)
    {
        char l=a[i];
        if(l=='?')
        {
            storeQA.pb(i);
            continue;
        }
        auto itr=storeIndex.find(l);
        if(itr!=storeIndex.end())
        {
            blockIndex[i+1]=1;
            answer.pb(mp(i+1,itr->se.back()+1));
            itr->se.pop_back();
            if(itr->se.size()==0)storeIndex.erase(itr);
        }
        else
        {
            if(storeQB.size()>0)
            {
                blockIndex[i+1]=1;
                answer.pb(mp(i+1,storeQB.back()+1));
                storeQB.pop_back();
            }
        }
    }
    if(storeQA.size()>0)
    {
        while(storeQB.size()>0 && storeQA.size()>0)
        {
            answer.pb(mp(storeQA.back()+1,storeQB.back()+1));
            blockIndex[storeQA.back()+1]=1;
            storeQA.pop_back();
            storeQB.pop_back();
        }
        if(storeQA.size()>0)
        {
            for(auto itr=storeIndex.begin();itr!=storeIndex.end();itr++)
            {
                while(itr->se.size()>0 && storeQA.size()>0)
                {
                    answer.pb(mp(storeQA.back()+1,itr->se.back()+1));
                    blockIndex[storeQA.back()+1]=1;
                    itr->se.pop_back();
                    storeQA.pop_back();
                }
                if(storeQA.size()==0)break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(blockIndex[i]==-1 && storeQB.size()>0)
        {
            answer.pb(mp(i,storeQB.back()));
            storeQB.pop_back();
        }
    }
    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i].fi<<" "<<answer[i].se<<endl;
    }
    return 0;
}
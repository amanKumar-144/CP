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
    set<int>graph[n];
    vector<int>helloGraph[n];
    vector<int>graphSum(n,0);

    for(int i=0;i<n;i++)
    {
        int size;cin>>size;
        int sum=0;
        for(int j=0;j<size;j++)
        {
            int x;cin>>x;
            graph[i].ins(x);
            helloGraph[i].pb(x);
            sum+=x;
        }
        graphSum[i]=sum;
    }
    map<int,pii>s;//Sum-x,(sequence,x)
    int seq1,seq2;int ele1,ele2;int ind1,ind2;
    seq1=-1;seq2=-1;
    for(int i=0;i<n;i++)
    {
        for(auto itr=graph[i].begin();itr!=graph[i].end();itr++)
        {
            int ssum=graphSum[i]-*itr;
            auto it=s.find(ssum);
            if(it==s.end())
            {
                s.ins(mp(ssum,mp(i,*itr)));
            }
            else
            {
                seq1=i;
                seq2=it->se.fi;
                ele1=*itr;
                ele2=it->se.se;
            }
        }
    }
    if(seq1==-1 || seq2==-1){
        cout<<"NO"<<endl;return 0;
    }
    for(int i=0;i<helloGraph[seq1].size();i++)
    {
        if(ele1==helloGraph[seq1][i])ind1=i;
    }
    for(int i=0;i<helloGraph[seq2].size();i++)
    {
        if(ele2==helloGraph[seq2][i])ind2=i;
    }
    cout<<"YES"<<endl;
    cout<<seq1+1<<" "<<ind1+1<<endl;
    cout<<seq2+1<<" "<<ind2+1<<endl;
    return 0;
}
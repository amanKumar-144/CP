#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>
#define int long long 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
map<int,vii>graph;
set<int>s;
map<int,int>vertices;//Vertex Number,Count
vector<int>answer;

void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
void dfs(int v)
{
    answer.pb(v);
    auto it=vertices.find(v);
    it->se--;
    auto itr=graph.find(v);
    vii a=itr->se;
    for(int i=0;i<a.size();i++)
    {
        auto itr2=vertices.find(a[i]);
        if(itr2->se > 0)
        {
            dfs(a[i]);
        }
    }
}
int32_t main()
{
    FAST;
    int n;cin>>n;
    vii a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;a.pb(x);
        s.ins(x);
        auto itr=vertices.find(x);
        if(itr==vertices.end())vertices.ins(mp(x,1));
        else itr->se++;
    }
    for(int i=0;i<n;i++)
    {
        int element=a[i];
        int num1=element*2;
        auto itr1=s.find(num1);
        if(itr1!=s.end())
        {
            auto it=graph.find(element);
            if(it==graph.end())
            {
                graph[element]={num1};
                auto it2=graph.find(num1);
                if(it2==graph.end())
                {
                    graph[num1]={element};
                }
                else it2->se.pb(element);
            }
            else
            {
                it->se.pb(num1);
                auto it2=graph.find(num1);
                if(it2==graph.end())
                {
                    graph[num1]={element};
                }
                else it2->se.pb(element);
            }
        }
        if(element%3==0)
        {
            num1=element/3;
            auto itr1=s.find(num1);
            if(itr1!=s.end())
            {
                auto it=graph.find(element);
                if(it==graph.end())
                {
                    graph[element]={num1};
                    auto it2=graph.find(num1);
                    if(it2==graph.end())
                    {
                        graph[num1]={element};
                    }
                    else it2->se.pb(element);
                }
                else
                {
                    it->se.pb(num1);
                    auto it2=graph.find(num1);
                    if(it2==graph.end())
                    {
                        graph[num1]={element};
                    }
                    else it2->se.pb(element);
                }
            }
        }
    }
    int start=-1;
    for(auto itr=graph.begin();itr!=graph.end();itr++)
    {
        if(itr->se.size() == 1){
            start=itr->fi;
            int num1=start*2;
            auto it=s.find(num1);
            if(it!=s.end())
                break;
            if(start%3==0)
            {
                num1=start/3;
                auto it=s.find(num1);
                if(it!=s.end())
                    break;
            }
        }
    }
    dfs(start);
    print(answer);
    return 0;
}
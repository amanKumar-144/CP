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
#define endl "\n"
using namespace std;
int32_t main()
{
    FAST;
    int n,m,k;cin>>n>>m>>k;
    int store=0;
    int count=0;
    vector<vector<pii>>answer;
    vector<pii>temp;
    int polarity=0;

    for(int i=1;i<=n;i++)
    {
        if(polarity==0)
        {
            for(int j=1;j<=m;j++)
            {
                count++;
                temp.pb(mp(i,j));
                if(count==2 && store<k-1)
                {
                    answer.pb(temp);
                    temp.clear();
                    store++;
                    count=0;
                }
            }
            polarity=1;
        }

        else if(polarity==1)
        {
            for(int j=m;j>=1;j--)
            {
                count++;
                temp.pb(mp(i,j));
                if(count==2 && store<k-1)
                {
                    answer.pb(temp);
                    temp.clear();
                    store++;
                    count=0;
                } 
            }
            polarity=0;
        }
    }
    if(temp.size()>0)answer.pb(temp);
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i].size()<<" ";
        for(int j=0;j<answer[i].size();j++)
        {
            cout<<answer[i][j].fi<<" "<<answer[i][j].se<<" ";
        }cout<<endl;
    }
    return 0;
}
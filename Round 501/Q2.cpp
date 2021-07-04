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
vector<pii>coordinates;
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
    int n;cin>>n;
    string s,t;
    cin>>s;cin>>t;

    vii ans;
    int valid=0;
    string s1=s;
    string s2=t;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2)valid=1;

    if(valid==1)
    {
        vii ans;
        for(int i=0;i<t.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(s[j]==t[i])
                {
                    int start=i;
                    int end=j-1;
                    for(int k=end;k>=start;k--)
                    {
                        ans.pb(k+1);
                        swap(s[k],s[k+1]);
                    }
                    break;
                }
            }
        }
        //cout<<s<<endl;
        //cout<<t<<endl;
        cout<<ans.size()<<endl;
        print(ans);
    }
    else cout<<-1<<endl;
    
    return 0;
}
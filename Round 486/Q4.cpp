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
    set<int>s;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
        s.ins(x);
    }
    //Possible Answers=1,2,3
    int bestAns=1;
    int val1=a[0];int val2=-1;int val3=-1;
    
    for(int i=0;i<31;i++)
    {
        int gap=pow(2,i);
        for(int j=0;j<n;j++)
        {
            int start=a[j];
            int num1=start+gap;
            int num2=start+2*gap;
            auto it1=s.find(num1);
            auto it2=s.find(num2);
            if(it1!=s.end() && it2!=s.end())
            {
                bestAns=3;
                val1=start;val2=num1;val3=num2;
                cout<<bestAns<<endl;
                cout<<val1<<" "<<val2<<" "<<val3<<endl;
                return 0;
            }
            else if(it1!=s.end() && it2==s.end())
            {
                bestAns=2;
                val1=start;
                val2=num1;
            }
            else if(it1==s.end() && it2!=s.end())
            {
                bestAns=2;
                val1=start;
                val2=num2;
            }
        }
    }
    cout<<bestAns<<endl;
    if(bestAns==1)cout<<val1<<endl;
    else if(bestAns==2)cout<<val1<<" "<<val2<<endl;
    return 0;
}
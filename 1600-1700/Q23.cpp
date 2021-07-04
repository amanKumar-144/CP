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
    int n,m;cin>>n>>m;
    vii a;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
    }
    int index=0;
    int score=0;
    for(int i=0;i<m;i++)score+=a[i];
    int next;
    int minObtained=score;
    for(int i=1;i<n;i++)
    {
        next=i+m-1;
        if(next>=n)break;
        int newScore=score-a[i-1]+a[next];
        if(newScore<minObtained)
        {
            index=i;
            minObtained=newScore;
        }
        score=newScore;
    }
    cout<<index+1<<endl;
    return 0;
}
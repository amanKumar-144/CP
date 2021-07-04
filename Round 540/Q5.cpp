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
    int sum=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;a.pb(x);
        sum+=x;
    }
    int valid=1;
    if(m>sum)valid=0;
    if(valid==0)
    {
        cout<<-1<<endl;return 0;
    }
    sort(a.begin(),a.end());
    int start=1;
    int end=n;
    int answer=-1;
    while(start<=end)
    {
        int middle=start+(end-start)/2;
        int counter=0;
        int tempSum=0;
        int sub=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(counter<middle)
            {
                tempSum=tempSum+max(0ll,a[i]-sub);
                counter++;
            }
            else if(counter==middle)
            {
                sub++;
                counter=1;
                tempSum=tempSum+max(0ll,a[i]-sub);
            }
        }
        if(tempSum<m)
        {
            start=middle+1;
        }
        else
        {
            answer=middle;
            end=middle-1;
        }
    }
    cout<<answer<<endl;
    return 0;
}
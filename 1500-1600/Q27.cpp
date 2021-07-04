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
void print(vii &a){
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<"\n";
    }
}
int32_t main()
{
    FAST;
    string s;cin>>s;
    int n=s.size();
    vii counting(n,0);
    int left=n-1;int right=0;
    int box=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='l'){
            counting[left]=box;
            box++;
            left--;
        }
        else if(s[i]=='r'){
            counting[right]=box;
            box++;
            right++;
        }
    }
    print(counting);
    return 0;
}
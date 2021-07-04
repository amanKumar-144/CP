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
    int n;cin>>n;
    string a,b;
    cin>>a>>b;
    int moves=0;
    for(int i=0;i<n/2;i++)
    {
        char one=a[i];char two=a[n-i-1];
        char three=b[i];char four=b[n-i-1];

        set<char>s;
        s.ins(one);s.ins(two);s.ins(three);s.ins(four);

        if(s.size()==4)moves+=2;
        else if(s.size()==3)
        {
            moves+=1;
            if(one==two)moves++;
        }
        else if(s.size()==2)
        {
            if(one==four && two==three)moves=moves;
            else if(one==three && two==four)moves=moves;
            else if(one==two && three==four)moves=moves;
            else moves++;
        }

    }
    if(n%2==1 && a[n/2]!=b[n/2])moves++;
    cout<<moves<<endl;
    return 0;
}
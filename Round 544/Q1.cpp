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
    string a;
    string b;
    cin>>a>>b;
    int hour1=(a[0]-'0')*10+(a[1]-'0');
    int minute1=(a[3]-'0')*10+(a[4]-'0');

    int hour2=(b[0]-'0')*10+(b[1]-'0');
    int minute2=(b[3]-'0')*10+(b[4]-'0');

    int duration=(hour2-hour1)*60+(minute2-minute1);
    int gap=duration/2;

    int extraHours=gap/60;
    int extraMinutes=gap%60;

    hour1+=extraHours;
    int finalMinutes=extraMinutes+minute1;
    if(finalMinutes>=60)
    {
        hour1++;
        finalMinutes-=60;
    }
    if(hour1<=9)cout<<0<<hour1;
    else cout<<hour1;
    cout<<":";
    if(finalMinutes<=9)cout<<0<<finalMinutes<<endl;
    else cout<<finalMinutes<<endl;
    return 0;
}
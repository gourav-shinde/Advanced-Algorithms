#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

#define deb(i) cout<<#i<<":"<<i<<endl;
#define fo(i,n) for(int j=i;j<n;j++)
void get_arr(int *p,int length){for(ll i=0;i<length;i++)cin>>*(p+i);}
void print_arr(int *p,int length){for(int i=0;i<length;i++)cout<<*(p+i)<<" ";cout<<endl;}
typedef vector<int> vi;

void solve()
{
int length;
cin>>length;
queue<int> q;
for(int i=0;i<length;++i){
    int temp;
    cin>>temp;
    q.push(temp);
}
int comp=0;
do{
    int a=q.front();
    q.pop();
    int b=q.front();
    q.pop();
    // cout<<a<<" "<<b<<endl;
    q.push(max(a,b));
    ++comp;

}while(q.size()!=2);
    int a=q.front();
    
    q.pop();
    int b=q.front();
    q.pop();
    cout<<"Total Comparisons: "<<++comp<<endl;
    cout<<max(a,b)<<" "<<min(a,b)<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int t=1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
}

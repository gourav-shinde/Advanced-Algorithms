#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

#define deb(i) cout<<#i<<":"<<i<<endl;
#define fo(i,n) for(int j=i;j<n;j++)
void get_arr(ll *p,ll length){for(ll i=0;i<length;i++)cin>>*(p+i);}
void print_arr(int *p,int length){for(int i=0;i<length;i++)cout<<*(p+i)<<" ";cout<<endl;}
typedef vector<int> vi;
int count=0;
int gcd(int a, int b)
{
    cout<<a<<" "<<b<<endl;
    ++::count;
    if(b==0)return a;
    return gcd(b,a%b);

}

int extendedEuclidGCD(int a,int b,int *s,int *t){
    // cout<<"\na& b "<<a<<" "<<b<<endl;
    if(b==0){
        *s=0;*t=1;
        // cout<<"okay?\n";
        return a;
    }
    int x1, y1; // To store results of recursive call
    int gcd = extendedEuclidGCD(b, a%b, &x1, &y1);
 
    // cout<<"S "<<x1<<"  T "<<y1<<" Quotient "<<a/b<<endl;
    if(a/b!=0){
    *s = y1 - (a/b) * x1;
    *t = x1;
    }
    else{
        *s=x1;*t=y1;
    }
    cout<<"S "<<*s<<"  T "<<*t<<endl;
    return gcd;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // #endif
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int t=1;
    // cin>>t;

    while(t--)
    {
        // cout<<gcd(3,2)<<endl;
        // cout<<"Count is "<<::count<<endl;
        // ::count=0;
        // cout<<gcd(1035,585)<<endl;
        // cout<<"Count is "<<::count<<endl;
        int s=0,t=0;
        cout<<"g "<<extendedEuclidGCD(17,3120,&s,&t)<<" s "<<s<<" t "<<t<<endl;
    }
}

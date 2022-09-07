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

void traditionalHorners()
{
    int x,power;//v
    cin>>x;
    cin>>power;
    int arr[power+1];
    get_arr(arr,power+1);
    // cout<<x<<" "<<length<<endl;
    int sum=arr[0];

    for(int i=1;i<power+1;++i){
        sum=sum*x+arr[i];
        cout<<sum<<endl;
    }
    // print_arr(arr,length);
    cout<<"sum is "<<sum<<endl;

}

void homeworkHornerws(){
    int x,power;//v
    cin>>x;
    cin>>power;
    int arr[power+1];
    get_arr(arr,power+1);
    
    //positive terms are
    int sum=arr[0];
    int xsquare=pow(x,2);
    for(int i=2;i<power+1;i+=2){
        sum=sum*xsquare+arr[i];
        // cout<<sum<<endl;
    }
    // cout<<"sum is "<<sum<<endl;
    int sum2=arr[1];
    for(int i=3;i<power+1;i+=2){
        sum2=sum2*xsquare+arr[i];
    }
    sum2=sum2*x;
    cout<<"Answer:\nFor\n +x : "<<sum+abs(sum2)<<"\n -x : "<<sum-abs(sum2)<<endl;
    
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
        // traditionalHorners();
        homeworkHornerws();
    }
}

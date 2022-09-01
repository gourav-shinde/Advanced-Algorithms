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

int interPolatingSearch(int *arr,int low,int high, int X)
{
    if(low>high)return -1;
    int mid;
    if(X<arr[low] || X>arr[high])return -1;
    else{
        mid=high-(((arr[high]-X)*(high-low))/(arr[high]-arr[low]));
    }
    
    if(X==arr[mid]){
        return mid;
    }
    if(X<arr[mid]){
        return interPolatingSearch(arr,low,mid-1,X);
    }
    else
    {
        return interPolatingSearch(arr,mid+1,high,X);
    }

}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // #endif
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int arr[6]={1,2,3,5,6,7};
	
	cout<<interPolatingSearch(arr,0,5,1)<<endl;
    cout<<interPolatingSearch(arr,0,5,2)<<endl;
    cout<<interPolatingSearch(arr,0,5,3)<<endl;
    cout<<interPolatingSearch(arr,0,5,5)<<endl;
    cout<<interPolatingSearch(arr,0,5,6)<<endl;
    cout<<interPolatingSearch(arr,0,5,7)<<endl;
    cout<<interPolatingSearch(arr,0,5,25)<<endl;
}

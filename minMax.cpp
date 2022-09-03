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
//most optimal max min algorithm time complexity (3n/2)-2
//returns min and max of list of two
void MandM(int a,int b,int *max,int *min){
    if(a>b){
        *max=a;
        *min=b;
    }
    else{
        *min=a;
        *max=b;
    }
}

void solve(int *arr,int size)
{
    int max=INT_MIN,min=INT_MAX;
    if(size%2==0){
        MandM(arr[0],arr[1],&max,&min);
        for(int i=2;i<size-2;i+=2){
            int tmax,tmin;
            MandM(arr[i],arr[i+1],&tmax,&tmin);
            if(max<tmax)max=tmax;
            if(min>tmin)min=tmin;
        }
    }
    else{
        max=min=arr[0];
        for(int i=1;i<size-2;i+=2){
            int tmax,tmin;
            MandM(arr[i],arr[i+1],&tmax,&tmin);
            if(max<tmax)max=tmax;
            if(min>tmin)min=tmin;
        }
    }
    cout<<max<<" "<<min<<endl;

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int t=1;
    // cin>>t;
    int arr[]={10,20,100,5,1,40,25,150};
    int arr2[]={646, 12, 683, 530, 934, 407, 201, 208, 76, 824, 19, 144, 831, 564, 892,
    659, 144, 570, 940, 376, 1001, 70, 442, 270, 63, 169, 82, 768, 485, 546, 728, 90, 478,
    484, 961, 165, 585, 22, 450, 54, 898, 651, 291, 218, 776, 332, 680, 790, 230, 356, 203};
    while(t--)
    {
        solve(arr,8);
        solve(arr,51);
    }
}

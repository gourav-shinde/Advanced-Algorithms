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

void solve(int *arr,int size)
{
    int count=0;
    for(int i=1;i<size;++i){
        int j=i-1;
        while(j>=0){
            if(arr[j]>arr[i]){
                ++count;
                swap(arr[j],arr[i]);
                j--;
                i--;
            }
            else{
                break;
            }
        }
    }
    print_arr(arr,size);
    cout<<endl;
    cout<<"Swaps made "<<count<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int t=1;
    // cin>>t;
    int arr[]={646, 12, 683, 530, 934, 407, 201, 208, 76, 824, 19, 144, 831, 564, 892,
    659, 144, 570, 940, 376, 1001, 70, 442, 270, 63, 169, 82, 768, 485, 546, 728, 90, 478,
    484, 961, 165, 585, 22, 450, 54, 898, 651, 291, 218, 776, 332, 680, 790, 230, 356, 203};
    int arr2[]={1000, 995, 990, 985, 980, 975, 970, 965, 960, 955, 950, 945, 940, 935, 930, 925,
     920, 915, 910, 905, 900, 895, 890, 885, 880, 875, 870, 865, 860, 855, 850, 845, 840, 835, 
     830, 825, 820, 815, 810, 805, 800, 795, 790, 785, 780, 775, 770, 765, 760, 755, 750};
    while(t--)
    {
        solve(arr,51);
        solve(arr2,51);
    }
    
}

#include <iostream>
using namespace std;
int binSear(int *arr, int l, int h, int key){
    if(l>h)return -1;
    // cout<<l<<" "<<h<<endl;
    if(l==h){
        if(arr[l]==key)
            return l;
        else
            return -1;
    }
    
    int mid=(l+h)/2;
    
    // cout<<"#"<<key<<" "<<arr[mid]<<endl;
    if(key>arr[mid]){
        // cout<<"key smaller"<<endl;
        return binSear(arr,mid+1,h,key);
    }
    else
    {
        return binSear(arr,l,mid,key);
    }
    
}

int main() {
	// your code goes here
	int arr[6]={1,2,3,5,6,7};
	
	cout<<binSear(arr,0,5,1)<<endl;
    cout<<binSear(arr,0,5,2)<<endl;
    cout<<binSear(arr,0,5,3)<<endl;
    cout<<binSear(arr,0,5,5)<<endl;
    cout<<binSear(arr,0,5,6)<<endl;
    cout<<binSear(arr,0,5,7)<<endl;
    cout<<binSear(arr,0,5,25)<<endl;
	return 0;
}

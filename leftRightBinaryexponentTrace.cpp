#include <bits/stdc++.h>
using namespace std;


int bin(int n){
    if(n==0)return 0;
    if(n%2==1){
        int temp=bin(n/2)*2;
        cout<<"1 "<<temp+1<<endl;
        return (temp)+1;
    }
    else{
        int temp=bin(n/2)*2;
        cout<<"0 "<<temp<<endl;
        return temp;
    }
}

int main() {
	// your code goes here
	cout<<bin(888);
	return 0;
}

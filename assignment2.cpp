#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

#define deb(i) cout<<#i<<":"<<i<<endl;
#define fo(i,n) for(int j=i;j<n;j++)

// generate random number which is not divisible by 3 and 5
ull generateNumber(){
    ull min=7000,max=10000,temp;
    do{
        temp = min + (rand() % static_cast<int>(max - min + 1));   
    }while(temp%2==0 || temp%5==0);
    return temp;
}
//power function with mod n
ull modulo_power(ull base,ull powerr, ull modulus){
    //left to right binary method
    int ans = 1;
    while (powerr > 0) {
        if (powerr & 1 == 1) 
        {
            ans = (ans * base)%modulus;
        }
        base = (base * base)%modulus;
        powerr = powerr >> 1; 
    }
    return ans;
}


//check whther the number is prime or not
bool millarRabinPrimalityTest(ull number){
    // cout<<"miller rabine test called\n";
    ull min=2,max=number-2,k=number-1;
    ull a=min+(rand() % static_cast<ull>(max - min + 1));

    if(number==2 ||number==3)return true;
    
    //fermat's little theorem

    ull temp=modulo_power(a,k,number);
   
    if(temp!=1){
        //  cout<<"failed fermats\n";
         return false;
    }
    
    //other tests
    while(k%2==0){
        k/=2;
        if(temp==number-1){
            return true;
        }
        else if(temp!=1){
            // cout<<"failed others\n";
            return false;
        }
    }
    return true;
}

//repeat miller rabin test to rampu up correctness
bool MillerRepeat(ull number){
    // cout<<"MRepeat called\n";
    for(int i=0;i<100;++i){
        if(millarRabinPrimalityTest(number)==false){
            return false;
        }
    }
    return true;
}

//get large prime number
ull getNumber(){
    // cout<<"Get Number called\n";
    ull temp;
    do{
        temp=generateNumber();
    }while(MillerRepeat(temp)==false);
    return temp;
}



//get input string and convert to BEARCATII
ull getInput(){
 string input;
 cout<<"Enter message to Encode(all uppercase): ";
 cin>>input;
 ull bearcatii=0;
 for(int i=0;i<input.length();++i){
     bearcatii=bearcatii+(int(toupper(input[i]))-int('A'))*pow(26,i);
 }
 return bearcatii;
}

//covert to string from BEARCATTI format
string getOutput(ull bearcatii){
    string ans="";
    while(bearcatii!=0){
        int temp=bearcatii%26;
        bearcatii/=26;
        ans+=char(temp+int('A'));
    }
    return ans;
}
int gcd(ull a, ull b)
{
    // cout<<a<<" "<<b<<endl;
    if(b==0)return a;
    return gcd(b,a%b);

}

ll extendedEuclidGCD(ll a,ll b,ll *s,ll *t){
    // cout<<"\na& b "<<a<<" "<<b<<endl;
    if(b==0){
        *s=0;*t=1;
        // cout<<"okay?\n";
        return a;
    }
    ll x1, y1; // To store results of recursive call
    ll gcd = extendedEuclidGCD(b, a%b, &x1, &y1);
 
    // cout<<"S "<<x1<<"  T "<<y1<<" Quotient "<<a/b<<endl;
    if(a/b!=0){
    *s = y1 - (a/b) * x1;
    *t = x1;
    }
    else{
        *s=x1;*t=y1;
    }
    // cout<<"S "<<*s<<"  T "<<*t<<endl;
    return gcd;
}

int findDecryptionKey(ull e, ull n){
    ll s=0,t=0;
    // cout<<e<<" "<<n<<endl;
    ull g=extendedEuclidGCD(e,n,&s,&t);
    // cout<<s<<" "<<t<<" "<<g<<endl;
    return n+s;
}

ull encrypt(ull message,ull encryptionKey,ull modulus){
    return modulo_power(message,encryptionKey,modulus);
}

ull decrypt(ull encryptedMessage,ull decryptionKey,ull modulus){
    return modulo_power(encryptedMessage,decryptionKey,modulus);
}

void RSA(){
    ull p,q;
    ull encryptionKey;
    cout<<"Enter Encryption key: ";
    cin>>encryptionKey;
    cout<<"Finding coprime p and q values\n";
    p=7757;
    q=7993;
    while(true){
        p=getNumber();
        q=getNumber();
        ull totientFunction=(p-1)*(q-1);
        if(gcd(encryptionKey,totientFunction)<=1){
            break;
        }
    }
    cout<<"Values Found! p: "<<p<<" q: "<<q<<endl;
    cout<<"n=p*q: "<<p*q<<endl;;
    int decryptionKey=findDecryptionKey(encryptionKey,(p-1)*(q-1));
    cout<<"Decryption key is: "<<decryptionKey<<endl;
    ull message=getInput();
    cout<<"Bearcatti msg format: "<<message<<endl;
    if(message<p*q){
        cout<<"RSA applicable with this message\n";
    }
    ull encryptedtext=encrypt(message,encryptionKey,p*q);
    cout<<"Encrypted text: "<<encryptedtext<<endl;
    ull decryptedBearcatii=decrypt(encryptedtext,decryptionKey,p*q);
    cout<<"dcryrepted bearcatti "<<decryptedBearcatii<<endl;
    cout<<"Decrpted text: "<<getOutput(decryptedBearcatii);
    
}
void solve()
{
    
  RSA();
    

}

int main()
{
        solve();
        cout<<endl;
}

// TÍNH LŨY THỪA

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)

ll powMod(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    ll half = powMod(a, b/2);
    if(b % 2 == 0){
        return (half % mod * half % mod) % mod;
    }
    else{
        return ((half % mod * half % mod) % mod * a) % mod;
    }
}
int main(){
    ll a; ll b;
    while(cin >> a >> b){
    	if(a == 0 && b == 0) break;
        cout << powMod(a, b) << endl;
    }
    return 0;
}
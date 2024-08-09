#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mod (ll)(1e9 + 7)
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		ll F[n+5]; // F[i] so cach buoc len bang i
		F[0] = 1; F[1] = 1;
		for(int i =1; i <=n; i++){
			F[i] = 0;
			for(int j = i-1; j >=max(i-k, 0); j--){
				F[i] = (F[i] % mod + F[j] % mod) % mod;
			}
		}
		cout << F[n] << endl;
	}
	return 0;
}
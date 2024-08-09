#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n+1];
		for(int i =1; i <=n; i++){
			cin >> a[i];
		}
		ll F[k+1]; //cach tao ra tong i 
		F[0] = 1;
		for(int i =1; i <=k; i++){
			F[i] = 0;
			for(int j =1; j <=n; j++){
				if(i >= a[j]){
					F[i] = (F[i] % mod + F[i-a[j]] % mod) % mod;
				}
			}
		}
		cout << F[k] << endl;
	}
	return 0;
}

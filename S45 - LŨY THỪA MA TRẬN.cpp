#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)

int n; ll k;

struct matrix{
	ll a[15][15];
	friend matrix operator * (matrix x, matrix y){
		matrix z;
		for(int i =0; i <n; i++){
			for(int j =0; j <n; j++){
				z.a[i][j] = 0;
				for(int k =0; k <n; k++){
					z.a[i][j] += x.a[i][k] * y.a[k][j];
					z.a[i][j] %= mod;
				}
			}
		}
		return z;
	}
};

matrix powMod(matrix x, ll k){
	if(k == 1) return x;
	matrix half = powMod(x, k/2);
	if(k % 2 == 0){
		return half * half;
	}
	else{
		return half * half * x;
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		matrix x;
		for(int i =0; i <n; i++){
			for(int j =0; j <n; j++){
				cin >> x.a[i][j];
			}
		}
		matrix res = powMod(x, k);
		ll ans = 0;
		for(int i =0; i <n; i++){
			ans += res.a[i][n-1];
			ans %= mod;
		}
		cout << ans << endl;
	}
	return 0;
}

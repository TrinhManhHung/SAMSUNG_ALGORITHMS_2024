//SỐ FIBONACCI - VER 2 khi mod lên tới 1e12

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(1000000000019)

//// Hàm nhân số lớn theo modulo an toàn
ll multiple(ll a, ll b){
	ll res = 0;
	a %= mod;
	while(b > 0){
		if(b % 2 == 1){
			res = (res + a) % mod;
		}
		a = (a * 2) % mod;
		b /= 2;
	}
	return res;
}
struct Matrix{
	ll a[2][2];
	friend Matrix operator * (Matrix x, Matrix y){
		Matrix z;
		for(int i =0; i <2; i++){
			for(int j =0; j <2; j++){
				z.a[i][j] = 0;
				for(int k =0; k <2; k++){
					z.a[i][j] = (z.a[i][j] % mod + multiple(x.a[i][k], y.a[k][j])) % mod; 
				}
			}
		}
		return z;
	}
};

Matrix powMod(Matrix a, ll n){
	if(n == 1) return a;
	Matrix half = powMod(a, n/2);
	if(n % 2 == 0){
		return half * half;
	}
	else
		return half * half * a;
}

int main(){
//	faster();
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		if(n == 0){
			cout << 1 << "\n";
		}
		else{
			Matrix x;
			x.a[0][0] = 0; x.a[0][1] = 1;
			x.a[1][0] = 1; x.a[1][1] = 1;
			Matrix res = powMod(x, n);
			cout << res.a[1][1] << "\n";
		}
	}
	return 0;
}


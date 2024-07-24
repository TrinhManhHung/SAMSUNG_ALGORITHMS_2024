//SỐ FIBONACCI THỨ N

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class matrix{
	public:
		ll a[2][2];
		friend matrix operator * (matrix x, matrix y){
			matrix z;
			for(int i=0; i<2; i++){
				for(int j=0; j<2; j++){
					ll tmp = 0;
					for(int k=0; k<2; k++){
						tmp += x.a[i][k] * y.a[k][j];
						tmp %= mod;
					}
					z.a[i][j] = tmp;
				}
			}
			return z;
		}
};

matrix powMod(matrix x, ll n){
	if(n == 1) return x;
	matrix half = powMod(x, n/2);
	if(n % 2 == 0) 
		return half * half;
	else{
		return half * half * x;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		matrix x;
		x.a[0][0] = 0;   x.a[0][1] = 1;
		x.a[1][0] = 1;   x.a[1][1] = 1;
		matrix res = powMod(x, n);
		cout << res.a[1][0] << endl;
	}
	return 0;
}

//LŨY THỪA MA TRẬN

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n; ll k; 
class matrix{
	public:
		ll a[15][15];
		friend matrix operator * (matrix x, matrix y){
			matrix z;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					ll tmp = 0;
					for(int k=0; k<n; k++){
						tmp += x.a[i][k] * y.a[k][j];
						tmp %= mod;
					}
					z.a[i][j] = tmp;
				}
			}
			return z;
		}
};

matrix powMod(matrix x, ll k){
	if(k == 1) return x;
	matrix half = powMod(x, k/2);
	if(k % 2 == 0) 
		return half * half;
	else{
		return half * half * x;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		matrix x;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> x.a[i][j];
			}
		}
		
		matrix res = powMod(x, k);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << res.a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

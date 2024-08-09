#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ll res = 1;
		for(ll i =1; i <=n; i++){
			res = res * i / (gcd(res, i));
		}
		cout << res << endl;
	}
	return 0;
}


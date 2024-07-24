#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ll a[n+1], b[n+1];
		for(int i =1; i <=n; i++) cin >> a[i];
		b[0] = a[1]; b[n] = a[n];
		for(int i =1; i <n; i++){
			b[i] = lcm(a[i], a[i+1]);
		}
		for(auto x : b) cout << x << " ";
		cout << endl;
	}
	return 0;
}
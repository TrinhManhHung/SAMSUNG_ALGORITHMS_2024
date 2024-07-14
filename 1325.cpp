//Gap doi day so

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[51]; //f[i] luu vi tri k = 2 mu i
void init(){
	f[1] = 1;
	for(int i=2; i<=50; i++) {
		f[i] = f[i-1] << 1;
	}
}
void solve(int n, ll k){
	for(int i=n; i>=1; i--){
		if(k == f[i]){
			cout << i << endl;
			return;
		}
		else if(k > f[i]){
			k -= f[i];
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; ll k; cin >> n >> k;
		init();
		solve(n, k);
	}
	return 0;
}

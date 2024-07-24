//DÃY XÂU FIBONACCI

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fb[93]; //f[i] so fibo thu i
void init(){
	fb[1] = 1;
	fb[2] = 1;
	for(int i=3; i<=92; i++) fb[i] = fb[i-1] + fb[i-2];
}
int solve(int n, ll k){
	if(n < 3) return n;
	if(k > fb[n-2]) return solve(n-1, k - fb[n-2]);
	else return solve(n-2, k);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; ll k; cin >> n >> k;
		init();
		int res = solve(n, k);
		if(res == 1) cout << 'A';
		else cout << 'B';
		cout << endl;
	}
	return 0;
}

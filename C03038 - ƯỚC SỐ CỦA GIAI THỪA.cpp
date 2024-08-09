
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mod (ll)(1e9 + 7)

int solve(int n, int p){
	int res = 0;
	while(n){
		res += n / p;
		n /= p;
	}
	return res;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, p; cin >> n >> p;
		cout << solve(n, p) << endl;
	}
	return 0;
}


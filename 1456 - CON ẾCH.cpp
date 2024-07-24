//CON ẾCH
#include <bits/stdc++.h>
using namespace std;

int main(){
	long long dp[55]; // dp[i] so cach ech nhay den dinh i
	dp[0] = 1; dp[1] = 1; dp[2] = 2;
	for(int i=3; i<=50; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}

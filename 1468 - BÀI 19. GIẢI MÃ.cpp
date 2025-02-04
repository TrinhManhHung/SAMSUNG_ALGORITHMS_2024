#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define MOD (ll)1e9 + 7;
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush

void solve() {
	string s; cin >> s;
	int n = s.sz;
	s = "0" + s;
	ll dp[n+1] = {0};
	dp[0] = 1;
	if(s[1] == '0'){
		cout << 0 << endl;
		return;
	}
	for(int i =1; i <=n; i++){
		if(s[i] != '0') dp[i] += dp[i-1];
		int tmp = (s[i-1] - '0') * 10 + (s[i]-'0');
		if(tmp >= 10 && tmp <= 26){
			dp[i] += dp[i-2];
		}
	}
	cout << dp[n] << endl;
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.out", "w", stdout);
  	}
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/

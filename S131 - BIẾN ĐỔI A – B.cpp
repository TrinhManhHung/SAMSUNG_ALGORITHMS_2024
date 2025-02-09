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
#define pll pair<ll, ll>
#define MOD (ll)(1e9 + 7)
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define REP(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 1000005;

void solve(){
	string s; cin >> s;
	int n = s.sz;
	s = " " + s;
	int dp[n+1][2]; memset(dp, 0, sizeof(dp));
	//dp[i][0] chi phi bien doi xau si thanh A
	//dp[i][1] chi phi bien doi xau si thanh B
	FOR(i, 1, n){
		if(s[i] == 'A'){
			dp[i][0] = dp[i-1][0];
			dp[i][1] = min(dp[i-1][1] +1, dp[i-1][0] +1);
		}
		else{
			dp[i][0] = min(dp[i-1][0] +1, dp[i-1][1] +1);
			dp[i][1] = dp[i-1][1];
		}
//		cout << dp[i][0] << " " << dp[i][1] << endl;
	}
	cout << min(dp[n][0], dp[n][1] + 1) << endl;
}

int main(){
    faster();
    if(fopen("WORK.inp", "r")){
  		freopen("WORK.inp", "r", stdin);
  		freopen("WORK.out", "w", stdout);
  	}
//    int t; cin >> t;
//    while(t--){
        solve();
//    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/

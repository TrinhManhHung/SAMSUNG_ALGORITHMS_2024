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

int dp[105]; // dp[i] chi phi it nhat tao ra i kytu giong nhau
void solve(){
	int n; cin >> n;
	int x, y, z; cin >> x >> y >> z;
	dp[0] = 0;
	dp[1] = x;
	for(int i =2; i <=n; i++){
		if(i % 2 == 0){
			dp[i] = min(dp[i-1] + x, dp[i/2] + z);
		}
		else{
			dp[i] = min(dp[i-1] + x, dp[i/2+1] + z + y);
		}
	}
	cout << dp[n] << endl;
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.inp", "w", stdout);
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

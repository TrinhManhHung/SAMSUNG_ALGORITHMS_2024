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
const int maxn = 100005;
const int inf = -1e9;
int dp[maxn]; //dp[i] max money khi happiness = i
void solve(){
	int c, m; cin >> c >> m;
	int ans = c % (m + 1);
	if(ans >=1 && ans <=m) cout << "First\n";
	else cout << "Second\n";
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

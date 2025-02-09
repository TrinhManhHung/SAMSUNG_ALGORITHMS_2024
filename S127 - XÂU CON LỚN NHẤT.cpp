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

bool cmp(pair<string, int> a, pair<string, int> b){
	return a.se < b.se;	
}

void solve(){
	string s; cin >> s;
	reverse(s.begin(), s.end());
	string res = "a";
	FOR(i, 0, s.sz-1){
		if(s[i] >= res[res.sz-1]) res += s[i];
	}
	REP(i, res.sz-1, 1) cout << res[i];
	cout << endl;
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
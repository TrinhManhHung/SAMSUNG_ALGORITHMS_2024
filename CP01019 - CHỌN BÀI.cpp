#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define INF INT_MAX
const int maxn = 1e5;
const ll MOD = 1e9 + 7;

ll mul(ll a, ll b){
	ll res = a % MOD * b % MOD;
	res %= MOD;
	return res;
}

void solve(){
	int n; cin >> n;
	ll a[n];
	FOR(i, 0, n-1) cin >> a[i];
	sort(a, a+n);
	
	ll res = 1;
	FOR(i, 0, n-1){
		int idx = upper_bound(a, a+n, i) - a;
//		idx--;
		if(idx - i < 1){
			cout << 0 << endl;
			return;
		}
		res = mul(res, (ll)(idx - i));
//		cout << res << endl;
	}
	
	cout << res << endl;
}

int main() {
    faster();
    if(fopen("HungHot.inp", "r")){
    	freopen("HungHot.inp", "r", stdin);
    	freopen("HungHot.out", "w", stdout);
	}
    int t = 1; 
	cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/
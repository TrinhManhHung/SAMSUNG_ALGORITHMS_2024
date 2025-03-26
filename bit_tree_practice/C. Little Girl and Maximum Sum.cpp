//https://codeforces.com/contest/276/problem/C

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
const int maxn = 200005;

int n, q; 
int BIT[maxn];

void update(int pos, int val){
	for(; pos <= n; pos += pos & (-pos)){
		BIT[pos] += val;
	}
}

int getSum(int pos){
	int res = 0;
	for(; pos > 0; pos -= pos & (-pos)){
		res += BIT[pos];
	}
	return res;
}

void solve(){
	cin >> n >> q;
	int a[n+1];
	FOR(i, 1, n) cin >> a[i];
	while(q--){
		int l, r; cin >> l >> r;
		update(l, 1);
		update(r+1, -1);
	}
	
	int b[n+1];
	FOR(i, 1, n) b[i] = getSum(i);
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	
	ll res = 0;
	FOR(i, 1, n){
		res += 1ll * a[i] * b[i];
//		SHOW2(a[i], b[i]);
	}
	cout << res << endl;
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
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
#define pii pair<int, int>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define INF INT_MAX
const int maxn = 1e6;
int n;
int BIT[maxn+5];

void update(int pos){
	for(int i = pos - 1; i >= 1; i -= (i & -i)){
		BIT[i]++;
	}
}

ll get(int pos){
	ll ans = 0;
	for(int i = pos+1; i <=maxn; i += (i & -i)){
		ans += BIT[i];
	}	
	return ans;
}


void solve() {
	int n; cin >> n;
	int a[n+1];
	vi idxOdd;
	FOR(i, 1, n){
		cin >> a[i];
		if(a[i] % 2 == 1) idxOdd.pb(i);
	}	
	idxOdd.pb(n+1);
	
//	for(auto x : idxOdd) cout << x << " ";
	
	FOR(i, 1, idxOdd[0]-1){
		update(a[i]);
	}
	
	ll ans = 0;
	for(int i =0; i <idxOdd.sz-1; i++){
		int k1 = idxOdd[i];
		int k2 = idxOdd[i+1];
		FOR(j, k1+1, k2-1){
			ans += get(a[j]);
//			cout << a[j] << endl;
		}
		FOR(j, k1+1, k2-1){
			update(a[j]);
		}
	}
	
	cout << ans << endl;
}
 
int main() {
    faster();
//    int t; cin >> t;
//    while (t--) {
        solve();
//    }
    return 0;
}
/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/



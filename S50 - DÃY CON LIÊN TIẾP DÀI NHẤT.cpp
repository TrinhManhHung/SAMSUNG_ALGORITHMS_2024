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
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 100000;

void solve(){
	int n, k; cin >> n >> k;
	ll a[n+1], sum[n+1] = {0};
	ll b[n+1] = {0};
	FOR(i, 1, n){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
		b[i] = sum[i] - 1ll * i * k;
//		cout << b[i] << " ";
	}
	
	int res = 0;
	vector<int> M;
	FOR(i, 0, n){
		if(M.empty() || b[i] < b[M.back()]){
			M.pb(i);
		}
	}
	
	FOD(j, n, 0){
		while(!M.empty() && b[j] >= b[M.back()]){
			res = max(res, j-M.back());
			M.pop_back();
		}
	}
	cout << res << endl;
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
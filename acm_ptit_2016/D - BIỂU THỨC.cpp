//https://www.spoj.com/PTIT/problems/PTIT016D/

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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF INT_MAX
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve(){
	int n, k; cin >> n >> k;
	int a[n+1];
	FOR(i, 1, n) cin >> a[i];
	
	sort(a+2, a+n+1, greater<int>());
	ll res = a[1];
	FOR(i, 2, k+1){
		res += a[i];
	}
	FOR(i, k+2, n){
		res -= a[i];
	}
	cout << res << endl;
}

int main(){
    faster();
    int t = 1;
//    cin >> t;
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

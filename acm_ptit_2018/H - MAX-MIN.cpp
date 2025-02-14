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
const int maxn = 1e6;

void solve(){
	int n; cin >> n;
	int a[n+1];
	FOR(i, 1, n) cin >> a[i];
	
	vi res;
	
	int curmax = 0;
	FOR(k, 1, n){
		curmax = 0;
		deque<int> dq;
		
		FOR(i, 1, k){
			while(!dq.empty() && a[dq.back()] >= a[i]){
				dq.pop_back();
			}
			dq.push_back(i);
		}
		curmax = max(curmax, a[dq.front()]);
		FOR(i, k+1, n){
			while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
			while(!dq.empty() && a[dq.back()] >= a[i]){
				dq.pop_back();
			}
			dq.push_back(i);
			curmax = max(curmax, a[dq.front()]);
		}
		res.pb(curmax);
	}
	
	for(auto x : res) cout << x << " ";
	cout << endl;
}

int main(){
    faster();
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


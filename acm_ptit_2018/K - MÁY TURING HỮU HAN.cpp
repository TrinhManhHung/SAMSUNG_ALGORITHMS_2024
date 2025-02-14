/*
https://www.spoj.com/PTIT/problems/PTIT018K/
*/
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
	int n, P, Q; cin >> n >> P >> Q;
	int a[n+5], cnt[n+5]; //cnt[i] so buoc de di tu i den Q 
	FOR(i, 1, n){
		cin >> a[i];
		cnt[i] = 1005;
	}
	cnt[Q] = 0;
	unordered_map<int, int> last, cur;
	last[a[Q]] = 1;
	int curStep = 1; //tinh xem nhung diem nao can dung curStep de di den Q
	while(cnt[P] == 1005){
		FOR(i, 1, n){
			if(cnt[i] == curStep-1){
				cnt[i-1] = min(cnt[i-1], curStep);
				cnt[i+1] = min(cnt[i+1], curStep);
				if(cnt[i-1] == curStep) cur[a[i-1]] = 1;
				if(cnt[i+1] == curStep) cur[a[i+1]] = 1;
			}
			if(last[a[i]] == 1){
				cnt[i] = min(cnt[i], curStep);
			}
		}
		last = cur;
		cur.clear();
		curStep++;
	}
	cout << cnt[P] << endl;
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


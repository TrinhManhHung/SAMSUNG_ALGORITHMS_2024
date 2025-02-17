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
const int maxn = 300000;

void solve() {
	int n; cin >> n;
	vector<string> vs(n+1);
	vector<int> per(n+1);
	vvi digits(n+1, vector<int>(n+1));
	
	FOR(i, 1, n){
		string s; cin >> s;
		vs[i] = s;
		per[i] = i;
	}
	
	FOR(i, 1, n){
		FOR(j, 1, n){
			int cnt[27] = {0};
			for(auto x : vs[i]) cnt[x-'A'] = 1; 
			for(auto x : vs[j]){
				if(cnt[x-'A'] == 1) digits[i][j]++;
			}
		}
	}

	int res = 50000;
	do{
//		FOR(i, 1, n){
//			cout << per[i] << " " << vs[per[i]] << " ";
//		}
//		cout << endl;
		
		int cnt = 0;
		FOR(i, 1, n-1){
			cnt += digits[per[i]][per[i+1]];
		}
		
		res = min(res, cnt);
//		cout << cnt << endl;
	}while(next_permutation(per.begin()+1, per.begin()+n+1));
	
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


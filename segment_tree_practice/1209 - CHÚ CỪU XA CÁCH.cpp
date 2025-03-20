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
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 1000;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

map<pii, vector<pii>> mp;
int n, m, k; //n: size, k: so cuu, m: so rao

int a[105][105];
int visited[105][105];

void init(){
	cin >> n >> k >> m;
	memset(a, 0, sizeof(a));
	memset(visited, 0, sizeof(visited));
	
	FOR(i, 1, m){
		int u, v, x, y; cin >> u >> v >> x >> y;
		mp[{u, v}].pb({x, y});
		mp[{x, y}].pb({u, v});
	}
	FOR(i, 1, k){
		int x, y; cin >> x >> y;
		a[x][y] = 1;
	}		
}

//dem so luong cuu ko xa cach
int dfs(int i, int j){
	int cnt = 0;
	FOR(idx, 0, 3){
		int next_i = i + dx[idx];
		int next_j = j + dy[idx];
		
		bool check = true;
		if(mp.find({i, j}) != mp.end()){
			for(auto x : mp[{i, j}]){
				if(x.fi == next_i && x.se == next_j){
					check = false;
					break;
				}
			}
		}
		
		if(check && next_i >= 1 && next_i <=n && next_j >= 1 && next_j <= n && !visited[next_i][next_j]){
			visited[next_i][next_j] = 1;
			if(a[next_i][next_j] == 1) cnt++;
			cnt += dfs(next_i, next_j);
		}
	}
	return cnt;
}

void solve(){
	init();
	
	int ans = 0;
	FOR(i, 1, n){
		FOR(j, 1, n){
			if(a[i][j] == 1){
				memset(visited, 0, sizeof(visited));
				visited[i][j] = 1;
				int cnt = dfs(i, j);
				ans += k -cnt -1; 
			}
		}
	}
	
	ans /= 2;
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

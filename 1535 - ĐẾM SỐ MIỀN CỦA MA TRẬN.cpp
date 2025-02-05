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
#define MOD (ll)1e9 + 7;
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define REP(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 2e5 + 5;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m; 
int a[105][105]; 
int visited[105][105];
bool check;

void dfs(int i, int j){
	visited[i][j] = 1;
//	if(i == 1 || i == n || j == 1 || j == m) check = false;
	FOR(k, 0, 7){
		int nexti = i + dx[k];
		int nextj = j + dy[k];
		if(nexti >= 1 && nexti <= n && nextj >= 1 && nextj <= m && !visited[nexti][nextj] && a[nexti][nextj] == 1) dfs(i+dx[k], j+dy[k]);
	}
}

void solve(){
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	memset(visited, 0, sizeof(visited));
	
	FOR(i, 1, n){
		FOR(j, 1, m){
			cin >> a[i][j];
		}
	}
	
	int res = 0;
	FOR(i, 1, n){
		FOR(j, 1, m){
			if(a[i][j] == 1 && !visited[i][j]){
				dfs(i, j);
				res++;
			}
		}
	}
	cout << res << endl;
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.out", "w", stdout);
  	}
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

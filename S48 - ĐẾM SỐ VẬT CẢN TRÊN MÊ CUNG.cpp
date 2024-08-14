#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int n, m; 
int a[505][505];

bool check(int i, int j){
	if(i >=1 && i <=n && j >=1 && j <=m && a[i][j] == 1) return true;
	return false;
}

void DFS(int i, int j){
	for(int k =0; k <4; k++){
		int nexti = i + dx[k];
		int nextj = j + dy[k];
		if(check(nexti, nextj)){
			a[nexti][nextj] = 0;
			DFS(nexti, nextj);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i =1; i <=n; i++){
		for(int j =1; j <=m; j++){
			char x; cin >> x;
			if(x == '#') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	
	int cnt = 0;
	for(int i =1; i <=n; i++){
		for(int j =1; j <=m; j++){
			if(a[i][j] == 1){
				cnt++;
				a[i][j] = 0;
				DFS(i, j);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

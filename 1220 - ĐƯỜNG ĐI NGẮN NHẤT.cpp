//ĐƯỜNG ĐI NGẮN NHẤT

#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105][105];
int d[105][105];
int q;
int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			d[i][j] = 1e8;
		}
		d[i][i] = 0;
	}
	for(int i=1; i<=m; i++){
		int u, v, w; cin >> u >> v >> w;
		d[u][v] = d[v][u] = w;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				d[j][k] =min(d[j][k] ,d[j][i] + d[i][k]);
			}
		}
	}
	int q; cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		cout << d[x][y] << endl;
	}
	return 0;
}
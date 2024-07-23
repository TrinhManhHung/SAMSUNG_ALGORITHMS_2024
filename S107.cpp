// ĐƯỜNG ĐI NHỎ NHẤT - 1

#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int dx[4] = {1, 0, 1};
int dy[4] = {0, 1, 1};

const int inf = 1e9;
bool check(int i, int j, int n, int m){
    if(i >=1 && i <=n && j >=1 && j <=m) return true;
    return false;
}
void dijkstra(int a[][505], int n, int m){
    vector<vector<int>> d(n+1, vector<int>(m+1, inf));
    priority_queue <pipii, vector<pipii>, greater<pipii>> Q;
    //<khoang cach, a[i][j]>
    d[1][1] = a[1][1];
    Q.push({a[1][1], {1, 1}});
    while(!Q.empty()){
        auto top = Q.top(); Q.pop();
        int kc = top.fi;
        int cur_i = top.se.fi;
        int cur_j = top.se.se;
        if(kc > d[cur_i][cur_j]) continue;
        for(int k =0; k <3; k++){
            int next_i = cur_i + dx[k];
            int next_j = cur_j + dy[k];
            if(check(next_i, next_j, n, m)){
                if(d[next_i][next_j] > d[cur_i][cur_j] + a[next_i][next_j]){
                    d[next_i][next_j] = d[cur_i][cur_j] + a[next_i][next_j];
                    Q.push({d[next_i][next_j], {next_i, next_j}});
                }
            }
        }
    }
    cout << d[n][m] << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        int a[505][505];
        int n, m; cin >> n >> m;
        for(int i =1; i <=n; i++){
            for(int j =1; j <=m; j++){
                cin >> a[i][j];
            }
        }
        dijkstra(a, n, m);
    }
    return 0;
}


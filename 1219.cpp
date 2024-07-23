//NỐI ĐIỂM

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
typedef pair<int, int> pii;
typedef pair<double, pii> pipii;

vector<pipii> adj; 
int parent[105];

//khoang cach
double distance(double x1, double y1, double x2, double y2){
	double tmp = (double)sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2-y1));
	return tmp;
}

//ktao
void Init(){
	//memset
	adj.clear();
	for(int i =1; i <=100; i++) parent[i] = i;
	//Nhap toa do cac dinh u vao ds dang: tmp[u]:<i(u), j(u)>
	int n; cin >> n;
	vector<pair<double, double>> tmp;
	tmp.pb({0, 0});
	for(int i =1; i <=n; i++){
		double x, y; cin >> x >> y;
		tmp.pb({x, y});
	}
	//Dua vao danh sach canh adj: <kc, <u,v>>
	for(int i =1; i <tmp.size(); i++){
		for(int j =i+1; j <tmp.size(); j++){
			double kc = distance(tmp[i].fi, tmp[i].se, tmp[j].fi, tmp[j].se);
			adj.pb({kc, {i, j}});
		}
	}
	sort(adj.begin(), adj.end(), [](pipii a, pipii b) {
		return a.fi < b.fi;
	});
}

//set union
int Find(int u){
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return false;
	
	if(u < v) parent[v] = u;
	else parent[u] = v;
	return true;
}

//kruskal
void kruskal(){
	double min_w = 0;
	for(auto x : adj){
		double w = x.fi;
		int u = x.se.fi; 
		int v = x.se.se;
		if(Union(u, v)) min_w += w;
	}
	cout <<fixed << setprecision(6) << min_w << endl;
}

int main(){
	int t; cin >> t;
	while(t--){
		Init();
		kruskal();
	}
	return 0;
}


// SEGMENT TREE + LAZY UPDATE

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 100005;
ll t[4*maxn], lazy[4*maxn];

void push(int id, int l, int r){
	if(lazy[id] != 0){
		t[id] += lazy[id];
		if(l != r){
			lazy[2*id+1] += lazy[id];
			lazy[2*id] += lazy[id];
		}
		lazy[id] = 0;
	}	
}
ll getMax(int id, int l, int r, int u, int v){
	if(v < u) return 0;
	push(id, l, r);
	if(l == u && r == v){
		return t[id];
	}
	else{
		int mid = (l + r) / 2;
		return max(getMax(2*id, l, mid, u, min(v, mid)),
					getMax(2*id+1, mid+1, r, max(u, mid+1), v));
	}
}
void update(int id, int l, int r, int u, int v, int k){
	push(id, l, r);
	if(v < u) return;
	if(l == u && r == v){
		lazy[id] += k;
		push(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	update(2*id, l, mid, u, min(v, mid), k);
	update(2*id + 1, mid+1, r, max(u, mid+1), v, k);
	t[id] = max(t[2*id], t[2*id + 1]);
}

int main(){
	int n, q; cin >> n >> q;
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int u, v, k; cin >> u >> v >> k;
			update(1, 1, n, u, v, k);
		}
		else{
			int u, v; cin >> u >> v;
			cout << getMax(1, 1, n, u, v) << endl;
		}
	}
	return 0;
}

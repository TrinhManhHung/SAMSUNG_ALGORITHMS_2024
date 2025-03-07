//https://codeforces.com/problemset/problem/380/C

//SEGMENT TREE

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1000000;

struct node{
	int open;
	int close;
	int ans;
};

node sumBra(const node a, const node b){
	node res;
	int mi = min(a.open, b.close);
	res.ans = a.ans + b.ans + mi;
	res.open = a.open + b.open - mi;
	res.close = a.close + b.close - mi;
	return res;
}

node t[4*maxn + 1]; 

void update(int v, int l, int r, int pos, char val){
	if(l == r){
		t[v] = {0, 0, 0};
		if(val == '(') t[v].open = 1;
		else if(val == ')') t[v].close = 1;
	}
	else{
		int mid = (l + r) / 2;
		if(pos <= mid) update(2*v, l, mid, pos, val);
		else if(pos > mid) update(2*v + 1, mid+1, r, pos, val);
		t[v] = sumBra(t[2*v], t[2*v + 1]);
	}
}

node get(int v, int l, int r, int x, int y){ //do dai day con dung trong doan [u, v]
	if(y < x) return {0, 0, 0};
	if(x == l && y == r) return t[v];
	else{
		int mid = (l + r) / 2;
		node Left = get(2*v, l, mid, x, min(y, mid));
		node Right = get(2*v + 1, mid+1, r, max(x, mid+1), y);
		return sumBra(Left, Right);
	}
}
int main(){
	string s; cin >> s; 
	int n = s.size();
	s = " " + s;
	for(int i =1; i <=n; i++){
		update(1, 1, n, i, s[i]);
	}
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		node res = get(1, 1, n, l, r);
		cout << res.ans * 2 << endl;
	}
	return 0;
}
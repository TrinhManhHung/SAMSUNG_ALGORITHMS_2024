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
#define INF 1e9

struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = right = NULL;
	}
};

node *insertNode(node *root, int key){
	if(root == NULL){
		root = new node(key);
	}
	else if(key > root->data){
		root->right = insertNode(root->right, key);
	}
	else{
		root->left = insertNode(root->left, key);
	}
	return root;
}

int cntTrungGian(node *root){
	if(root == NULL) return 0;
	if(root->left == NULL && root->right == NULL){
		return 0;
	}
	return 1 + cntTrungGian(root->left) + cntTrungGian(root->right);
}
void solve(){
	int n; cin >> n;
	node *root = NULL;
	for(int i =1; i <=n; i++){
		int x; cin >> x;
		root = insertNode(root, x);
	}
	cout << cntTrungGian(root) << endl;
}

int main(){
    faster();
    int t;
    cin >> t;
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



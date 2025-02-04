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
#define MOD (ll)(1e9 + 7)
#define INF 1e18

struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = NULL; right = NULL;
	}
};

void makeRoot(node *root, int u, int v, char c){
	if(c == 'L') root->left = new node(v);
	else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root->data == u){
		makeRoot(root, u, v, c);
	}
	insertNode(root->left, u, v, c);
	insertNode(root->right, u, v, c);
}

node *insertNode(node *root, int key){
	if(root == NULL){
		root = new node(key);
	}
	else if(key < root->data){
		root->left = insertNode(root->left, key);
	}
	else if(key > root->data){
		root->right = insertNode(root->right, key);
	}
	return root;
}

void inOrder(node *root){
	if(root == NULL) return;
	inOrder(root->left);
	inOrder(root->right);
	cout << root->data << " ";
}
void solve(){
	int n; cin >> n;
	node *root = NULL;
	for(int i =1; i <=n; i++){
		int x; cin >> x;
		if(root == NULL) root = new node(x);
		else insertNode(root, x);
	}
	inOrder(root);
	cout << endl;
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
  		freopen("HungHot.inp", "r", stdin);
  		freopen("HungHot.inp", "w", stdout);
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


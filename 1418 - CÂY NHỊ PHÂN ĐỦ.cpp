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

int maxHeight(node *root){
	if(root == NULL) return -1;
	return max(maxHeight(root->left) +1, maxHeight(root->right) +1);
}

bool checkFullTree(node *root){
	if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
		return false;
	if(root->left == NULL && root->right == NULL) return true;
	return (checkFullTree(root->left) && checkFullTree(root->right));
}
void solve(){
	int n; cin >> n;
	node *root = NULL;
	for(int i =1; i <=n; i++){
		int u, v; char c; cin >> u >> v >> c;
		if(root == NULL){
			root = new node(u);
			makeRoot(root, u, v, c);
		}
		else{
			insertNode(root, u, v, c);
		}
	}
	
	checkFullTree(root) == true? cout << "1\n" : cout << "0\n";
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
2
4
1 2 L 1 3 R 2 4 L 2 5 R
3
1 2 L 1 3 R 2 4 
**/


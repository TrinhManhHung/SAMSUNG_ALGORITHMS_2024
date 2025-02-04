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

int ans;
void maxSumPath(node *root, int cursum){
	ans = max(ans, max(0, cursum) + root->data);
	if(root == NULL) return;
	if(root->left != NULL){
		maxSumPath(root->left, max(cursum, 0));
	}
	if(root->right != NULL){
		maxSumPath(root->right, max(cursum, 0));
	}
}
//void solve(){
//	int n; cin >> n;
//	node *root = NULL;
//	for(int i =1; i <=n; i++){
//		int u, v; char c; cin >> u >> v >> c;
//		if(root == NULL){
//			root = new node(u);
//			makeRoot(root, u, v, c);
//		}
//		else{
//			insertNode(root, u, v, c);
//		}
//	}
//	
//	ans = -1e9;
//	maxSumPath(root, 0);
//	cout << ans << endl;
//}

void solve(){
	int n; cin >> n;
	set<int> se;
	for(int i =1; i <=n; i++){
		int u, v; char c; cin >> u >> v >> c;
		se.insert(u);
		se.insert(v);
	}
	for(auto x : se) cout << x << " ";
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
12
-15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L
**/


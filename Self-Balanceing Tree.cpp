#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <conio.h>

using namespace std;

struct node {
	node() {
		val = 10002;
		left = NULL;
		right = NULL;
		parents = NULL;
	}
	node(int v, node* p) {
		val = v;
		node* newLeft = new node;
		left = newLeft; newLeft->parents = this;
		node* newRight = new node;
		right = newRight; newRight->parents = this;
		parents = p;
	}
	int val;
	node* left;
	node* right;
	node* parents;
};

class AVLTree {
public:
	node* root;
	int size;
public:
	AVLTree() {
		size = 0;
		root = NULL;
	}
	bool isLeaf(node* n) {
		return n->val==10002;
	}
	int height(node* n) {
		if (isLeaf(n)) return 0;
		int max = height(n->left);
		int tmp = height(n->right);
		if (tmp>max) max = tmp;
		return max+1;
	}
	int depth(node* n) {
		if (n==root) return 0;
		return 1+depth(n->parents);
	}

	void left_left_balancing(node* subroot) {
		node* tmp1;
		int tmp2;
		tmp1 = subroot->left;
		subroot->left = subroot->left->left; subroot->left->parents = subroot;
		tmp2 = tmp1->val; tmp1->val = subroot->val; subroot->val = tmp2;
		tmp1->left = tmp1->right; tmp1->left->parents = tmp1;
		tmp1->right = subroot->right; subroot->right->parents = tmp1;
		subroot->right = tmp1; tmp1->parents = subroot;
	}
	void left_right_balancing(node* subroot) {
		node* tmp1, *tmp2;
		tmp1 = subroot->left; tmp2 = tmp1->right;
		subroot->left = tmp2; tmp2->parents = subroot;
		tmp1->right = tmp2->left; tmp2->left->parents = tmp1;
		tmp2->left = tmp1; tmp1->parents = tmp2;
		left_left_balancing(subroot);
	}
	void right_right_balancing(node* subroot) {
		node* tmp1;
		int tmp2;
		tmp1 = subroot->right;
		subroot->right = subroot->right->right; subroot->right->parents = subroot;
		tmp2 = tmp1->val; tmp1->val = subroot->val; subroot->val = tmp2;
		tmp1->right = tmp1->left; tmp1->right->parents = tmp1;
		tmp1->left = subroot->left; subroot->left->parents = tmp1;
		subroot->left = tmp1; tmp1->parents = subroot;
	}
	void right_left_balancing(node* subroot) {
		node* tmp1, *tmp2;
		tmp1 = subroot->right; tmp2 = tmp1->left;
		subroot->right = tmp2; tmp2->parents = subroot;
		tmp1->left = tmp2->right; tmp2->right->parents = tmp1;
		tmp2->right = tmp1; tmp1->parents = tmp2;
		right_right_balancing(subroot);
	}

	bool self_balancing(node* before, bool found) {
		if (isLeaf(before)) return found;
		if ((isLeaf(before->left) && isLeaf(before->right))) {
			return found;
		}
		if (found) return true;
		self_balancing(before->left, found);

		if (found) return true;
		self_balancing(before->right, found);

		if (found) return true;
		int std = height(before->left) - height(before->right);
		if (std>1 || std<-1) {
			found = true;
			int left1 = height(before->left);
			int right1 = height(before->right);
			if (left1>right1) {
				int left2 = height(before->left->left);
				int right2 = height(before->left->right);
				if (left2>right2) {
					left_left_balancing(before);
				} else {
					left_right_balancing(before);
				}
			} else {
				int left2 = height(before->right->left);
				int right2 = height(before->right->right);
				if (left2>right2) {
					right_left_balancing(before);
				} else {
					right_right_balancing(before);
				}
			}
		}
		return found;
	}
	node* search(int val) {
		node* p = root;
		if (p->val==val) return root;
		bool found = false;
		while (found==false && !isLeaf(p)) {
			if (val<p->val) p = p->left;
			else {
				if (val==p->val) {
					found = true;
					break;
				} 
				else p = p->right;				
			}
		}
		if (found) return p;
		else return NULL;
	}
	void insert(int val) {
		insert(root, val);
	}
	void insert(node* before, int val) {
		if (root==NULL) {
			root = new node(val, NULL);
			size++;
			return ;
		}
		if (isLeaf(before)) {
			node* tmp = before->parents;
			node* newNode = new node(val, before->parents);
			if (tmp->val>val) {
				tmp->left = newNode; 
			} else {
				tmp->right = newNode; 
			}
			size++;
			return ;
		}
		if (val>=before->val) insert(before->right, val);
		else insert(before->left, val);
		self_balancing(root, false);
	}
	void insert(node* n) {
		if (root==NULL) {
			insert(root,n->val);
			return;
		}
		node* p = root;
		while (!isLeaf(p)) {
			if (n->val<p->val) p = p->left;
			else {
				p = p->right;				
			}
		}
		node* tmp = p->parents;
		if (tmp->left==p) {
			tmp->left = n; n->parents = tmp;
		} else {
			tmp->right = n; n->parents = tmp;
		}
	}
	void remove(int val) {
		node* n = search(val);
		if (n==NULL) return;
		if (isLeaf(n->left) && isLeaf(n->right)) {
			if (n==root) {
				root = NULL; return;
			}
			node* tmp = n->parents;
			if (tmp->left==n) {
				tmp->left = n->left; tmp->left->parents = tmp;
			}
			else {
				tmp->right = n->right; tmp->right->parents = tmp;
			}
		} else {
			int left = height(n->left), right = height(n->right);
			node* tmp1, *tmp2;
			if (left>right) {
				tmp1 = n->left; tmp2 = tmp1->right; n->val = tmp1->val;
				n->left = tmp1->left; n->left->parents = n;
				insert(tmp2);
			} else {
				tmp1 = n->right; tmp2 = tmp1->left; n->val = tmp1->val;
				n->right = tmp1->right; n->right->parents = n;
				insert(tmp2);
			}
		}
		bool continued = self_balancing(root,false);
		while (continued) continued = self_balancing(root,false);
		size--;
	}
	// int drawInorder(node* before, int** fr, int r, int c) {
	// 	if (isLeaf(before)) {
	// 		fr[r][c] = before->val;
	// 		c++;
	// 		return c;
	// 	}
	// 	c = drawInorder(before->left,fr,r+1,c);
	// 	fr[r][c] = before->val;
	// 	c++;
	// 	c = drawInorder(before->right,fr,r+1,c);
	// 	return c;
	// }
	int inorder(node* before, int** fr, int j) {
		if (isLeaf(before)) {
			int i = depth(before);
			fr[i][j] = 10002; j++;
			return j;
		}
		j = inorder(before->left, fr, j);
		int i = depth(before);
		fr[i][j] = before->val;
		if (fr[i][j]>9) {
			fr[i][j+1] = 10003; j+=2;
		}
		else j++;
		j = inorder(before->right, fr, j);
		return j;
	}
	void draw() {
		if (root==NULL) return;
		int **frame;
		int col, row;
		col = 80; row = 15;
		frame = new int*[row];
		for (int i=0; i<row; i++) {
			frame[i] = new int[col];
			for (int j=0; j<col; j++) {
				frame[i][j] = 10001;
			}
		}
		//drawInorder(root, frame, 1, 1);
		inorder(root,frame,1);
		cout << endl << endl;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				if (frame[i][j] == 10002) cout << "o";
				else  if (frame[i][j]==10001) cout << " ";
				else if (frame[i][j]==10003) cout << "";
				else cout << frame[i][j];
			}
			cout << endl;
		}
		printInorder(root);
	}
	// void printInorder(node* n) {
	// 	if (isLeaf(n)) {
	// 		cout << n->val << " ";
	// 		return;
	// 	}
	// 	printInorder(n->left);
	// 	cout << n->val << " ";
	// 	printInorder(n->right);
	// }
	void printInorder(node* n) {
		stack<node*> s;
		do {
			while (!isLeaf(n)) {
				if(!isLeaf(n->right)) s.push(n->right);
				s.push(n);
				n = n->left;
			}
			cout << n->val << " "; 
			cout << s.top()->val << " ";
			n = s.top();
			n = n->right;
			s.pop();
			getch();
		} while(!s.empty());
	}
};

int main()
{
	srand(time(NULL));
	int n;
	AVLTree tree;
	cin >> n;
	for (int i=1; i<=n; i++) {
		//cin >> input;
		tree.insert(i);
	}
	tree.draw();
	cout << tree.size << endl;
	for (int i=1; i<2*n/3; i++) {
		tree.remove(rand()%n+1);
	}
	tree.draw();
	cout << tree.size;
}
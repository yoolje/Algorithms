#include <algorithm>
#include <cstdlib>
using namespace std;

typedef int KeyType;
struct Node
{
	KeyType key;
	int priority, size;
	Node* left, * right;

	// initialize
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
	// renew size
	void calcSize()
	{
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};
typedef pair<Node*, Node*> NodePair;

// root를 루트로 하는 treap을 key를 기준으로 쪼갠다.
NodePair split(Node* root, KeyType key)
{
	if (root == NULL) return NodePair(NULL, NULL);
	// root가 key 미만: 오른쪽 Subtree를 쪼갠다.
	if (root->key < key)
	{
		NodePair rightSubtree = split(root->right, key);
		root->setRight(rightSubtree.first);
		return NodePair(root, rightSubtree.second);
	}
	//root가 key 이상: 왼쪽 Subtree를 쪼갠다.
	else
	{
		NodePair leftSubtree = split(root->left, key);
		root->setLeft(leftSubtree.second);
		return NodePair(leftSubtree.first, root);
	}
}

// How to Use: root = insert(root, new Node(value));
Node* insert(Node* root, Node* node)
{
	if (root == NULL) return node;
	// node의 priority가 root의 priority보다 높다면
	// 해당 Subtree를 반으로 쪼개서 각각 자손으로 한다.
	if (root->priority < node->priority)
	{
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

// 두 treap A, B에 대해 max A < min B이면 둘을 합친다.
Node* merge(Node* A, Node* B)
{
	if (A == NULL) return B;
	if (B == NULL) return A;
	if (A->priority < B->priority)
	{
		B->setLeft(merge(A, B->left));
		return B;
	}
	else
	{
		A->setRight(merge(A->right, B));
		return A;
	}
}

// root를 루트로 하는 treap에서 key를 지우고 트립의 루트를 반환
Node* erase(Node* root, KeyType key)
{
	if (root == NULL) return root;
	if (root->key == key)
	{
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}

// root를 루트로 하는 treap의 k번째 원소를 반환
Node* kth(Node* root, int k)
{
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	else if (k == leftSize + 1) return root;
	else kth(root->right, k - leftSize - 1);
}

// root를 루트로 하는 treap에서 key보다 작은 원소의 개수를 반환
int countLessThan(Node* root, KeyType key)
{
	if (root == NULL) return 0;
	else if (root->key >= key)
		return countLessThan(root->left, key);
	else
	{
		int leftSize = (root->left ? root->left->size : 0);
		return leftSize + 1 + countLessThan(root->right, key);
	}
}

// root를 루트로 하는 treap에서 구간 [min, max)에 속하는 원소의 개수를 반환
int countInInterval(Node* root, KeyType min, KeyType max)
{
	return countLessThan(root, max) - countLessThan(root, min);
}

int main()
{


	return 0;
}
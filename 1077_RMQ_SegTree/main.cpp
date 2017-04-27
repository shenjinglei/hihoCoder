#include <iostream>
#include <algorithm>
#define MAX_N 100000

using namespace std;

const int INFINITE = 2147483647;
int N;	//the amount of goods
int weight[MAX_N];	//the weight of each good
struct SegTreeNode {
	int val;
}seg_tree[2 * MAX_N];


/*
构建区间树，最小值
[L,R] Array的区间
*/
void build(int root, int* Array, int l, int r){	
	if (l == r) {	//递归结束
		seg_tree[root].val = Array[l];
		return;
	}
	int mid = (l + r) / 2;	//后序遍历
	build(root * 2 + 1, Array, l, mid);
	build(root * 2 + 2, Array, mid + 1, r);
	seg_tree[root].val = min(seg_tree[root * 2 + 1].val, seg_tree[root * 2 + 2].val);
}

/*
'功能：线段树的区间查询
'root：当前线段树的根节点下标
'[L,R]: 当前节点所表示的区间
'[x,y]: 此次查询的区间
*/
int _query(int root, int l, int r, const int L, const int R) {
	//查询区间和当前节点区间没有交集
	if (r < L || R < l) {
		return INFINITE;
	}
	if (L <= l && r <= R) {
		return seg_tree[root].val;
	}
	int mid = (l + r) / 2;
	return min(_query(root * 2 + 1, l, mid, L, R), _query(root * 2 + 2, mid + 1, r, L, R)); // 此处[mid+1, r]会出现 mid+1 > r 的情况，需要对于这种情况进行截止
}

int query(const int L, const int R) {
	return _query(0, 0, N-1, L, R);
}

/*
'功能：更新线段树中某个叶子节点的值
'root：当前线段树的根节点下标
'[L, R]: 当前节点所表示的区间
'index: 待更新节点在原始数组arr中的下标
'add_val: 更新的值（原来的值加上addVal）
*/
void _update_one(int root, int l, int r, const int index, const int val) {
	if (l == r && l == index) {
		seg_tree[root].val = val;
		return;
	}
	int mid = (l + r) / 2;
	if (index <= mid) {
		_update_one(root * 2 + 1, l, mid, index, val);
	} else {
		_update_one(root * 2 + 2, mid + 1, r, index, val);
	}
	seg_tree[root].val = min(seg_tree[root * 2 + 1].val, seg_tree[root * 2 + 2].val);
}

void update_one(const int index, const int val) {
	_update_one(0, 0, N - 1, index, val);
}

int main() {
	int Q;	//the amount of quest
	int command, first, second;	//the command of each quest
	cin >> N;
	for (int i = 0; i < N ; i++) {
		cin >> weight[i];
	}
	build(0, weight, 0, N-1);
	cin >> Q;
	for (int i = 0; i < Q ; i++) {
		cin >> command >> first >> second;
		if (command == 0) {
			cout << query(first - 1, second - 1) << endl;
		}
		else {
			update_one(first - 1, second);
		}
	}
	system("pause");
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define MAX_N 100005

using namespace std;

const int INFINITE = 2147483647;
int N;	//the amount of goods
int weight[MAX_N];	//the weight of each good
struct SegTreeNode {
	int val;
}seg_tree[4 * MAX_N];

inline int lson(int idx) { 
	return (idx << 1) | 1;
}

inline int rson(int idx) { 
	return (idx << 1) + 2; 
}

/*
��������������Сֵ
[L,R] Array������
*/
void build(int root, int* Array, int l, int r){	
	if (l == r) {	//�ݹ����
		seg_tree[root].val = Array[l];
		return;
	}
	int mid = (l + r) / 2;	//�������
	build(lson(root), Array, l, mid);
	build(rson(root), Array, mid + 1, r);
	seg_tree[root].val = min(seg_tree[root * 2 + 1].val, seg_tree[root * 2 + 2].val);
}

/*
'���ܣ��߶����������ѯ
'root����ǰ�߶����ĸ��ڵ��±�
'[L,R]: ��ǰ�ڵ�����ʾ������
'[x,y]: �˴β�ѯ������
*/
int _query(int root, int l, int r, const int L, const int R) {
	//��ѯ����͵�ǰ�ڵ�����û�н���
	if (r < L || R < l || l > r) {
		return INFINITE;
	}
	if (L <= l && r <= R && l <= r) {
		return seg_tree[root].val;
	}
	int mid = (l + r) / 2;
	if (R <= mid)
		return _query(lson(root), l, mid, L, R);
	if (L > mid)
		return _query(rson(root), mid + 1, r, L, R);
	return min(_query(lson(root), l, mid, L, R), _query(rson(root), mid + 1, r, L, R)); // �˴�[mid+1, r]����� mid+1 > r ���������Ҫ��������������н�ֹ
}

int query(const int L, const int R) {
	return _query(0, 0, N-1, L, R);
}

/*
'���ܣ������߶�����ĳ��Ҷ�ӽڵ��ֵ
'root����ǰ�߶����ĸ��ڵ��±�
'[L, R]: ��ǰ�ڵ�����ʾ������
'index: �����½ڵ���ԭʼ����arr�е��±�
'add_val: ���µ�ֵ��ԭ����ֵ����addVal��
*/
void _update_one(int root, int l, int r, const int index, const int val) {
	if (l == r) {
		seg_tree[root].val = val;
		return;
	}
	int mid = (l + r) / 2;
	if (index <= mid) {
		_update_one(lson(root), l, mid, index, val);
	} else {
		_update_one(rson(root), mid + 1, r, index, val);
	}
	seg_tree[root].val = min(seg_tree[lson(root)].val, seg_tree[rson(root)].val);
}

void update_one(const int index, const int val) {
	_update_one(0, 0, N - 1, index, val);
}

int main_error() {
	int Q;	//the amount of quest
	int command, first, second;	//the command of each quest
	scanf("%d", &N);
	for (int i = 0; i < N ; i++) {
		scanf("%d", weight + i);
	}
	build(0, weight, 0, N-1);
	scanf("%d", &Q);
	for (int i = 0; i < Q ; i++) {
		scanf("%d%d%d", &command, &first, &second);
		if (command == 0) {
			printf("%d\n", query(first - 1, second - 1));
		}
		else {
			update_one(first - 1, second);
		}
	}
	cout << flush;
	system("pause");
}
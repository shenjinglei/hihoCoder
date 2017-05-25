#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN = 1000000 + 10;

struct Node {
	int l, r;
	int w;
} tree[4 * MAXN];

/*
build
[l,r]
call: build(1, 1, n);
*/
void build(int node, int l, int r) {
	tree[node].l = l, tree[node].r = r;
	if (l == r) {
		scanf("%d", &tree[node].w);
		return;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	tree[node].w = min(tree[node * 2].w, tree[node * 2 + 1].w);
}

/*
update
[l,r]
call: update(1, x, v);
*/
void update(int node, int x, int k) {
	if (tree[node].l == x && x == tree[node].r) {	
		tree[node].w = k;
		return;
	}	
	
	if (tree[node].l == tree[node].r)
		return;
	int mid = (tree[node].l + tree[node].r) / 2;
	if (x <= mid)
		update(node * 2, x, k);
	else
		update(node * 2 + 1, x, k);
	tree[node].w = min(tree[node * 2].w, tree[node * 2 + 1].w);
}
int query(int node, int l, int r) {
	if (l <= tree[node].l && tree[node].r <= r) {
		return tree[node].w;
	}	

	int mid = (tree[node].l + tree[node].r) / 2;
	if (r <= mid)
		return query(node * 2, l, r);
	else if (mid < l)
		return query(node * 2 + 1, l, r);
	else
		return min(query(node * 2, l, mid), query(node * 2 + 1, mid + 1, r));
}
int main() {
	int n, q;
	int p, L, R, x, v;
	while (~scanf("%d", &n)) {
		build(1, 1, n);
		scanf("%d", &q);
		while (q--) {
			scanf("%d", &p);
			if (p == 0) {
				scanf("%d%d", &L, &R);
				printf("%d\n", query(1, L, R));
			}
			else {
				scanf("%d%d", &x, &v);
				update(1, x, v);
			}
		}
	}

	return 0;
}

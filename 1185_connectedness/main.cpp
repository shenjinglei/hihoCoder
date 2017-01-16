#include <iostream>
#define MAX_N 20000
#define MAX_M 100000
using namespace std;

//algorithm tarjan is
//input : 图 G = (V, E)
//output : 以所在的强连通分量划分的顶点集
/*
	index : = 0
	S : = empty    // 置栈为空
	for each v in V do
		if (v.index is undefined)
			strongconnect(v)
			end if
*/

//TODO: 未完成
void strongconnect(int v) {
	// 将未使用的最小index值作为结点v的index
	v.index : = index
	v.lowlink : = index
	index : = index + 1
	S.push(v)

	// 考虑v的后继结点
	for each (v, w) in E do
		if (w.index is undefined) then
			// 后继结点w未访问，递归调用
			strongconnect(w)
			v.lowlink : = min(v.lowlink, w.lowlink)
		else if (w is in S) then
			// w已在栈S中，亦即在当前强连通分量中
			v.lowlink : = min(v.lowlink, w.index)
			end if

			// 若v是根则出栈，并求得一个强连通分量
			if (v.lowlink = v.index) then
				start a new strongly connected component
				repeat
				w : = S.pop()
				add w to current strongly connected component
				until(w = v)
				output the current strongly connected component
				end if
				end function
}

int main() {
	int N, M;
	cin >> N >> M;
	int w[MAX_N];
	for (int i = 0; i < N ; i++) {
		cin >> w[i];
	}
	int path[MAX_M][2];
	for (int i = 0; i < M ; i++) {
		cin >> path[i][0] >> path[i][1];
	}

}


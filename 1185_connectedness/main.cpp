#include <iostream>
#define MAX_N 20000
#define MAX_M 100000
using namespace std;

//algorithm tarjan is
//input : ͼ G = (V, E)
//output : �����ڵ�ǿ��ͨ�������ֵĶ��㼯
/*
	index : = 0
	S : = empty    // ��ջΪ��
	for each v in V do
		if (v.index is undefined)
			strongconnect(v)
			end if
*/

//TODO: δ���
void strongconnect(int v) {
	// ��δʹ�õ���Сindexֵ��Ϊ���v��index
	v.index : = index
	v.lowlink : = index
	index : = index + 1
	S.push(v)

	// ����v�ĺ�̽��
	for each (v, w) in E do
		if (w.index is undefined) then
			// ��̽��wδ���ʣ��ݹ����
			strongconnect(w)
			v.lowlink : = min(v.lowlink, w.lowlink)
		else if (w is in S) then
			// w����ջS�У��༴�ڵ�ǰǿ��ͨ������
			v.lowlink : = min(v.lowlink, w.index)
			end if

			// ��v�Ǹ����ջ�������һ��ǿ��ͨ����
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


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int v;
	int next;
	Edge(int a = 0, int b = 0) : v(a), next(b) {}
};

int topology(const vector<vector<int>> &graph, vector<int> &virus, vector<int> &degree) {	//��������
	queue<int> q;
	for (int i = 1; i < degree.size() ; i++) {	//�����Ϊ0�Ľ�����
		if(degree[i] == 0){
			q.push(i);
		}
	}
	while (!q.empty()) {	//�Զ��зǿս���ѭ��
		int u = q.front();	//������
		q.pop();
		for (auto v : graph[u]) {	//�Ըýڵ��ÿ�����Ƚڵ����
			virus[v] += virus[u];
			virus[v] %= 142857;
			if (--degree[v] == 0) {	//�Ըó���ɾ��������ýڵ�û������������
				q.push(v);
			}
		}
	}
	return 0;
}

int main() {
	int n, m, k; //N���ڵ㣬M���ߣ�K����ʼ������
	cin >> n >> m >> k;
	vector<int> headers(n + 1);	//�Խڵ��ʾ
	vector<Edge> edges(m + 1);	//�Ա߱�ʾ
	
	vector<vector<int>> graph(n + 1);	//���ڽӱ��ʾ
	vector<int> virus(n + 1), degree(n + 1);

	for (int i = 1; i <= k ; i++) {
		int x;
		cin >> x;
		virus[x] = 1;
	}

	for (int i = 1; i < m+1 ; i++) {
		int u, v;
		cin >> u >> v;

		edges[i].v = v;
		edges[i].next = headers[u];
		headers[u] = i;
	}


	for (int i = 1; i <= n ; i++) {
		for (int j = headers[i]; j; j = edges[j].next) {
			graph[i].push_back(edges[j].v);
			degree[edges[j].v]++;
		}
	}
	topology(graph, virus, degree);

	int ans = 0;
	for (int i = 1; i <= n ; i++) {
		ans += virus[i];
		ans %= 142857;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}

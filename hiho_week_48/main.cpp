#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int v;
	int next;
	Edge(int a = 0, int b = 0) : v(a), next(b) {}
};

int topology(const vector<vector<int>> &graph, vector<int> &virus, vector<int> &degree) {	//拓扑排序
	queue<int> q;
	for (int i = 1; i < degree.size() ; i++) {	//将入度为0的进队列
		if(degree[i] == 0){
			q.push(i);
		}
	}
	while (!q.empty()) {	//以队列非空进行循环
		int u = q.front();	//出队列
		q.pop();
		for (auto v : graph[u]) {	//对该节点的每个出度节点操作
			virus[v] += virus[u];
			virus[v] %= 142857;
			if (--degree[v] == 0) {	//对该出度删除，如果该节点没有入度则进队列
				q.push(v);
			}
		}
	}
	return 0;
}

int main() {
	int n, m, k; //N个节点，M条边，K个起始病毒点
	cin >> n >> m >> k;
	vector<int> headers(n + 1);	//以节点表示
	vector<Edge> edges(m + 1);	//以边表示
	
	vector<vector<int>> graph(n + 1);	//以邻接表表示
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

#include <iostream>
#include <string>
#define MAX_N 100
#define MAX_M 100
using namespace std;

int N, M;
char field[MAX_N][MAX_M + 1];

/*
现在位置x,y
将现在位置重置后，深度搜索来重置整个水塘
*/
void dfs(int x, int y) {
	field[x][y] = '.';
	int m_x, m_y;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			m_x = x + i;
			m_y = y + j;
			if (0 <= m_x && m_x < N 
				&& 0 <= m_y && m_y < M
				&& field[m_x][m_y] == 'W') {
				dfs(m_x, m_y);
			}
		}
	}
}

/*
遍历field，每遇到一次W就用一次dfs清除该水塘
用了几次dfs，就表明有几个水塘
*/
int solve() {
	int ans = 0;
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < M; j++){
			if (field[i][j] == 'W') {
				ans++;
				dfs(i, j);
			}
		}
	}
	return ans;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N ; i++) {
		cin >> *(field + i);
	}
	cout << solve() << endl;
	system("pause");
}

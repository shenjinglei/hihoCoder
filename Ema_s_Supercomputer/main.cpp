#include <iostream>
#include <vector>
using namespace std;
typedef struct Pos {
	int x;	//row
	int y;	//col
	int r;	//radius
}Pos;
//2016.12.07 Ema's Supercomputer
bool is_valid(Pos p1, Pos p2) {	//返回两个十字是否相交
	int diff_x = p1.x - p2.x > 0 ? p1.x - p2.x : p2.x - p1.x;
	int diff_y = p1.y - p2.y > 0 ? p1.y - p2.y : p2.y - p1.y;
	if (diff_x == 0 && diff_y <= p1.r + p2.r) {		
		return false;
	}
	else if (diff_y == 0 && diff_x <= p1.r + p2.r) {		
		return false;
	}
	else if (diff_x <= p1.r && diff_y <= p2.r || diff_x <= p2.r && diff_y <= p1.r) {
		return false;
	}
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;
	char a[15][15];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	
	int cnt = 0, max = 0, tmp = 0;
	vector<Pos> ans;
	for (int i = 0; i < N; i++) {	//往ans中加入所有十字
		for (int j = 0; j < M; j++) {
			for (int k = 0; (i + k) < N && (j + k) < M && (i - k) >= 0 && (j - k) >= 0; k++) {
				if (a[i + k][j] == 'G' && a[i - k][j] == 'G' && a[i][j - k] == 'G' && a[i][j + k] == 'G'){
					ans.push_back(Pos{ i, j, k });
					continue;
				}
				break;
			}
		}
	}
	for (int i = 0; i < ans.size() - 1; i++) {	//两两计算乘积值,保留最大的结果
		for (int j = i+1; j < ans.size(); j++) {
			if (is_valid(ans[i],ans[j])) {
				tmp = (4 * ans[i].r + 1)*(4 * ans[j].r + 1);
				max = tmp > max ? tmp : max;
			}
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}

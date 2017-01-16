#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int main() {
	int N, M;//表示奖品的个数，以及小Ho手中的奖券数
	cin >> N >> M;
	int item[500][2];
	for (int i = 0; i < N ; i++) {
		cin >> item[i][0] >> item[i][1];
	}
	int best[MAX];
	for (int i = 0; i < MAX; i++) {
		best[i] = 0;
	}
	for (int i = 0; i < N ; i++) {
		for (int j = M; j >= item[i][0]; j--) {
			best[j] = max(best[j], best[j - item[i][0]] + item[i][1]);
		}
	}
	cout << best[M] << endl;
	system("pause");
	return 0;
}

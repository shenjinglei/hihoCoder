#include <iostream>
#define MAX 1000001
using namespace std;
int main() {
	int n;
	cin >> n;
	bool is_prime[MAX];
	memset(is_prime, true, sizeof(is_prime));
	int prime_list[1000];
	int prime_count = 0;
	for (int i = 2; i <= n ; i++) {
		if (is_prime[i]) {
			prime_count++;
			prime_list[prime_count] = i;
		}
		for (int j = 1; j <= prime_count ; j++) {
			if (i * prime_list[j] > n) {
				break;
			}
			is_prime[i * prime_list[j]] = false;
			if (i % prime_list[j] == 0) {
				break;
			}
		}
	}
	cout << prime_count << endl;
	for (int i = 0; i < prime_count ; i++) {
		cout << prime_list[i + 1] << " ";
	}
	system("pause");
}

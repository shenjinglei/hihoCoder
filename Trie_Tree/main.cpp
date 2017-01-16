#include <iostream>
using namespace std;
struct trie {
	trie *chi[26];
	int num;
	trie() {
		num = 0;
		for (int i = 0; i < 26; ++i) {
			chi[i] = NULL;
		}
	}
}*root;

void insert_trie(char *s) {
	trie *p = root;				//start from root
	p->num++;
	for (int i = 0; s[i]; i++) {
		int j = s[i] - 'a';
		if (p->chi[j] == NULL) {
			p->chi[j] = new trie;
		}
		p = p->chi[j];
		p->num++;
	}
}

int search_trie(char *s) {
	trie *p = root;	//start from root
	for (int i = 0; p && s[i]; i++) {
		int j = s[i] - 'a';
		p = p->chi[j];
	}
	if (!p) {
		return 0;
	}
	else {
		return p->num;
	}
}

int main() {
	char s[12];
	int n, m;
	cin >> n;
	root = new trie;
	while (n--) {
		cin >> s;
		insert_trie(s);
	}
	cin >> m;
	while (m--) {
		cin >> s;
		cout << search_trie(s) << endl;
	}
	system("pause");
	return 0;
}
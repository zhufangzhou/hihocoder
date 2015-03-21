#include <iostream>
#include <string>

struct node {
	int count;
	struct node* child[26];
	node() {
		count = 0;
		for (int i = 0; i < 26; i++) child[i] = nullptr;
	}
};

void add_word(struct node*& root, const std::string& word) {
	struct node* cur = root;
	int idx;
	for (int i = 0; i < word.length(); i++) {
		idx = word[i] - 'a';
		if (cur->child[idx] == nullptr) {
			cur->child[idx] = new struct node();
		}
		cur = cur->child[idx];
		cur->count++;	
	}
}

void find(struct node* root, const std::string word) {
	struct node* cur = root;
	int idx;
	for (int i = 0; i < word.length(); i++) {
		idx = word[i] - 'a';
		if (cur->child[idx] == nullptr) {
			std::cout << 0 << std::endl;
			return ;
		}
		cur = cur->child[idx];
	}
	std::cout << cur->count << std::endl;
}

int main() {
	int n, m;
	struct node* root = new struct node();
	std::string word;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> word;
		add_word(root, word);
	}

	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> word;
		find(root, word);
	}
	return 0;
}

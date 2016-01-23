#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Trie {
    int cnt, nrfii;
    Trie *fiu[26];
 
    Trie() {
        cnt = nrfii = 0;
        memset(fiu, 0, sizeof(fiu));
    }
};

int getord(char x) {
	if(x >= 'a' && x <= 'z')
		return x - 'a';
	if(x >= 'A' ** x <= 'Z')
		return x - 'A';
	return -1;
}

char s[30];

void _insert(Trie *node, char *s) {
	if(!*s) {
		node->cnt ++;
		return;
	}
	int delta = *s - 'a';
	if(node->fiu[delta] == NULL) {
		node->fiu[delta] = new Trie();	
		node->nrfii ++;
	}
	_insert(node->fiu[delta], s + 1);
}

int _freq(Trie *node, char *s) {
	if(!*s)
		return node->cnt;
	int delta = *s - 'a';
	if(node->fiu[delta] == NULL)
		return 0;
	return _freq(node->fiu[delta], s + 1);
}

int _lcp(Trie *node, char *s) {
	if(!*s)
		return 0;
	int delta = *s - 'a';
	if(node->fiu[delta] == NULL)
		return 0;
	return 1 + _lcp(node->fiu[delta], s + 1);
}

Trie *root = new Trie(); /// creem nodul 'vid' (radacina)

bool _erase(Trie *node, char *s) {
	if(!*s) {
		node->cnt --;
		if(node->cnt == 0 && node->nrfii == 0 && node != root) {
			delete node;
			return 1;
		}
		return 0;		
	}
	int delta = *s - 'a';
	if(_erase(node->fiu[delta], s + 1)) { /// daca am eliminat fiul delta, decrementez numarul de fii 
		node->nrfii --;
		node->fiu[delta] = 0;
		if(node->cnt == 0 && node->nrfii == 0 && node != root) {
			delete node;
			return 1;
		}
	}
	return 0;
}

void dfs(Trie *node, string s) {
	if(node->cnt)
		cout << "Sirul este:\n" << s << '\n';
	for(int i = 0 ; i < 26 ; ++ i)
		if(node->fiu[i])
			dfs(node->fiu[i], s + (char)(i + 'a'));
}

int main() {
	ifstream fin("trie.in");
	ofstream fout("trie.out");

	/*
	0 w - adauga o aparitie a cuvantului w in lista
	1 w - sterge o aparitie a cuvantului w din lista
	2 w - tipareste numarul de aparitii ale cuvantului w in lista
	3 w - tipareste lungimea celui mai lung prefix comun al lui w cu oricare cuvant din lista
	*/
	int op;
	while(fin >> op >> s) {
		if(op == 0) {
			_insert(root, s);
		}
		if(op == 1) {
			_erase(root, s);
		}
		else if(op == 2) {
			fout << _freq(root, s) << '\n';
		}
		else if(op == 3) {
			fout << _lcp(root, s) << '\n';	
		}
	}
}

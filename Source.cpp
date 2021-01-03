#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool s_contains(vector<int> s , int x) {
	bool contains = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == x) {
			contains = true;
		}
	}
	return contains;
}

void check_possibility(stack<int> a, vector<int> b, vector<int> s) {
	for (int i = 0; i < b.size(); i++) {
		if (s_contains(s, b[i]) ) {
			if (s[s.size()-1] != b[i]) {
				cout << "Impossible" << endl;
				return;
			}
			else {
				s.pop_back();
			}
		}
		else {
			s.push_back(a.top());
			a.pop();
			while (s[s.size()-1] != b[i]) {
				s.push_back(a.top());
				a.pop();
			}
			if (s_contains(s, b[i])) {
				if (s[s.size()-1]!= b[i]) {
					cout << "Impossible" << endl;
					return;
				}
				else {
					s.pop_back();
				}
			}
		}
	}
	cout << "Aye" << endl;
}

int main() {
	int T,n, m;
	stack<int> A;
	vector<int> S;
	vector<int> B;
	int element;
	cin >> T;
	for (int x = 0; x < T; x++) {
		B.clear();
		cin >> n;
		while (!A.empty()) {
			A.pop();
		}
		S.clear();
		for (int i = 0; i < n; i++) {
			cin >> element;
			A.push(element);
		}
		cin >> m;
		for (int p = 0; p < m; p++) {
			B.clear();
			S.clear();

			for (int i = 0; i < n; i++) {
				cin >> element;
				B.push_back(element);
			}
			check_possibility(A, B, S);
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_symbol(char c) {
	return !isdigit(c) && !isspace(c) && !isalpha(c) && c != '.';
}

bool has_adjacent_symbol(const vector<string>& schematic, size_t i, size_t j) {
	for(int di = -1; di <= 1; di++) {
		for(int dj = -1; dj <= 1; dj++) {
			if (di == 0 && dj == 0) continue;
			if (i + di < 0 || i + di >= schematic.size()) continue;
			if (j + dj < 0 || j + dj >= schematic[i].size()) continue;
			if (is_symbol(schematic[i + di][j + dj])) return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	vector<string> schematic;
	string line;
	while(getline(cin, line)) {
		schematic.push_back(line);
	}

	int ans = 0;
	for(size_t i = 0; i < schematic.size(); i++) {
		for(size_t j = 0; j < schematic[i].size(); j++) {
			if (isdigit(schematic[i][j])) {
				size_t n = 0;
				bool sum = false;
				while(isdigit(schematic[i][j])) {
					n = n * 10 + schematic[i][j] - '0';
					if (has_adjacent_symbol(schematic, i, j)) {
						sum = true;
					}
					j++;
				}
				if (sum) ans += n;
			}
		}
	}

	cout << ans << endl;

	return 0;
}

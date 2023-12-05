#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int gear_ratio(const vector<string>& schematic, const vector<vector<int>>& map, const vector<int>& numbers, size_t i, size_t j) {
	int ans = 1;
	set<int> added;
	for(int di = -1; di <= 1; di++) {
		for(int dj = -1; dj <= 1; dj++) {
			if (di == 0 && dj == 0) continue;
			if (i + di < 0 || i + di >= schematic.size()) continue;
			if (j + dj < 0 || j + dj >= schematic[i].size()) continue;
			if (map[i + di][j + dj] != -1) {
				auto [_, res] = added.insert(map[i + di][j + dj]);
				if (added.size() > 2) return 0;
				if (res) ans *= numbers[map[i + di][j + dj]];
			}
		}
	}
	return added.size() == 2 ? ans : 0;
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

	vector<vector<int>> map(schematic.size(), vector<int>(schematic[0].size(), -1));
	vector<int> numbers;

	for(size_t i = 0; i < schematic.size(); i++) {
		for(size_t j = 0; j < schematic[i].size(); j++) {
			if (isdigit(schematic[i][j])) {
				int n = 0;
				while(isdigit(schematic[i][j])) {
					n = n * 10 + schematic[i][j] - '0';
					map[i][j] = numbers.size();
					j++;
				}
				numbers.push_back(n);
			}
		}
	}

	int ans = 0;
	for(size_t i = 0; i < schematic.size(); i++) {
		for(size_t j = 0; j < schematic[i].size(); j++){
			if (schematic[i][j] == '*') {
				ans += gear_ratio(schematic, map, numbers, i, j);
			}
		}
	}

	cout << ans << endl;

	return 0;
}

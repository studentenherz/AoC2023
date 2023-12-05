#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
using lli = long long int;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	string line;
	getline(cin, line);

	vector<lli> seeds;
	istringstream iss(line.substr(line.find(":") + 1));
	lli seed;
	while(iss >> seed) {
		seeds.push_back(seed);
	}

	vector<map<lli, lli>> maps;

	getline(cin, line);
	while (getline(cin, line))
	{
		maps.push_back({{-1, 0}});
		while(getline(cin, line)) {
			if (line.empty()) break;
			istringstream iss(line);
			lli from, to, n;
			iss >> to >> from >> n;
			lli diff = to - from;
			auto it = maps.back().upper_bound(from + n);
			it--;
			lli prev_diff = it->second;
			it = maps.back().upper_bound(from);
			while(it != maps.back().end() && it->first < from + n) {
				prev_diff = it->second;
				it = maps.back().erase(it);
			}
			maps.back()[from] = diff;
			maps.back()[from + n] = prev_diff;
		}
	}

	lli ans = 1 << 30;

	for(lli seed: seeds) {
		for(auto& m: maps) {
			auto it = m.upper_bound(seed);
			it--;
			seed = seed + it->second;
		}
		ans = min(ans, seed);
	}

	cout << ans << endl;

	return 0;
}

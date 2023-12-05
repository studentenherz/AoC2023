#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	string line;
	int ans = 0;
	while(getline(cin, line)){
		size_t first = line.find(':'), second = line.find('|', first);
		istringstream iss1(line.substr(first+ 1, second - first - 1));
		istringstream iss2(line.substr(second + 1));
		set<int> s;
		for(int i; iss1 >> i;)
			s.insert(i);
		int n = 0;
		for(int i; iss2 >> i;)
			if(s.find(i) != s.end())
				n++;
		if (n > 0)
			n = 1 << (n - 1);
		ans += n;
	}

	cout << ans << endl;

	return 0;
}

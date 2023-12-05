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
	vector<int> v;

	auto add_cards = [&v](int f, int l = -1, int cant = 1){
		if (l == -1) l = f;
		if (l >= (int)v.size()) v.resize(l + 1, 0);
		for(int i = f; i <= l; i++)
			v[i] += cant;
	};

	int card = 1;
	while(getline(cin, line)){
		add_cards(card);
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
			add_cards(card + 1, card + n, v[card]);
		card++;
	}

	cout << reduce(v.begin(), v.end()) << endl;

	return 0;
}

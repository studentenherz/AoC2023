#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	auto is_digit = [](char c) {return isdigit(c);};

	int sum = 0;
	string s;
	while(cin >> s) {
		auto it1 = find_if(s.begin(), s.end(), is_digit);
		auto it2 = find_if(s.rbegin(), s.rend(), is_digit);
		assert(it1 != s.end());
		assert(it2 != s.rend());

		sum += 10 * (*it1 - '0') + (*it2 - '0');
	}

	cout << sum << endl;

	return 0;
}

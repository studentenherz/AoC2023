#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cassert>

using namespace std;

const string digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const string number[] = {"o1e", "t2o", "t3e", "f4r", "f5e", "s6x", "s7n", "e8t", "n9e"};

void map_first_digit(string& s) {
	for(size_t pos = 0; pos < s.size(); pos++) {
		for(int i = 0; i < 9; i++){
			if (s.find(digits[i], pos) == pos) {
				s.replace(pos, number[i].size(), number[i]);
				return;
			}
		}
	}
}

void map_last_digit(string& s) {
	for(int pos = s.size() - 1; pos >= 0; pos--) {
		for(int i = 0; i < 9; i++){
			if ((int)s.find(digits[i], pos) == pos) {
				s.replace(pos, number[i].size(), number[i]);
				return;
			}
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	auto is_digit = [](char c) {return isdigit(c);};

	int sum = 0;
	string s;
	while(cin >> s) {
		map_first_digit(s);
		map_last_digit(s);

		auto it1 = find_if(s.begin(), s.end(), is_digit);
		auto it2 = find_if(s.rbegin(), s.rend(), is_digit);
		assert(it1 != s.end());
		assert(it2 != s.rend());

		sum += 10 * (*it1 - '0') + (*it2 - '0');
	}

	cout << sum << endl;

	return 0;
}

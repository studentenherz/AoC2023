#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
using lli = long long int;

lli get_times(lli d, lli t) {
	double disc = sqrt(t * t - 4 * d);
	lli t1 = (double(t) - disc) / 2;
	t1 = max(t1, 0ll);
	lli t2 = (double(t) + disc) / 2;
	if (t2 * (t - t2) == d) t2--;
	return t2 - t1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	string line;
	getline(cin, line);
	string number = "";
	for(char c: line) {
		if (isdigit(c)) number += c;
	}
	lli time = stoll(number);

	getline(cin, line);
	number = "";
	for(char c: line) {
		if (isdigit(c)) number += c;
	}
	lli d = stoll(number);

	cout << get_times(d, time) << endl;

	return 0;
}

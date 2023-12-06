#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int get_times(int d, int t) {
	double disc = sqrt(t * t - 4 * d);
	int t1 = (double(t) - disc) / 2;
	t1 = max(t1, 0);
	int t2 = (double(t) + disc) / 2;
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
	istringstream iss(line.substr(line.find(":") + 1));
	vector<int> times;
	int time;
	while(iss >> time) {
		times.push_back(time);
	}

	getline(cin, line);
	istringstream iss2(line.substr(line.find(":") + 1));
	vector<int> ds;
	int d;
	while(iss2 >> d) {
		ds.push_back(d);
	}

	int ans = 1;
	for(int i = 0; i < (int)times.size(); i++){
		int t = get_times(ds[i], times[i]);
		cout << t << endl;
		ans *= t;
	}

	cout << ans << endl;

	return 0;
}

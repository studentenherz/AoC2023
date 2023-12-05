#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using lli = long long int;

lli power(string& s){
	s += ";";
	size_t pos = s.find(':');
	size_t next;

	lli r = 0, g = 0, b = 0, n;
	while((next = s.find(';', pos + 1)) != string::npos){
		istringstream iss(s.substr(pos + 1, next - pos - 1));

		while(iss >> n){
			string color;
			iss >> color;
			switch (color[0])
			{
			case 'r':
				r = max(r, n);
				break;
			case 'g':
				g = max(g, n);
				break;
			case 'b':
				b = max(b, n);
				break;
			default:
				throw "Invalid color";
				break;
			}
		}

		pos = next;
	}

	return r * g * b;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	string line;
	lli ans = 0;
	while(getline(cin, line)) {
		ans += power(line);
	}

	cout << ans << endl;

	return 0;
}

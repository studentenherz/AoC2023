#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool possible(string& s){
	s += ";";
	size_t pos = s.find(':');
	size_t next;

	while((next = s.find(';', pos + 1)) != string::npos){
		istringstream iss(s.substr(pos + 1, next - pos - 1));

		int r = 12, g = 13, b = 14, n;
		while(iss >> n){
			string color;
			iss >> color;
			switch (color[0])
			{
			case 'r':
				r -= n;
				break;
			case 'g':
				g -= n;
				break;
			case 'b':
				b -= n;
				break;
			default:
				throw "Invalid color";
				break;
			}
		}

		if (r < 0 || g < 0 || b < 0) return false;

		pos = next;
	}

	return true;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	string line;
	int game = 1, ans = 0;
	while(getline(cin, line)) {
		if (possible(line)) ans += game;
		game++;
	}

	cout << ans << endl;

	return 0;
}

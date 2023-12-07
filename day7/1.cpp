#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Hand{
	enum Kind {
		HighCard,
		OnePair,
		TwoPairs,
		ThreeOfAKind,
		FullHouse,
		FourOfAKind,
		FiveOfAKind,
	};

	string cards;
	string normalized_cards;
	int bid;
	Kind kind;

	Hand(const string& cards, int bid) : cards(cards), bid(bid) {
		kind = get_kind(cards);

		static const string labels = "23456789TJQKA";
		for(char c: cards){
			normalized_cards += labels.find(c);
		}
	}

	bool operator<(const Hand& other) const {
		if (this->kind == other.kind) return this->normalized_cards < other.normalized_cards;
		return this->kind < other.kind;
	}

private:
	Kind get_kind(const string& cards) {
		map<char, int> cnt;
		for (char c : cards) cnt[c]++;
		int max_cnt = 0;
		for (auto p : cnt) max_cnt = max(max_cnt, p.second);
		if (max_cnt == 5) return FiveOfAKind;
		if (max_cnt == 4) return FourOfAKind;
		if (max_cnt == 3) {
			if (cnt.size() == 2) return FullHouse;
			return ThreeOfAKind;
		}
		if (max_cnt == 2) {
			if (cnt.size() == 3) return TwoPairs;
			return OnePair;
		}
		return HighCard;
	}
};

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
	#endif

	string cards;
	int bid;

	vector<Hand> hands;
	while (cin >> cards >> bid) {
		hands.push_back(Hand(cards, bid));
	}

	sort(hands.begin(), hands.end());

	int ans = 0;
	for (int i = 0; i < (int)hands.size(); i++) {
		ans +=  hands[i].bid * (i + 1);
	}

	cout << ans << endl;

	return 0;
}

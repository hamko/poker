#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<long long> vll;
typedef pair<ll, ll> P;

string deal(map<int, string>& deck) {
    while (1) {
        int i = rand() % 53;
        if (deck.count(i)) {
            string tmp = deck[i];
            deck.erase(i);
            return tmp;
        }
    }
    return "";
}
void deal(map<int, string>& deck, vector<string>& hand) {
    hand.pb(deal(deck));
}

void disp(string memo, vector<string>& hand, vector<string>& table) {
    printf("\033[2J");
    cout << memo << endl;
    printf("Table\n");
    for (int i = 0; i < (int)table.size(); i++) {
        cout << table[i] << " ";
    }
    cout << endl;
    cout << endl;
    printf("Hand\n");
    for (int i = 0; i < (int)hand.size(); i++) {
        cout << hand[i] << " ";
    }
    cout << endl;
    string s;
    cin >> s;
}

void fill(map<int, string>& cards) {
    rep(i, 53) {
        string s;
        if (i < 13) {
            s += "H" + to_string(i+1);
        } else if (i < 26) {
            s += "S" + to_string(i+1-13);
        } else if (i < 39) {
            s += "C" + to_string(i+1-26);
        } else if (i < 52) {
            s += "D" + to_string(i+1-39);
        } else {
            s += "Joker";
        }
        cards[i] = s;
    }
}

int main(void)
{
    srand(time(NULL));
    while (1) {
        map<int, string> deck; fill(deck);
        vector<string> names = {"Moe-san", "Hamko"};
        int n = names.size();
        vector<vector<string>> hands(n);

        vector<string> table;
        vector<string> null;

        for (int i = 0; i < (int)hands.size(); i++) {
            deal(deck, hands[i]); deal(deck, hands[i]);
            disp("Turn: "+names[i], hands[i], table);
            hands[i].clear();
            disp("Turn: "+names[i], hands[i], table);
        }

        for (int mode = 0; mode <= 3; mode++) {
            if (mode == 0) {
            } else if (mode == 1) {
                deal(deck, table); deal(deck, table); deal(deck, table);
            } else if (mode == 2) {
                deal(deck, table);
            } else if (mode == 3) {
                deal(deck, table);
            } 
            disp("", null, table);
        }
        disp("", null, table);
    }
    return 0;
}

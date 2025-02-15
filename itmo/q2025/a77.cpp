#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Card {
  string color;
  string value;
};

struct Player {
  vector<Card> hand;
  bool active;
};

struct Game {
  vector<Player> players;
  Card topCard;
  int currentPlayer;
  int direction;
  int xCount;
  bool skipNext;
  bool isXChain;
  bool isAtChain;
};

bool isCardMatch(const Card &card1, const Card &card2) {
  return card1.color == card2.color || card1.value == card2.value ||
         card1.color == "black" || card2.color == "black";
}

bool isCardInHand(const Player &player, const Card &card) {
  for (const auto &c : player.hand) {
    if (c.color == card.color && c.value == card.value) {
      return true;
    }
  }
  return false;
}

void removeCardFromHand(Player &player, const Card &card) {
  auto it = find_if(player.hand.begin(), player.hand.end(), [&](const Card &c) {
    return c.color == card.color && c.value == card.value;
  });
  if (it != player.hand.end()) {
    player.hand.erase(it);
  }
}

void addCardToHand(Player &player, const Card &card) {
  player.hand.push_back(card);
}

void processMove(Game &game, const string &move, int turn, int &violationTurn,
                 int &violationPlayer, string &violationMsg) {
  if (violationTurn != -1)
    return;

  string action;
  int playerId;
  Card card;
  cin >> action;

  if (action == "->") {
    cin >> card.color >> card.value;
    string by;
    cin >> by >> playerId;

    if (!game.players[playerId - 1].active) {
      violationTurn = turn;
      violationPlayer = playerId;
      violationMsg = "other player's turn";
      return;
    }

    if (!isCardInHand(game.players[playerId - 1], card)) {
      violationTurn = turn;
      violationPlayer = playerId;
      violationMsg = "no such card";
      return;
    }

    if (!isCardMatch(card, game.topCard)) {
      violationTurn = turn;
      violationPlayer = playerId;
      violationMsg = "non-matching card";
      return;
    }

    removeCardFromHand(game.players[playerId - 1], card);
    game.topCard = card;

    if (card.value == "#") {
      game.skipNext = true;
    } else if (card.value == "X") {
      game.isXChain = true;
      game.xCount++;
    } else if (card.value == "@") {
      game.isAtChain = true;
      game.xCount++;
    }

    if (game.players[playerId - 1].hand.size() == 1) {
      string uno;
      cin >> uno;
      if (uno != "AND") {
        violationTurn = turn;
        violationPlayer = playerId;
        violationMsg = "failed 'Uno!'";
        return;
      }
    }

  } else if (action == "<<-") {
    int k;
    cin >> k;
    vector<Card> cards(k);
    for (int i = 0; i < k; ++i) {
      cin >> cards[i].color >> cards[i].value;
    }
    string by;
    cin >> by >> playerId;

    if (!game.players[playerId - 1].active) {
      violationTurn = turn;
      violationPlayer = playerId;
      violationMsg = "other player's turn";
      return;
    }

    if (game.isXChain || game.isAtChain) {
      int requiredCards = game.isXChain ? 2 * game.xCount : 4 * game.xCount;
      if (k != requiredCards) {
        violationTurn = turn;
        violationPlayer = playerId;
        violationMsg = "wrong move";
        return;
      }
    }

    for (const auto &c : cards) {
      addCardToHand(game.players[playerId - 1], c);
    }

    game.isXChain = false;
    game.isAtChain = false;
    game.xCount = 0;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, q;
    cin >> n >> a >> q;
    Card initialCard;
    cin >> initialCard.color >> initialCard.value;

    Game game;
    game.players.resize(n);
    for (int i = 0; i < n; ++i) {
      game.players[i].hand.resize(a);
      for (int j = 0; j < a; ++j) {
        cin >> game.players[i].hand[j].color >> game.players[i].hand[j].value;
      }
      game.players[i].active = true;
    }
    game.topCard = initialCard;
    game.currentPlayer = 1;
    game.direction = 1;
    game.xCount = 0;
    game.skipNext = false;
    game.isXChain = false;
    game.isAtChain = false;

    int violationTurn = -1;
    int violationPlayer = -1;
    string violationMsg;

    for (int turn = 1; turn <= q; ++turn) {
      string move;
      getline(cin, move);
      if (move.empty())
        continue;

      processMove(game, move, turn, violationTurn, violationPlayer,
                  violationMsg);

      if (violationTurn != -1) {
        break;
      }

      if (game.skipNext) {
        game.skipNext = false;
        game.currentPlayer = (game.currentPlayer + game.direction) % n;
        if (game.currentPlayer == 0)
          game.currentPlayer = n;
      }

      game.currentPlayer = (game.currentPlayer + game.direction) % n;
      if (game.currentPlayer == 0)
        game.currentPlayer = n;
    }

    if (violationTurn == -1) {
      cout << "no violations" << endl;
    } else {
      cout << violationMsg << " BY player " << violationPlayer << " ON turn "
           << violationTurn << endl;
    }
  }
  return 0;
}

#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main(int argc, char *argv[]){
  int seed = 0;
  if (argc > 1) seed = stoi(argv[1]);

  shared_ptr<Game> game = make_shared<Game>(seed);
  game->start();
}

//TODO
//1. get human and computer players to work properly on their own (2 hrs)
//2. create table class (1 hr)
//3. get the game logic going (finish end of saturday - at least rough outline)
//4. put it all together (sunday - all day)
//5. test test test (sunday - all day) - continue on monday



// string seed (argv[1]);
// unsigned s = static_cast<unsigned>(stoul(seed));
// Deck myDeck{s};
// myDeck.printDeck();
// cout << "shuffling" << endl;
// myDeck.shuffle();
// myDeck.printDeck();
// cout << "creating the table" << endl;
// Table table{};
// table.addCard(make_shared<Card>(2,3));
// table.printTable();
// cout <<"creating human Player" << endl;
//
// HumanPlayer human{};
// human.setHand(myDeck.getHand(0,12));
// cout << "score: " << human.getScore() << endl;
// human.updateScore(4);
// cout << "updated score: " << human.getScore() << endl;
// vector<shared_ptr<Card>> legalPlays = human.legalPlays(table);
// human.cardsToString(legalPlays);
// // //play 7C
// // string s1 = "7C";
// // if (s1.length() == 2){
// //   human.playCard(s1,legalPlays);
// // }else{
// //   cout << "error" <<endl;
// // }

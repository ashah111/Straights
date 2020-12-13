#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <sstream>
#include "game.h"

using namespace std;

Game::Game(unsigned seed): deck{Deck{seed}}, table{Table{}}, firstPlayer{0}, currentPlayer{0} {
  for (int i = 0 ; i < PLAYER_COUNT ; i++){
    cout << "Is Player" << i+1 << " a human (h) or a computer (c)?" << endl << ">";
    try{
        addPlayer();
    }catch (InvalidValueException &i) {
        cerr << "sampleTextUIStraights: GameLogic.cc:34: void GameLogic::enterPlayers(): Assertion `c == 'h' || c == 'c'' failed.";
        exit(0);
    }
  }
}

void Game::addPlayer(){
  if (players.size() >= PLAYER_COUNT) return;
  string type;

  while (getline(cin, type)){
    if (type == "h"){
      players.emplace_back(make_shared<HumanPlayer>());
      return;
    } else if (type == "c"){
      players.emplace_back(make_shared<ComputerPlayer>());
      return;
    } else if (type.find_first_not_of(' ') == std::string::npos){}
    else throw InvalidValueException();
  }
}

Game::~Game(){}

Deck Game::getDeck(){
    return deck;
}

Table Game::getTable(){
  return table;
}

void Game::getNextPlayer(){
  currentPlayer = (currentPlayer+1)%PLAYER_COUNT;
}

void Game::start(){
  while (!gameOver()){
    beginRound();
  }

  for (int i = 0 ; i < PLAYER_COUNT ; i++){
    cout << "Player" << (i+1) << "'s discards:";
    players[i]->cardsToString(players[i]->getDiscardPile());
    cout << "Player" << (i+1) << "'s score: " << players[i]->getScore() << " + " << players[i]->getScoreGained() << " = ";
    players[i]->updateScore(players[i]->getScoreGained());
    cout << players[i]->getScore() << endl;
  }
  printWinners();
}

void Game::beginRound(){
  deck.shuffle();
  table.clearTable();
  for ( int i=0 ; i<PLAYER_COUNT ; i++ ){
    players[i]->reset();
    if (players[i]->setHand(deck.getHand(i*13, i*13+12)) == 1){
      firstPlayer = i;
      currentPlayer = i;
    }
  }
  cout << "A new round begins. It's Player" << firstPlayer+1 << "'s turn to play" << endl;
  while (!roundOver()){
    takeTurn();
    getNextPlayer();
  }
}

void Game::takeTurn(){
  table.printTable();
  cout << "Your hand:";
  players[currentPlayer]->cardsToString(players[currentPlayer]->getHand());
  cout << "Legal plays:";
  vector<shared_ptr<Card>> legal = players[currentPlayer]->legalPlays(table);
  players[currentPlayer]->cardsToString(legal);

  if (players[currentPlayer]->playerType() == "computer"){
    if (legal.size() > 0){
        players[currentPlayer]->playCard("",legal);
    }
  }else{ //humanPlayer
    string s;
    cout << ">";
    while (std::getline(std::cin, s)) {
        istringstream iss{s};
        string cmd;
        iss >> cmd;

        if (cmd == "play"){
          cout << "cmd::play" << endl;
          iss >> cmd;
          try {
              players[currentPlayer]->playCard(cmd,legal);
              return;
          } catch (InvalidValueException &i) {
              cout << "This is not a legal play." << endl;
          }
        }else if (cmd == "discard"){
          cout << "cmd::discard" << endl;
          if (legal.size() > 0){
            cout << "You have a legal play. You may not discard" << endl;
          }else{
            iss >> cmd;
            try {
                players[currentPlayer]->discardCard(cmd);
                return;
            } catch (InvalidValueException &i) {
                cout << "This is not a legal play." << endl;
            }
          }
        }else if (cmd == "deck"){
          cout << "cmd::deck" << endl;
          deck.printDeck();
          cout << ">";
        }else if (cmd == "ragequit"){
          rageQuit(players[currentPlayer]);
          cout << "Player" << currentPlayer+1 << "ragequits. A computer will now take over" << endl;
        }else if (cmd == "quit"){
          exit(0);
        }else {
          cout << "Invalid command: '" << cmd << "'" << endl;
        }

    }
  }
}

void Game::rageQuit(shared_ptr<Player> player){
  auto found = find_if(players.begin(), players.end(), [&](shared_ptr<Player>& p){
    return (p == player);
  });

  if(found == players.end()) { return; }
  int idx = distance(players.begin(), found);

  //players.emplace_back(make_shared<ComputerPlayer>(player.get()));
  //players.erase(players.begin() + idx);
}

bool Game::roundOver(){
  int over = 0;
  for (int i = 0; i < PLAYER_COUNT ; i++){
    if (players[i]->getHand().size() == 0) over++;
  }
  if (over == PLAYER_COUNT) return true;
  return false;
}

bool Game::gameOver(){
  for (int i = 0; i < PLAYER_COUNT ; i++){
    if (players[i]->getScore() >= 80) return true;
  }
  return false;
}

void Game::printWinners(){
  vector<int> scores = {0,0,0,0};
  for (int i = 0; i < PLAYER_COUNT; i++){
    scores[i] = players[i]->getScore();
  }
  sort(scores.begin(),scores.end());
  int winningScore = scores[0];
  for (int i = 0; i < PLAYER_COUNT; i++){
    if (scores[i] == winningScore) cout << "Player" << i+1 << " wins!" << endl;
  }

}

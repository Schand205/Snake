#include "header.hpp"
#include <fstream>
#include <sstream>


void readHighscore(vector<Player> &highscores) {
	ifstream file("../highscore.txt");

	if(file.is_open()) {
		string line;
		while(getline(file, line)) {
			Player newPlayer;
			stringstream ss(line);
			ss >> newPlayer.name >> newPlayer.score;
			highscores.push_back(newPlayer);
		}
	}
	else	cout << "FYI: Noch keine Highscores vorhanden" << endl;
}

void addScore(vector<Player> &highscores, Player player) {

	if(highscores.empty()) {
		highscores.push_back(player);
		return;
	}

	size_t i = highscores.size()-1;
	
	//Index finden
	while(highscores[i].score < player.score) {
		if(i == 0) break;
		else i--;
	}
	//ersten 10 Plätze füllen
	if(highscores.size() < 10)	
		highscores.insert(highscores.begin() + i, player);
	//einfügen
	else if(i < 10) {
		highscores.insert(highscores.begin() + i, player);
		highscores.pop_back();
	}
}

void saveHighscore(vector<Player> &highscores) {
	ofstream file("../highscore.txt");

	if(file.is_open()) {
		for(auto player : highscores) {
			file << player.name << "\t" << player.score << endl;
		}
	}
	else	cerr << "Daten konnte nicht gesichert werden!" << endl;
}
	
void manageHighscore(Player newPlayer) {
	vector<Player> highscores;
	readHighscore(highscores);
	addScore(highscores, newPlayer);
	saveHighscore(highscores);
}

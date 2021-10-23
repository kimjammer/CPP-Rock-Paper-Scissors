#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum RPSNames {rock, paper, scissors};
string RPSString[] = {"rock", "paper", "scissors"};

int one_game(){
	cout << "Best out of 3:\n";

	int userWins = 0;
	int computerWins = 0;

	RPSNames userChoice;
	RPSNames compChoice;
	bool gameOver = false;

	while(!gameOver){
		while(true){
			cout << "Choose Rock, Paper, or Scissors:";

			string userInput;
			getline(cin,userInput);

			if(userInput == "Rock" || userInput == "rock"){
				userChoice = rock;
			}
			else if (userInput == "Paper" || userInput == "paper"){
				userChoice = paper;
			}
			else if (userInput == "Scissors" || userInput == "scissors"){
				userChoice = scissors;
			}else{
				cout << "That is unvalid!\n";
				continue;
			}

			compChoice = static_cast<RPSNames>(rand() % 3);

			cout << "The Computer chose " << RPSString[compChoice] << ". ";
			if (userChoice != compChoice){
				break;
			}else{
				cout << "Tie, go again!\n";
			}
		}

		if(userChoice > compChoice || (userChoice == rock && compChoice == scissors)){
			cout << "You Win!\n";
			userWins++;
		}
		else{
			cout << "You Loose!\n";
			computerWins++;
		}
		if(userWins >= 2 || computerWins >= 2){
			gameOver = true;
		}
	}

	if(userWins >= 2){
		return 0;
	}else if (computerWins >= 2){
		return 1;
	}

	//Some problem has occured if we hit this point.
	return 2;
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
  cout << "Welcome to Rock Paper Scissors\n";

	int userWins = 0;
	int computerWins = 0;
	bool stillPlaying = true;
	while(stillPlaying){
		int game_status = one_game();
		if(game_status == 0){
			userWins++;
		}else if (game_status == 1){
			computerWins++;
		}
		cout << "\n\nYou have won " << userWins << " times.\n";
		cout << "The computer has won " << computerWins << " times.\n";

		while(true){
			cout << "Play Again? (Y/N):";
			string userInput;
			getline(cin,userInput);
			if(userInput == "Y" || userInput == "y"){
				stillPlaying = true;
				break;
			}else if (userInput == "N" || userInput == "n"){
				stillPlaying = false;
				break;
			}
		}
	}

	cout << "Thank you for playing Rock Paper Scissors!\n";

	return 0;
}
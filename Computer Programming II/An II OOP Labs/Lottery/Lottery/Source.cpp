#include "Core.h"
#include "Lottery.h"

// Ask for users -> for every user init a vector of balls -> check for every user if he win 

int main() {

	srand(time(NULL) * rand()%3 + rand() % 20);

	//ifstream in("input.txt");

	//Get number of users
	int lotteryBallsSize = 49;
	int numberOfUsers;
	Ball ball;
	cout << "How many user you are : \n";
	cin >> numberOfUsers;

	//Init a vector jackpot for every user and for every vector there are 6 user own balls
	vector<vector<Ball>> jackpotz;

	//For every user get its own balls
	for (int i = 0; i < numberOfUsers; i++) {
		vector<Ball> balls;
		int input;
		for (int i = 0; i < 6; i++) {
			input = rand() % 49 + 1;
			ball.setBallValue(input);
			balls.push_back(ball);
		}
		jackpotz.push_back(balls);
	}

	cout << endl;

	// Show user balls;
	for (int i = 0; i < jackpotz.size(); i++) {
		cout << "User " << i + 1 << " balls are : ";
		for (int j = 0; j < jackpotz[i].size(); j++) {
			cout << jackpotz[i][j].getBallValue() << " ";
		}
		cout << endl;
	}

	//Initialize lottery balls.
	vector<Ball> lotteryBalls;
	lotteryBalls.resize(lotteryBallsSize);
	for (int i = 0; i < lotteryBallsSize; i++)
	{
		lotteryBalls[i].setBallValue(i + 1);
	}

	//Get random ball from lottery and put it into luckyBalls
	vector<Ball> luckyBalls;
	cout << "\n Lucky numbers are :";
	for (int i = 0; i < 6; i++)
	{
		int temp = rand() % lotteryBallsSize + 1;
		bool randomValueIsOk = true;
		for (int j = 0; j < luckyBalls.size(); j++) {
			if (temp == luckyBalls[j].getBallValue()) {
				randomValueIsOk = false;
				break;
			}
		}

		if (randomValueIsOk == false || i == 0) {
			ball.setBallValue(lotteryBalls[temp].getBallValue());
			luckyBalls.push_back(ball);
			swap(lotteryBalls[temp], lotteryBalls[lotteryBallsSize - 1]);
			lotteryBalls.pop_back();
			lotteryBallsSize--;
			lotteryBalls.resize(lotteryBallsSize);
		}
		else{
			i--;
		}
	}

	for (int k = 0; k < luckyBalls.size(); k++) {
		cout << luckyBalls[k].getBallValue() << " ";
	}

	cout << endl;

	//Check if someone win
	for (int i = 0; i < jackpotz.size(); i++) {
		for (int j = 0; j < jackpotz[i].size(); j++) {
			for (int k = 0; k < luckyBalls.size(); k++) {
				if (jackpotz[i][j].getBallValue() == luckyBalls[k].getBallValue()) {
					cout << "User " << i + 1 << " found : " << jackpotz[i][j].getBallValue() << "! \n";
				}
			}
		}
		cout << endl;
	}

	system("PAUSE");
}
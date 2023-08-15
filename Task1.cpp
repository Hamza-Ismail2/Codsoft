#include <iostream>
#include <ctime>
using namespace std;


int main() {
	
	srand(time(NULL)); // enabling the rand function to give different values
	
	int randnum = rand() % 500; // range of guess values from 0-500.
	int tries = 0; // counter check for amount of tries.
	int user = -1; // keeping value -1 so it doesnt accidentally matches the values of random number.
	
	cout << "The number to be guessed is in range 0 - 500" << endl;
	
	while (user != randnum) {
		
		cout << "Guess the random number: ";
		cin >> user;
		tries++;
		
		if(user > randnum && (user - randnum >= 250)) {
			cout << "Your guess is very high, please guess a lower value." << endl;
			continue;
		}
		if(randnum > user && (randnum - user >= 250)) {
			cout << "Your guess is very low, please guess a higher value." << endl;
			continue;
		}
		if(user > randnum && (user - randnum >= 50)) {
			cout << "Your are close, but high, please guess a lower value." << endl;
			continue;
		}
		if(randnum > user && (randnum - user >= 50)) {
			cout << "Your are close, but low, please guess a higher value." << endl;
			continue;
		}
		if(user > randnum && (user - randnum > 10)) {
			cout << "OOOOH, almost made it, a little high, please guess a lower value." << endl;
			continue;
		}
		if(randnum > user && (randnum - user > 10)) {
			cout << "OOOOH, almost made it, a little low, please guess a higher value." << endl;
			continue;
		}
		if(user > randnum && (user - randnum <= 10)) {
			cout << "You are within +- 10 of this value, please guess a lower value." << endl;
			continue;
		}
		if(randnum > user && (randnum - user <= 10)) {
			cout << "You are within +- 10 of this value, please guess a higher value." << endl;
			continue;
		}
		
		
	}
	cout << "\n\n\nHooorrayy, found the number yay <3" << endl;
	cout << "It took you " << tries << " amount of tries to find the random number " << randnum << "."; 
}
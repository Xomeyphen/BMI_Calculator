/*
Program name : N/A

Programmer : N/A

Date : 9 / 17 / 2023

Version : 1.5

Des: BMI calculator that is able to tell you (according to Adolphe Quetelet) if you are over, under or at a good weight to hight ratio.
- Has checks for invalid imputs as well as a loop for checking mutipule people 
- Universal for metric or imperal systems 
- Has checks to see if information might not be enterd corectly. 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double BMI = 0.0, Weight = 0.0, Height = 0.0;
	bool CoolLoop, IsMetric;
	char LoopDecider, MetricOrImperil;

	for (CoolLoop = true; CoolLoop;) {//loop, checks, & intro
		cout << "Will you be using the metric or imperial system today? \n(e.g. 'M' or 'I') \n-->"; cin >> MetricOrImperil;


		if (MetricOrImperil == 'M' || MetricOrImperil == 'm') { IsMetric = true; //Freedom units
			cout << "Welcome to my BMI calculator. \nPlease enter your weight in lbs, then height in inches seperated by a space.\n";
			cin >> Weight >> Height;
		}
		else if (MetricOrImperil == 'I' || MetricOrImperil == 'i') { IsMetric = false; //World units
			const double IMPERIAL_TO_METRIC_WEIGHT = 2.20462;
			const double IMPERIAL_TO_METRIC_HEIGHT = 0.393701;
			cout << "Welcome to my BMI calculator. \nPlease enter your weight in kg, then height in cm seperated by a space.\n";
			cin >> Weight >> Height;
			Height *= IMPERIAL_TO_METRIC_HEIGHT; Weight *= IMPERIAL_TO_METRIC_WEIGHT;
		}
		else {
			cout << "Please choose which system you want to use. "; 
			continue;
		}
		if (Height < 0 || Weight < 0) { //check for non postive numers
			cout << "Both Height and Weight need to be postive values";
			continue;
		}
		else { //caluclations and output
			BMI = (Weight * 703) / pow(Height, 2); 
			if (BMI < 18.5) { //bmi check 1
				cout << "Acording to 'Adolphe Quetelet' your BMI '" << BMI << "' is considered Underweight";
			}
			else if (BMI > 18.5 && BMI < 25) { //bmi check 2
				cout << "Acording to 'Adolphe Quetelet' your BMI '" << BMI << "' is considered Good";
			}
			else if (BMI > 25 && BMI < 200) { //bmi check 3
				cout << "Acording to 'Adolphe Quetelet' your BMI '" << BMI << "' is considered Overweight";
			}
			else { //probably wrong information enterd
				cout << "Please recheck your information entered, something went wrong. >_>\n";
				continue;
			}
		}
		cout << "\nWant to find another BMI? \n(e.g. y/n)\n-->"; cin >> LoopDecider; // loop check
		if (LoopDecider == 'Y' || LoopDecider == 'y') {
			CoolLoop = true;
			cout << "\nOkay! \n";
			continue;
		}
		else {
			CoolLoop = false;
			continue;
		}
	}
	return 0;
}
#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Questions {
public:
	static std::string GetQuestions() {
		int random = rand() % 10;
		switch (random) {
		case 1:
			question = "How many arms/tentacles/limbs does a squid have?";
			answer1 = "8";
			answer2 = "10";
			answer3 = "12";
			answer4 = "15";
			correctAnswer = 2;
			break;
		case 2:
			question = "In the song, Heartbreak Hotel is on which street?";
			answer1 = "Lonely Street";
			answer2 = "HeartBreak Street";
			answer3 = "Winslow Street";
			answer4 = "Weeping Street";
			correctAnswer = 1;
			break;
		case 3:
			question = "In which country did the Mau Mau uprising (1952-60) occur?";
			answer1 = "China";
			answer2 = "Mongolia";
			answer3 = "Ethiopia";
			answer4 = "Kenya";
			correctAnswer = 4;
		case 4:
			question = "What does a numismatist study or collect?";
			answer1 = "Numbers";
			answer2 = "Flowers";
			answer3 = "Coins";
			answer4 = "Dinosaurs";
			correctAnswer = 3;
			break;
		case 5:
			question = "Who captained Jules Verne's submarine Nautilus?";
			answer1 = "Captain Nemo";
			answer2 = "Captain Dory";
			answer3 = "Captain Randall";
			answer4 = "Captain Black";
			correctAnswer = 1;
			break;
		case 6:
			question = "In knitting, what is meant by the initials 'psso'?";
			answer1 = "Put String Stich Over";
			answer2 = "Pass Stich Stich Over";
			answer3 = "Pass Slipped Stich Over";
			answer4 = "Pass Stich Sew Over";
			correctAnswer = 3;
			break;
		case 7:
			question = "What is infant whale commonly called?";
			answer1 = "Doe";
			answer2 = "Soe";
			answer3 = "Baby";
			answer4 = "Calf";
			correctAnswer = 4;
			break;
		case 8:
			question = "How many gallons of beer are in a firkin?";
			answer1 = "9";
			answer2 = "10";
			answer3 = "11";
			answer4 = "12";
			correctAnswer = 1;
			break;
		case 9:
			question = "What is an otter's home called?";
			answer1 = "Hostel";
			answer2 = "Holt";
			answer3 = "Dinge";
			answer4 = "Cavst";
			correctAnswer = 2;
			break;
		case 10:
			question = " Which hills divide England from Scotland?";
			answer1 = "Cheviots";
			answer2 = "Horst";
			answer3 = "Marmost";
			answer4 = "Scottish Hills";
			correctAnswer = 1;
			break;
		default:
			break;
		}
		return question;
	}

	static std::string getAnswer1() {
		return answer1;
	}
	static std::string getAnswer2() {
		return answer2;
	}
	static std::string getAnswer3() {
		return answer3;
	}
	static std::string getAnswer4() {
		return answer4;
	}
	static int getCorrectAnswer() {
		return correctAnswer;
	}

private:
	static std::string question;
	static std::string answer1;
	static std::string answer2;
	static std::string answer3;
	static std::string answer4;
	static int correctAnswer;
};
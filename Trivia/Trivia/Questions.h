#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Questions {
public:
	std::string GetQuestions() {
		std::ifstream questions("Questions.txt");
		numLines = 0;
		std::string line;
		while (std::getline(questions, line)) {
			++numLines;
		}
		int questionNumber = rand() % numLines;
	}

private:
	int numLines;
};
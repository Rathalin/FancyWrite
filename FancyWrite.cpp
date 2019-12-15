#include "FancyWrite.h"
#include <vector>
#include <iostream>


FancyWrite::FancyWrite()
	: hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) }, originalConsoleForeground{ 15 }, CSBI{}
{
	SetConsoleScreenBufferSize(hConsole, COORD{ 100, 100 });
	// store current console color
	if (GetConsoleScreenBufferInfo(hConsole, &CSBI)) {
		originalConsoleForeground = CSBI.wAttributes;
	}
}

FancyWrite::~FancyWrite()
{
	// set console color to original
	SetConsoleTextAttribute(hConsole, originalConsoleForeground);
}

void FancyWrite::changeColor(FancyColor color)
{
	SetConsoleTextAttribute(hConsole, (int)color);
}

void FancyWrite::write(std::string text, FancyColor color)
{
	// store current console color
	WORD lastColor{ 15 };
	if (GetConsoleScreenBufferInfo(hConsole, &CSBI)) {
		lastColor = CSBI.wAttributes;
	}

	changeColor(color);
	std::cout << text << std::flush;

	// set color to last color
	SetConsoleTextAttribute(hConsole, lastColor);
}

void FancyWrite::writeRepeated(std::string text, unsigned int count, FancyColor color)
{
	// store current console color
	WORD lastColor{ 15 };
	if (GetConsoleScreenBufferInfo(hConsole, &CSBI)) {
		lastColor = CSBI.wAttributes;
	}

	changeColor(color);
	for (unsigned int i{ 0 }; i < count; i++) {
		std::cout << text << std::flush;
	}

	// set color to last color
	SetConsoleTextAttribute(hConsole, lastColor);
}

std::string FancyWrite::writeWrapped(std::string text, char borderChar, FancyColor colorText, FancyColor colorBorder)
{
	// store current console color
	WORD lastColor{ 15 };
	if (GetConsoleScreenBufferInfo(hConsole, &CSBI)) {
		lastColor = CSBI.wAttributes;
	}
	// split text into rows and remember the maximum letter count in a row
	std::vector<std::string> rows{};
	std::string row{};
	unsigned int maxRowLetters{ 0 };
	for (unsigned int iLetter{ 0 }; iLetter < text.length(); iLetter++) {
		if (text[iLetter] != '\n' && iLetter < text.length() - 1) {
			row += text[iLetter];
		}
		else {
			rows.push_back(row);
			if (maxRowLetters < row.length()) {
				maxRowLetters = row.length();
			}
			row = "";
		}
	}

	// wrap text
	std::string wrappedText{};
	changeColor(colorBorder);
	for (unsigned int iLetter{ 0 }; iLetter < maxRowLetters + 4; iLetter++) {
		std::cout << borderChar;
	}
	std::cout << "\n";
	for (unsigned int iRow{ 0 }; iRow < rows.size(); iRow++) {
		std::cout << borderChar;
		std::cout << " ";
		changeColor(colorText);
		for (unsigned int iLetter{ 0 }; iLetter < maxRowLetters; iLetter++) {
			if (iLetter < rows[iRow].length()) {
				std::cout << rows[iRow][iLetter];
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << " ";
		changeColor(colorBorder);
		std::cout << borderChar;
		std::cout << "\n";
	}
	for (unsigned int iLetter{ 0 }; iLetter < maxRowLetters + 4; iLetter++) {
		std::cout << borderChar;
	}
	// set color to last color
	SetConsoleTextAttribute(hConsole, lastColor);

	return wrappedText;
}

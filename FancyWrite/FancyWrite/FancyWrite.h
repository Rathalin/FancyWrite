#ifndef FANCYWRITE_H
#define FANCYWRITE_H

#include <string>
#include <Windows.h>
#include <vector>
#include <iostream>

namespace Fancy {

	enum class FancyColor {
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		CYAN = 3,
		RED = 4,
		VIOLET = 5,
		YELLOW = 6,
		LIGHTGRAY = 7,
		GRAY = 8,
		LIGHTBLUE = 9,
		LIGHTGREEN = 10,
		LIGHTCYAN = 11,
		LIGHTRED = 12,
		LIGHTVIOLET = 13,
		LIGHTYELLOW = 14,
		WHITE = 15
	};


	class FancyWrite
	{
	public:
		static void changeColor(FancyColor color)
		{
			initInstance();
			SetConsoleTextAttribute(FancyWrite::instance->hConsole, (int)color);
		}
		static void write(std::string text, FancyColor color)
		{
			initInstance();
			// store current console color
			WORD lastColor{ 15 };
			if (GetConsoleScreenBufferInfo(FancyWrite::instance->hConsole, &FancyWrite::instance->CSBI)) {
				lastColor = FancyWrite::instance->CSBI.wAttributes;
			}

			changeColor(color);
			std::cout << text << std::flush;

			// set color to last color
			SetConsoleTextAttribute(FancyWrite::instance->hConsole, lastColor);
		}
		static void writeRepeated(std::string text, unsigned int count, FancyColor color)
		{
			initInstance();
			// store current console color
			WORD lastColor{ 15 };
			if (GetConsoleScreenBufferInfo(FancyWrite::instance->hConsole, &FancyWrite::instance->CSBI)) {
				lastColor = FancyWrite::instance->CSBI.wAttributes;
			}

			changeColor(color);
			for (unsigned int i{ 0 }; i < count; i++) {
				std::cout << text << std::flush;
			}

			// set color to last color
			SetConsoleTextAttribute(FancyWrite::instance->hConsole, lastColor);
		}
		static void writeWrapped(std::string text, char borderChar, FancyColor colorText, FancyColor colorBorder)
		{
			initInstance();
			// store current console color
			WORD lastColor{ 15 };
			if (GetConsoleScreenBufferInfo(FancyWrite::instance->hConsole, &FancyWrite::instance->CSBI)) {
				lastColor = FancyWrite::instance->CSBI.wAttributes;
			}
			// split text into rows and remember the maximum letter count in a row
			std::vector<std::string> rows{};
			std::string row{};
			unsigned int maxRowLetters{ 0 };
			for (unsigned int iLetter{ 0 }; iLetter < text.length(); iLetter++) {
				// store row characters into row except EOL
				if (text[iLetter] != '\n') {
					row += text[iLetter];
				}
				// store complete row when EOL or end of string
				if (text[iLetter] == '\n' || iLetter == text.length() - 1) {
					rows.push_back(row);
					if (maxRowLetters < row.length()) {
						maxRowLetters = row.length();
					}
					row = "";
				}
			}

			// wrap text
			changeColor(colorBorder);
			for (unsigned int iLetter{ 0 }; iLetter < maxRowLetters + 4; iLetter++) {
				std::cout << borderChar << std::flush;
			}
			std::cout << "\n" << std::flush;
			for (unsigned int iRow{ 0 }; iRow < rows.size(); iRow++) {
				std::cout << borderChar << std::flush;
				std::cout << " " << std::flush;
				changeColor(colorText);
				for (unsigned int iLetter{ 0 }; iLetter < maxRowLetters; iLetter++) {
					if (iLetter < rows[iRow].length()) {
						std::cout << rows[iRow][iLetter] << std::flush;
					}
					else {
						std::cout << " " << std::flush;
					}
				}
				std::cout << " " << std::flush;
				changeColor(colorBorder);
				std::cout << borderChar << std::flush;
				std::cout << "\n" << std::flush;
			}
			for (unsigned int iLetter{ 0 }; iLetter < maxRowLetters + 4; iLetter++) {
				std::cout << borderChar << std::flush;
			}
			// set color to last color
			SetConsoleTextAttribute(FancyWrite::instance->hConsole, lastColor);
		}
	private:
		FancyWrite()
			: hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) }, originalConsoleForeground{ 15 }, CSBI{}
		{
			SetConsoleScreenBufferSize(hConsole, COORD{ 200, 200 });
			// store current console color
			if (GetConsoleScreenBufferInfo(hConsole, &CSBI)) {
				originalConsoleForeground = CSBI.wAttributes;
			}
			FancyWrite::instance = this;
		}
		~FancyWrite()
		{
			// set console color to original
			SetConsoleTextAttribute(hConsole, originalConsoleForeground);
		}
		static FancyWrite* instance;
		static void initInstance()
		{
			if (!FancyWrite::instance) {
				FancyWrite::instance = new FancyWrite();
			}
		}
		HANDLE hConsole;
		WORD originalConsoleForeground;
		CONSOLE_SCREEN_BUFFER_INFO CSBI;
	};

	FancyWrite* FancyWrite::instance{ nullptr };
}

#endif
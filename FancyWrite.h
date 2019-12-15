#pragma once
#include <string>
#include <Windows.h>
#include "FancyColor.h"

class FancyWrite
{
public:
	FancyWrite();
	~FancyWrite();
	void changeColor(FancyColor color);
	void write(std::string text, FancyColor color);
	void writeRepeated(std::string text, unsigned int count, FancyColor color = FancyColor::WHITE);
	std::string writeWrapped(std::string text, char borderChar = (char)219, FancyColor colorText = FancyColor::WHITE, FancyColor colorBorder = FancyColor::WHITE);
private:
	HANDLE hConsole;
	WORD originalConsoleForeground;
	CONSOLE_SCREEN_BUFFER_INFO CSBI;
};
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <array>

class File
{
private:
	std::fstream file;
	int width;
	int height;
	int maxValue;
	std::string map;

public:
	File(std::string filename, std::ios::openmode mode);
	File(const File& f);
	~File();
	void ReadFile();
	void ExtractInteger(std::string str);
	int GetWidth();
	int GetHeight();
	int GetMaxValue();
	std::string GetMap();
};


#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "File.h"

class MapCreator
{
	int mapWidth;
	int mapHeight;
	int mapMaxValue;
	int occupiedThreshold;
	int freeThreshold;
	std::vector<std::string> map;
public:
	MapCreator(File _file) :
		mapWidth(_file.GetWidth()),
		mapHeight(_file.GetHeight()),
		mapMaxValue(_file.GetMaxValue())
	{
		occupiedThreshold = mapMaxValue * 0.04;
		freeThreshold = mapMaxValue - mapMaxValue * 0.04;
	};
	void CreateMap(std::string mapInLine);
	std::vector<std::string> ConvertMap();
	void PrintMap();
};

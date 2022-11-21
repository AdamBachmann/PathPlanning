#include "MapCreator.h"

void MapCreator::CreateMap(std::string mapInLine)
{
	std::string row;

	for (int i = 0; i < mapHeight; i++)
	{
		std::copy_n(mapInLine.begin() + i * mapWidth, mapWidth, std::back_inserter(row));

		map.push_back(row);
		row.clear();
	}
}

std::vector<std::string> MapCreator::ConvertMap()
{
	std::vector<std::string> convertedMap;
	std::string row;
	int threshold = this->freeThreshold;

	row.resize(mapWidth + 2);
	std::fill_n(row.begin(), mapWidth + 2, '#');
	convertedMap.push_back(row);
	row.clear();

	for (auto it : map)
	{
		row = "#";

		for (auto sign : it)
		{
			if (static_cast<unsigned char>(sign) >= freeThreshold)
				row.push_back('.');
			else
				row.push_back('#');
		}

		row.push_back('#');
		convertedMap.push_back(row);
		row.clear();
	}

	row.resize(mapWidth + 2);
	std::fill_n(row.begin(), mapWidth + 2, '#');
	convertedMap.push_back(row);
	row.clear();

	return convertedMap;
}

void MapCreator::PrintMap()
{
	for (auto it : map)
		std::cout << it << std::endl;
}
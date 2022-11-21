#include "File.h"

File::File(std::string filename, std::ios::openmode mode) : width(0), height(0), maxValue(0)
{
	file.open(filename, mode);
}

File::File(const File& f)
{
	width = f.width;
	height = f.height;
	maxValue = f.maxValue;
	map = f.map;
}

File::~File()
{
	file.close();
}

void File::ReadFile()
{
	std::string line;
	std::stringstream ss;
	int lineCounter = 0;
	while (getline(file, line))
	{
		if (lineCounter % 5 == 0)
		{
			if (line != "P2" && line != "P5")
			{
				std::cout << "Wrong file" << std::endl;
				break;
			}
		}
		else if (lineCounter % 5 == 1)
		{
			//comment
		}
		else if (lineCounter % 5 == 2)
		{
			ExtractInteger(line);
		}
		else if (lineCounter % 5 == 3)
		{
			std::stringstream(line) >> maxValue;
		}
		else if (lineCounter % 5 == 4)
		{
			map = line;
		}

		lineCounter++;
	}
}

void File::ExtractInteger(std::string str)
{
	std::stringstream ss;
	ss << str;
	std::string temp;
	int counter = 0;

	while (!ss.eof())
	{
		ss >> temp;
		if (counter == 0)
			std::stringstream(temp) >> width;
		else
			std::stringstream(temp) >> height;

		counter++;
	}
}

int File::GetWidth()
{
	return width;
}

int File::GetHeight()
{
	return height;
}

int File::GetMaxValue()
{
	return maxValue;
}

std::string File::GetMap()
{
	return map;
}
#include <iostream>
#include "MapCreator.h"
#include "MapSolver.h"

using namespace std;

int main()
{
	File F("map_2.pgm", ios::in);
	F.ReadFile();

	MapCreator MC(F);
	MC.CreateMap(F.GetMap());

	vector<string> myMap;
	myMap = MC.ConvertMap();

	std::pair<int, int> myStart(2, 2);
	std::pair<int, int> myFinish(1, 8);

	MapSolver MS(myStart, myFinish);
	MS.PutStartAndFinish(myMap);

	MS.SolveMap(myMap);
	MS.WritePath(myMap);

	for (auto it : myMap)
		cout << it << endl;

	return 0;
}
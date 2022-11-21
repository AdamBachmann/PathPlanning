#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <deque>

class MapSolver
{
	std::pair<int, int> start;
	std::pair<int, int> finish;
	std::deque<std::pair<int, int>> q;
public:
	MapSolver() : start(-1, -1), finish(-1, -1) {};
	MapSolver(std::pair<int, int> _start, std::pair<int, int> _finish) : start(_start), finish(_finish) {};
	void PutStartAndFinish(std::vector<std::string> &_map);
	void SolveMap(std::vector<std::string>& _map);
	void WritePath(std::vector<std::string>& _map);
};


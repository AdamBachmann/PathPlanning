#include "MapSolver.h"

void MapSolver::PutStartAndFinish(std::vector<std::string> &_map)
{
	if (start.first == -1 || start.second == -1 || finish.first == -1 || finish.second == -1)
		std::cout << "Wrong start or finish parameters" << std::endl;
	else
	{
		_map[start.first][start.second] = 'S';
	}
}

void MapSolver::SolveMap(std::vector<std::string>& _map)
{
    std::pair<int, int> position;
    q.push_back(start);

    while (!q.empty())
    {
        position = q.front();
        q.pop_front();

        if (position == finish) break;

        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if ((i != j) && (!i || !j))
                {
                    if (_map[position.first + i][position.second + j] == '.')
                    {
                        if (i == -1) _map[position.first + i][position.second + j] = 'd';
                        else if (i == 1) _map[position.first + i][position.second + j] = 'g';
                        else if (j == -1) _map[position.first + i][position.second + j] = 'p';
                        else               _map[position.first + i][position.second + j] = 'l';

                        std::pair<int, int> newPosition((position.first + i), (position.second + j));
                        q.push_back(newPosition);
                    }
                }
    }
}

void MapSolver::WritePath(std::vector<std::string>& _map)
{
    if (_map[finish.first][finish.second] != '.')
    {
        int i = finish.first; 
        int j = finish.second;

        while ((i != start.first) || (j != start.second))
        {
            char c = _map[i][j];
            _map[i][j] = '+';
            switch (c)
            {
            case 'd': i++; break;
            case 'g': i--; break;
            case 'p': j++; break;
            case 'l': j--; break;
            }
        }
    }

    _map[finish.first][finish.second] = 'W';

    for (int i = 0; i < _map.size(); i++)
    {
        for (int j = 0; j < (int)_map[i].length(); j++)
            switch (_map[i][j])
            {
            case 'g':
            case 'd':
            case 'p':
            case 'l': 
            case '.': _map[i][j] = ' ';
            }
    }
}
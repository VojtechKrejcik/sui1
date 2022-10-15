#include "search-strategies.h"
#include <unordered_set>
#include <queue>
#include <string>
#include <iostream> 
#include <sstream>  
#include <tuple>
#include <memory>


std::string state_to_string(std::shared_ptr<SearchState> state)
{
	std::stringstream buffer;
	buffer << *state;
	return buffer.str();
}

std::vector<SearchAction> BreadthFirstSearch::solve(const SearchState &init_state) {

	std::queue<std::shared_ptr<SearchState>> open;
	std::unordered_set<std::string> closed;
	std::map<std::shared_ptr<SearchState>,std::tuple<std::shared_ptr<SearchState>,SearchAction>> backtrackmap;
	std::shared_ptr<SearchState> working_state = std::make_shared<SearchState>(init_state);
	open.push(working_state);
	backtrackmap.insert({working_state,{working_state,working_state->actions().front()}});

	while (!open.empty())
	{
		std::shared_ptr<SearchState> cur_state = open.front();

		open.pop();
		if (cur_state->isFinal())
		{	
			std::vector<SearchAction> solution = {};
			std::shared_ptr<SearchState> child_state = cur_state;
			std::shared_ptr<SearchState> parent_state = std::get<0>(backtrackmap.at(cur_state));

			while (child_state != parent_state)
			{
				solution.insert(solution.begin(),std::get<1>(backtrackmap.at(child_state)));
				child_state = parent_state;
				parent_state = std::get<0>(backtrackmap.at(child_state));
			}
			return solution;
		}

		if(closed.find(state_to_string(cur_state)) != closed.end())
			continue;

		auto actions = cur_state->actions();

		if (actions.size() == 0)
			continue;
		
		for (long unsigned int i=0; i < actions.size();i++)
		{
			std::shared_ptr<SearchState> new_state = std::make_shared<SearchState>(actions[i].execute(*cur_state));
			open.push(new_state);
			backtrackmap.insert({new_state,{cur_state,actions[i]}});
		}
		
		closed.insert(state_to_string(cur_state));
	}
	return {};
}


std::vector<SearchAction> DepthFirstSearch::solve(const SearchState &init_state) {

	std::vector<SearchAction> open;
	std::vector<SearchAction> closed;
	SearchState working_state(init_state);

	return {};
}

double StudentHeuristic::distanceLowerBound(const GameState &state) const {
    return 0;
}

std::vector<SearchAction> AStarSearch::solve(const SearchState &init_state) {
	return {};
}

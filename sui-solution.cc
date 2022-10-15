#include "search-strategies.h"
#include <unordered_set>
#include <queue>
#include <string>
#include <iostream> 
#include <sstream>  
#include <tuple>



std::string state_to_string(SearchState state)
{
	std::stringstream buffer;
	buffer << state;
	return buffer.str();
}

std::vector<SearchAction> BreadthFirstSearch::solve(const SearchState &init_state) {

	std::queue<SearchState> open;
	std::unordered_set<std::string> closed;
	SearchState working_state(init_state);
	std::map<SearchState,std::tuple<SearchState,SearchAction>> backtrackmap;

	open.push(working_state);

	backtrackmap.insert({working_state,{working_state,working_state.actions().front()}});


	while (!open.empty())
	{
		// Expand node
		SearchState cur_state = open.front();

		open.pop();

		if (cur_state.isFinal())
		{	
			std::vector<SearchAction> solution;
			SearchState* child_state = &cur_state;
			SearchState* parent_state = &std::get<0>(backtrackmap.at(cur_state));
			while (state_to_string(*child_state) != state_to_string(*parent_state))
			{
				solution.insert(solution.begin(),std::get<1>(backtrackmap.at(*child_state)));
				std::cout<<"Akce přidána: " << std::get<1>(backtrackmap.at(*child_state)) << std::endl;
				child_state = parent_state;
				std::cout<<*child_state<<std::endl;
				parent_state = &std::get<0>(backtrackmap.at(*child_state));
			}
			std::cout<<"Solution ################################################################\n";
			return solution;
		}

		if(closed.find(state_to_string(cur_state)) != closed.end())
		{
			continue;
		}

		auto actions = cur_state.actions();

		if (actions.size() == 0)
		{
			// dead end
			continue;
		}

		
		for (int i=0; i < actions.size();i++)
		{
			//Add new states to open
			open.push(actions[i].execute(cur_state));
			//Add new states to map
			backtrackmap.insert({actions[i].execute(cur_state),{cur_state,actions[i]}});
		}
		
		//Close state and remove it from queue
		//std::cout<<cur_state;
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

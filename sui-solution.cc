#include "search-strategies.h"


std::vector<SearchAction> BreadthFirstSearch::solve(const SearchState &init_state) {

	std::vector<SearchState> open;
	std::vector<SearchState> closed;  //TODO: Replace with set
	SearchState working_state(init_state);
	std::map<SearchState,std::tuple<SearchState,SearchAction>> backtrackmap;

	open.push_back(working_state);

	backtrackmap.insert({working_state,{working_state,working_state.actions().front()}});


	while (!open.empty())
	{
		// Expand node
		SearchState cur_state = open.front();

		if (cur_state.isFinal())
		{
			//TODO: Do the thing
		}

		auto actions = cur_state.actions();

		if (actions.size() == 0)
		{
			// dead end
			break;
		}

		
		for (int i=0; i < actions.size();i++)
		{
			//Add new states to open
			open.push_back(actions[i].execute(cur_state));
			//Add new states to map
			backtrackmap.insert({actions[i].execute(cur_state),{cur_state,actions[i]}});
		}
		
		//Close state and remove it from queue
		closed.push_back(cur_state);
		open.erase(open.begin());

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

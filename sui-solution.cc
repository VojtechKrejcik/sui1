#include "search-strategies.h"
#include <unordered_set>
#include <queue>
#include <string>
#include <iostream> 
#include <sstream>  
#include <tuple>
#include <memory>
#include <stack>

std::string str(std::shared_ptr<SearchState> state)
{
	std::stringstream buffer;
	buffer << *state << std::endl;
	return buffer.str();
}

std::vector<SearchAction> BreadthFirstSearch::solve(const SearchState &init_state) {

	typedef std::shared_ptr<SearchState> state_ptr;
	std::hash<std::string> hash_string;
	std::queue<state_ptr> open;
	std::unordered_set<int> closed;
	std::map<int,std::tuple<int,SearchAction>> backtrackmap;
	state_ptr working_state = std::make_shared<SearchState>(init_state);
	open.push(working_state);

	backtrackmap.insert({hash_string(str(working_state)),{hash_string(str(working_state)),working_state->actions().front()}});

	
	 

	while (!open.empty())
	{
		state_ptr cur_state = open.front();
		int cur_state_hash = hash_string(str(cur_state));
		open.pop();
		if (cur_state->isFinal())
		{	
			std::vector<SearchAction> solution = {};
			int child_state = cur_state_hash;
			int parent_state = std::get<0>(backtrackmap.at(cur_state_hash));

			while (child_state != parent_state)
			{
				solution.insert(solution.begin(),std::get<1>(backtrackmap.at(child_state)));
				child_state = parent_state;
				parent_state = std::get<0>(backtrackmap.at(child_state));
			}
			return solution;
		}

		if(closed.count(cur_state_hash) >= 1)
		{
			continue;
		}
		auto actions = cur_state->actions();

		if (actions.size() == 0)
			continue;
		
		for (long unsigned int i=0; i < actions.size();i++)
		{
			state_ptr new_state = std::make_shared<SearchState>(actions[i].execute(*cur_state));
			open.push(new_state);
			backtrackmap.insert({hash_string(str(new_state)),{cur_state_hash,actions[i]}});
		}
		
		closed.insert(cur_state_hash);
	}
	return {};
}


std::vector<SearchAction> DepthFirstSearch::solve(const SearchState &init_state) {

	typedef std::shared_ptr<SearchState> state_ptr;
	std::hash<std::string> hash_string;
	std::stack<state_ptr> open;
	std::stack<int> depth;
	std::unordered_set<int> closed;
	std::map<int,std::tuple<int,SearchAction>> backtrackmap;
	state_ptr working_state = std::make_shared<SearchState>(init_state);

	open.push(working_state);
	backtrackmap.insert({hash_string(str(working_state)),{hash_string(str(working_state)),working_state->actions().front()}});
	depth.push(1); // Na úrovni 0 budiž jeden element a tím jest root. - Holy Bible of DFS chapter 0 verse 1

	while (!open.empty())
	{
		state_ptr cur_state = open.top();
		int cur_state_hash = hash_string(str(cur_state));
		open.pop();

		
		if (cur_state->isFinal())
		{	
			std::vector<SearchAction> solution = {};
			int child_state = cur_state_hash;
			int parent_state = std::get<0>(backtrackmap.at(cur_state_hash));

			while (child_state != parent_state)
			{
				solution.insert(solution.begin(),std::get<1>(backtrackmap.at(child_state)));
				child_state = parent_state;
				parent_state = std::get<0>(backtrackmap.at(child_state));
			}
			return solution;
		}

		depth.top()--;
		if(closed.count(cur_state_hash) >= 1)
		{
			if (depth.top() <= 0 ) // nemám sousedy -> jdu o úroveň výš
			{
				depth.pop();
			}
			continue;
		}	
		//Expanduji uzel
		auto actions = cur_state->actions();
		closed.insert(cur_state_hash);
		

		if ((depth.size() >= this->depth_limit_) || (actions.size() == 0)) // Dosáhl jsem hloubkového limitu nebo nemám kam
		{
			if (depth.top() <= 0 ) // nemám sousedy -> jdu o úroveň výš
			{
				depth.pop();
			}
			continue;
		}
		else // Expanduji do hloubky
		{
			depth.push(actions.size());
			for (long unsigned int i=0; i < actions.size();i++)
			{
				state_ptr new_state = std::make_shared<SearchState>(actions[i].execute(*cur_state));
				open.push(new_state);
				backtrackmap.insert({hash_string(str(new_state)),{cur_state_hash,actions[i]}});
			}
		}
		
	}
	return {};
}

double StudentHeuristic::distanceLowerBound(const GameState &state) const {
    return 0;
}

std::vector<SearchAction> AStarSearch::solve(const SearchState &init_state) {
	return {};
}

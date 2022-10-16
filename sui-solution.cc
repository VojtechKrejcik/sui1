#include "search-strategies.h"
#include <unordered_set>
#include <queue>
#include <string>
#include <iostream> 
#include <sstream>  
#include <tuple>
#include <memory>
#include <stack>
#include "memusage.h"
#include "card.h"



typedef std::shared_ptr<SearchState> state_ptr;

std::string str(std::shared_ptr<SearchState> state)
{
	std::stringstream buffer;
	buffer << *state << std::endl;
	return buffer.str();
}

class AState
{
	public:
		state_ptr state;
		double heuristic_value;

		AState(state_ptr state,double heuristic_value)
			: state(state), heuristic_value(heuristic_value)
		{		
		}

		std::string to_string()
		{
			return str(state);
		}

		size_t hash()
		{
			std::hash<std::string> hash_string;
			return hash_string(this->to_string());
		}
};

std::ostream& operator<< (std::ostream& os, AState& s)
{
		os << "State: " << *s.state<<std::endl<<"Heuristic value: " << s.heuristic_value<<std::endl;
		return os;
}
std::ostream& operator<< (std::ostream& os,const AState s)
{
		os << "State: " << *s.state<<std::endl<<"Heuristic value: " << s.heuristic_value<<std::endl;
		return os;
}
bool operator<(const AState &s1, const AState &s2)
{
		return s1.heuristic_value < s2.heuristic_value;
}
bool operator>(const AState &s1, const AState &s2)
{
		return s1.heuristic_value > s2.heuristic_value;
}
bool operator==(const AState &s1, const AState &s2)
{
		return s1.heuristic_value == s2.heuristic_value;
}
bool operator!=(const AState &s1, const AState &s2)
{
		return s1.heuristic_value != s2.heuristic_value;
}

std::vector<SearchAction> BreadthFirstSearch::solve(const SearchState &init_state) {

	std::hash<std::string> hash_string;
	std::queue<state_ptr> open;
	std::unordered_set<size_t> closed;
	std::unordered_set<size_t> h_open;
	std::map<size_t,std::tuple<size_t,SearchAction>> backtrackmap;
	state_ptr working_state = std::make_shared<SearchState>(init_state);
	open.push(working_state);

	backtrackmap.insert({hash_string(str(working_state)),{hash_string(str(working_state)),working_state->actions().front()}}); 

	while (!open.empty())
	{
		state_ptr cur_state = open.front();

		size_t cur_state_hash = hash_string(str(cur_state));
		open.pop();
		if((closed.count(cur_state_hash) >= 1))
		{
			continue;
		}	
		closed.insert(cur_state_hash);
		auto actions = cur_state->actions();
		if(actions.size() == 0)
			continue;
		
		for (size_t i=0; i < actions.size();i++)
		{
			state_ptr new_state = std::make_shared<SearchState>(actions[i].execute(*cur_state));
			if((closed.count(hash_string(str(new_state))) >= 1)
			|| (h_open.count(hash_string(str(new_state))) >= 1))
			{
				continue;
			}			
			backtrackmap.insert({hash_string(str(new_state)),{cur_state_hash,actions[i]}});
			if (new_state->isFinal())
			{	
				std::vector<SearchAction> solution = {};
				cur_state_hash = hash_string(str(new_state));
				size_t child_state = cur_state_hash;
				size_t parent_state = std::get<0>(backtrackmap.at(cur_state_hash));
				while (child_state != parent_state)
				{
					solution.insert(solution.begin(),std::get<1>(backtrackmap.at(child_state)));
					child_state = parent_state;
					parent_state = std::get<0>(backtrackmap.at(child_state));
				}
				return solution;
			}
			h_open.insert(hash_string(str(new_state)));
			open.push(new_state);
		}	
		
	}
	return {};
}


std::vector<SearchAction> DepthFirstSearch::solve(const SearchState &init_state) {

	std::hash<std::string> hash_string;
	std::stack<state_ptr> open;
	std::stack<int> depth;
	std::unordered_set<size_t> closed;
	std::map<size_t,std::tuple<size_t,SearchAction>> backtrackmap;
	state_ptr working_state = std::make_shared<SearchState>(init_state);

	open.push(working_state);
	backtrackmap.insert({hash_string(str(working_state)),{hash_string(str(working_state)),working_state->actions().front()}});
	depth.push(1); // Na úrovni 0 budiž jeden element a tím jest root. - Holy Bible of DFS chapter 0 verse 1

	while (!open.empty())
	{
		state_ptr cur_state = open.top();
		size_t cur_state_hash = hash_string(str(cur_state));
		open.pop();

		
		if (cur_state->isFinal())
		{	
			std::vector<SearchAction> solution = {};
			size_t child_state = cur_state_hash;
			size_t parent_state = std::get<0>(backtrackmap.at(cur_state_hash));

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
		

		if ((depth.size() >= (size_t)this->depth_limit_) || (actions.size() == 0)) // Dosáhl jsem hloubkového limitu nebo nemám kam
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
			for (size_t i=0; i < actions.size();i++)
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


	size_t sum = 0;
	std::vector<int> wantedValues = {1,1,1,1};

	
	for (const auto &home : state.homes) {
        auto top = home.topCard();
		if(top.has_value())
		{
			if(top.value().value == king_value)
			{
				continue;
			}
			wantedValues[(int)top.value().color] = top.value().value + 1;
		}
	}
	bool prazdny_stack = false;
	for(const auto& stack : state.stacks)
	{
		auto stackCards = stack.storage(); 	
		if (stackCards.size() == 0) prazdny_stack = true;
		long unsigned int stacksize = stackCards.size();
		for(long unsigned int i=0;i<stacksize;i++)
		{
			
			if(wantedValues[(int)stackCards[i].color] == stackCards[i].value)
				sum += i;
		}
	}

	if(prazdny_stack)
	{
		return sum;
	}
	else
	{
		for(const auto& freeCell : state.free_cells)
		{
			if(!freeCell.topCard().has_value()) return sum;
		}
		return sum*2;
	}
	return sum*2;
}

std::vector<SearchAction> AStarSearch::solve(const SearchState &init_state) {

	std::priority_queue<AState,std::vector<AState>,std::greater<AState>> open;
	std::unordered_set<size_t> closed;
	std::map<size_t,std::tuple<size_t,SearchAction>> backtrackmap;
	AState working_state(std::make_shared<SearchState>(init_state),-1);
	
	open.push(working_state);
	backtrackmap.insert({working_state.hash(),{working_state.hash(),working_state.state->actions().front()}});

	while (!open.empty())
	{
		AState state = open.top();
		state_ptr cur_state = state.state;
		size_t cur_state_hash = state.hash();
		open.pop();
		

		if (cur_state->isFinal())
		{	
			std::vector<SearchAction> solution = {};
			size_t child_state = cur_state_hash;
			size_t parent_state = std::get<0>(backtrackmap.at(cur_state_hash));

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
		closed.insert(cur_state_hash);
		auto actions = cur_state->actions();

		if (actions.size() == 0)
			continue;
		
		for (size_t i=0; i < actions.size();i++)
		{
			AState new_state(std::make_shared<SearchState>(actions[i].execute(*cur_state)),compute_heuristic(*cur_state,*this->heuristic_));
			open.push(new_state);
			backtrackmap.insert({new_state.hash(),{cur_state_hash,actions[i]}});
		}
		
	}
	return {};
}

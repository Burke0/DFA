/*
 * DFA.cpp
 *J. Alex Burke
 * 3/8/21
 */


#include "DFA.h"


void DFA::add_state(string s)
{
	states.insert(states.end(),s);
}

void DFA::add_final_state(string s)
{
	finalStates.insert(finalStates.end(),s);
}

void DFA::add_alphabet_symbol(string s)
{
	alphabet.insert(alphabet.end(),s);
}

void DFA::add_transition(string beforeState, string symbol, string afterState)
{
	transitions.insert({{beforeState,symbol},afterState});
}

void DFA::set_current_state_to_inital(string s)
{
	currentState=initialState=s;
}

void DFA::display_DFA_desc()
{
	map<pair<string, string>,string>::iterator it = transitions.begin();

	cout<<"\n----DFA--------------------------------------------\n<states>\n";
    copy(states.begin(), states.end(), ostream_iterator<string>(cout," "));
	cout<<"\n<alphabet>\n";
	copy(alphabet.begin(), alphabet.end(), ostream_iterator<string>(cout," "));
	cout<<"\n<transitions>\n";
	while (it != transitions.end())
    {
        string s1 = it->first.first;
        string s2= it->first.second;
        string s3= it->second;
        cout <<"("<<s1 <<", "<<s2<<") -> " << s3 <<endl;
        it++;
    }
	cout<<"<initial state>\n"<<initialState<<"\n<final states>\n";
	copy(finalStates.begin(),finalStates.end(), ostream_iterator<string>(cout," "));
	cout<<"\n---------------------------------------------------------\n";

}
bool DFA::is_symbol_valid(string s)
{
	if(find(alphabet.begin(), alphabet.end(), s) != alphabet.end())
		return true;
	else
	{
		cout<<s<<": invalid symbol"<<endl;
		return false;
	}
}
string DFA::get_current_state()
{
	return currentState;
}
void DFA::transition_to_next_state(string s)
{
	cout<<"->"<<s<<"->";
	if (transitions.count({currentState, s}))
	{
		currentState=transitions.at({currentState, s});
		cout<<"["<<currentState<<"]";
	}
	else
		cout<<" transition failed"<<endl;

}
bool DFA::is_final_state()
{
	if(count(finalStates.begin(), finalStates.end(), currentState))
		return true;
	else
		return false;
}



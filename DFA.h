/*
 *DFA.h
 *J. Alex Burke
 *3/8/21
 *This class is used to build a DFA.
 */
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include<iostream>
#include<iterator>


using namespace std;
class DFA
{
public:

void add_state(string s);
void add_final_state(string s);
void add_alphabet_symbol(string s);
void add_transition(string beforeState, string symbol, string afterState);
void set_current_state_to_inital(string s);
void display_DFA_desc();
bool is_symbol_valid(string s);
string get_current_state();
void transition_to_next_state(string s);
bool is_final_state();



private:
string currentState, initialState;
vector<string> states;
vector<string> alphabet;
vector<string> finalStates;
map <pair<string,string>,string>transitions;

};







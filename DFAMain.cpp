/*
 * DFAMain.cpp
 * J. Alex Burke
 * 3/8/21
 * This program uses the DFA Class to build a DFA from a text file of a specific format.
 * Then, it allows the user to test if a string would be accepted or rejected.
 */
#include "DFA.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int main()
{
	bool repeatFlag = true;
	DFA myDFA;
	fstream newfile;
	string fileName,input;
	cout<<"enter file path: "<<endl;
	cin>>fileName;

	newfile.open(fileName, ios::in);
	while(newfile.is_open()==false)
	{
		cout<<"File did not open. Please re-enter file path: "<<endl;
		cin>>fileName;
		newfile.open(fileName, ios::in);
	}

	cout<<"File opened successfully. Building DFA"<<endl;
	string nextline;

	getline(newfile,nextline);
	getline(newfile,nextline);
	while(nextline.compare("<alphabet>") != 0)
	{
		myDFA.add_state(nextline);
		getline(newfile, nextline);

	}
	getline(newfile,nextline);
	while(nextline.compare("<transitions>") != 0)
	{
		myDFA.add_alphabet_symbol(nextline);
		getline(newfile, nextline);
	}
	getline(newfile,nextline);
	while(nextline.compare("<initial state>") != 0)
	{
		stringstream ss(nextline);
		string t1, t2, t3;
		ss>>t1>>t2>>t3;
		myDFA.add_transition(t1,t2,t3);
		getline(newfile, nextline);
	}
	getline(newfile,nextline);
	while(nextline.compare("<final states>") != 0)
	{
		myDFA.set_current_state_to_inital(nextline);
		getline(newfile, nextline);
	}
	getline(newfile,nextline);
	do
	{
		myDFA.add_final_state(nextline);
	}while(getline(newfile,nextline));
	cout<<"DFA is complete!"<<endl;

	myDFA.display_DFA_desc();

	cout<<"Enter a string to process(Ctrl^C or input x to exit): "<<endl;
	cin>>input;
	while(repeatFlag)
	{
		cout<<"["<<myDFA.get_current_state()<<"]";
		for(unsigned int i=0; i<input.length(); i++)
		{
			if(myDFA.is_symbol_valid(input.substr(i,1)))
				myDFA.transition_to_next_state(input.substr(i,1));
		}
		if( myDFA.is_final_state())
			cout<<" : Accepted"<<endl;
		else
			cout<<" : Rejected"<<endl;
		myDFA.set_current_state_to_inital("q0");
		cout<<"Enter a string to process(Ctrl^C or input x to exit): "<<endl;
		cin>>input;
		if(input=="x")
			repeatFlag=false;
	}

	return 0;

}




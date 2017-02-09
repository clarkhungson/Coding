//----------------------------------------------------------------------------
// Filename: command.cpp
// Author: thson
// Creation date: 2017/02/08
//----------------------------------------------------------------------------
#include "command.h"

set<class Cmd *> Cmd::cmd_set;
int Cmd::count = 0;

Cmd::Cmd(const char * const i_name):name(i_name){
	do_register();

}
Cmd::~Cmd() {
	unregister();
	cout << "deleting .. cmd" << endl;
}

void Cmd::do_register(){
	cmd_set.insert(this);
	count++;
}

void Cmd::unregister()
{
	cmd_set.erase(this);
	count--;
}

void Cmd::do_it(void) {}

void Cmd::do_cmd(const char * const cmdname)
{
	set<class Cmd *>::iterator cur_cmd;
	for (cur_cmd = cmd_set.begin();
		cur_cmd != cmd_set.end();
		++cur_cmd) {
		if (strcmp((*cur_cmd)->name, cmdname) == 0)
		{
			(*cur_cmd)->do_it();
			return;
		}
	}
	//throw(unknown_cmd(cmd_name));
}

void Cmd::showName()
{
	cout << name << endl;
}

Cmd_copy::Cmd_copy(const char * const name): Cmd("copy"){} 

Cmd_copy::~Cmd_copy(){
	cout << "deleting .. copy" << endl;
};

void Cmd_copy::do_it(void)
{
	cout << "copying.." << endl;
}

Cmd_paste::Cmd_paste(const char * const name): Cmd("paste"){} 
void Cmd_paste::do_it(void)
{
	cout << "pasting.." << endl;
}

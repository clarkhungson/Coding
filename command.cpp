#include <stdio.h>
#include <iostream>
using namespace std;
#include <set>
#include <string.h>

class Cmd
{
private:
	static set<class Cmd *> cmd_set;
	const char * const name;
private:
	void do_register(){
		cmd_set.insert(this);
	}
	void unregister()
	{
		cmd_set.erase(this);
	}
public:
	virtual void do_it(void) = 0;
public:
	Cmd(const char * const i_name):name(i_name){
		do_register();
	}
	virtual ~Cmd() {
		unregister();
	}
public:
	static void do_cmd(const char * const cmdname)
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
public:
	void showName()
	{
		cout << name << endl;
	}
};
set<class Cmd *> Cmd::cmd_set;
class Cmd_copy: public Cmd
{
public:
	Cmd_copy(const char * const name): Cmd(name){} 
private:
	void do_it(void)
	{
		cout << "copying.." << endl;
	}
};

int main()
{
	cout << ":P" << endl;
	Cmd_copy * copy = new Cmd_copy("copy");
	copy -> showName();
	Cmd::do_cmd("copy");
	return 0;
}

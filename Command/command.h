//----------------------------------------------------------------------------
// Filename: command.h
// Author: thson
// Creation date: 2017/02/08
//----------------------------------------------------------------------------
class Cmd
{
private:
	// The container of commands
	static set<class Cmd *> cmd_set;
	// Command's name
	const char * const name;
public:
	// The number of commands in container
	static int count;

public:
	// Constructor and Destroyer
	Cmd(const char * const);
	virtual ~Cmd();

private:
	// Register and unregister methods
	void do_register();
	void unregister();
	// Command's doing
	virtual void do_it(void);	
public:
	// Commands doing (public)
	static void do_cmd(const char * const);
	// Show command's name
	void showName();
};

class Cmd_copy: public Cmd
{
public:
	Cmd_copy(const char * const);
	~Cmd_copy();
private:
	void do_it(void);
};

class Cmd_paste: public Cmd
{
public:
	Cmd_paste(const char * const);
private:
	void do_it(void);
};

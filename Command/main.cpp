#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <set>
#include <string.h>
#include "command.cpp"
#include "logging.h"
char * read_from_line_i(FILE *, int, char *, size_t &);
int main()
{
	Cmd * copy = new Cmd_copy("copy");
	Cmd * paste = new Cmd_paste("paste");
	Cmd::do_cmd("copy");
	#if 0
	Msg_printSomething(Cmd::count);
	delete copy;
	Msg_printSomething(Cmd::count);
	#endif

	FILE *f;
	f = fopen("read.txt", "w");
	fprintf(f, "%s\n", "Have a nice day!");
	fprintf(f, "%c\n", 66);
	fprintf(f, "^^");
	fprintf(f, "\n");
	fclose(f);

	FILE *f2;
	f2 = fopen("write.txt", "rw");

	f = fopen("read.txt", "r");
	char * line;
	size_t len = 0;
	ssize_t read;
	// while((read = getline(&line, &len, f)) != -1)
	read_from_line_i(f, 1, line, len);
	cout << line;
	fclose(f);

	fclose(f2);
	return 0;
}

char * read_from_line_i(FILE *f, int i, char * line, size_t & len)
{
	getline(&line, &len, f);
}
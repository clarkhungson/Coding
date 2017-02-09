#define DEBUG 1
#define DEBUG_count 1

#if DEBUG_count
#define Msg_printSomething(X) cout << #X << " = " << X << endl;
#else
#define print(X)
#endif
#ifdef ARGSMGR_H
#define ARGSMGR_H
enum Operation
{
    Create = 0
}

struct argument
{
    enum Operation operation;
    char* tag;
}
#endif
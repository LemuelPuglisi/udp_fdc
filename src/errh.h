
#ifndef ERRH_H
#define ERRH_H

#define ARGS_PASS_ERR "[terminated] Args: [remote ip address] [type: client|server]"
#define SOCK_INIT_ERR "[terminated] Socket cannot be initialized\n"
#define SOCK_BIND_ERR "[terminated] Socket cannot be binded\n"

int report_error (char* error); 

#endif
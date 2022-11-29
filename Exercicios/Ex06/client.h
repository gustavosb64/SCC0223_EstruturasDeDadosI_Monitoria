#ifndef CLIENT_H
#define CLIENT_H


typedef struct client Client;

Client* create_client();

Client* register_client();

char* get_cpf(Client *C);

long int cpf_to_longint(char *cpf);

int print_client(Client *C);

void free_client(Client *C);


#endif
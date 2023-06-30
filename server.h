#ifndef SERVER_H
#define SERVER_H
using namespace std;
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class server
{
public:
    server();
    server(int port);
    static void* echo(void* arg);
private:
    int listenfd, *connfd;
    struct sockaddr_in serverAdd;  /* server's address information */
    struct sockaddr_in *clientAdd; /* client's address information */
    socklen_t sin_size;
    pthread_t tid;
};


#endif // SERVER_H

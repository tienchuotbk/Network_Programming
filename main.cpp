#include "mainwindow.h"
#include "server.h"

#include <QApplication>
#include <stdio.h> /* These are the usual header files */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#define BUFF_SIZE 1024
#define MAX_USERNAME_LENGTH 25
#define MAX_PASSWORD_LENGTH 25
#define BACKLOG 20 /* Number of allowed connections */
void printData(){
    printf("Helllo");
}
void *echo(void *arg)
{
    int connfd;
    char temp[BUFF_SIZE];
    char letters[BUFF_SIZE];
    char digits[BUFF_SIZE];
    int split_result;
    int bytes_sent, bytes_received;
    char buff[BUFF_SIZE + 1];

    connfd = *((int *)arg);
    free(arg);
    pthread_detach(pthread_self());

    while (1)
    {

        bytes_received = recv(connfd, buff, BUFF_SIZE - 1, 0);

        if (bytes_received < 0)
            perror("\nError: ");
        else
        {
            printf("Gedata");
        }
    }
    printf("Client closed connection\n");

    close(connfd);
}

int main(int argc, char *argv[])
{

    server *hh = new server(5000);
    QApplication a(argc, argv);
    printData();
    MainWindow w;
    w.show();
    return a.exec();
}

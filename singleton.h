#ifndef SINGLETON_H
#define SINGLETON_H
#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "loginform.h"
#include "mainwindow.h"
using namespace std;


class Singleton {
public:
    // Method to get the singleton instance
    static Singleton& getInstance();
    char* sendandrecieve(char *str);
    loginForm* f;
    MainWindow* w;
    void closeConection();
    // Other public member functions

private:
    // Private constructor to prevent instantiation
    Singleton();
    int client_sock;
    char* buff;
    struct sockaddr_in server_addr;
    int msg_len, bytes_sent, bytes_received;

    // Private copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

#endif // SINGLETON_H

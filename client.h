#ifndef CLIENT_H
#define CLIENT_H
using namespace std;

#include <QMainWindow>
#include <QWidget>

class client
{
public:
    client();
    client(string add, int port);
    int getUserId();
    int userId;
};


#endif // CLIENT_H

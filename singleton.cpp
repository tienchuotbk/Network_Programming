#include "singleton.h"
#include "client.h"
#include <stdio.h> /* These are the usual header files */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <QString>
#include "loginform.h"
#define BUFF_SIZE 1024

Singleton::Singleton() {
    // Constructor implementation
    this->client_sock = socket(AF_INET, SOCK_STREAM, 0);
    // Step 2: Specify server address
    this->server_addr.sin_family = AF_INET;
    this->server_addr.sin_port = htons(5000);
    this->server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(this->client_sock, (struct sockaddr *)&this->server_addr, sizeof(struct sockaddr)) < 0)
    {
        printf("\nError!Can not connect to sever! Client exit imediately! ");
        return ;
    } else {
        printf("Ok\n");
    }
    this->f = new loginForm;
    this->w = new  MainWindow();
    this->f->show();
}

Singleton& Singleton::getInstance() {
    static Singleton instance;
    return instance;
}
char* Singleton::sendandrecieve(char* str){
    printf("Sned %s\n", str);
    char* temp = (char*)malloc(sizeof(char*));
    this->bytes_sent = send(this->client_sock, str, strlen(str), 0); //Send message to server
    if (this->bytes_sent < 0)
    {
        perror("Error: ");
        close(this->client_sock);
        return temp;
    } else {
        printf("Send message Ok\n");
    }

    this->bytes_received = recv(this->client_sock, temp, BUFF_SIZE - 1, 0); //Get message from server
    if (this->bytes_received < 0)
    {
        perror("Error: ");
        close(this->client_sock);
        return temp;
    }
    temp[this->bytes_received] = '\0';
    printf("Gettt recceive from seerver:%s\n", temp);
    return temp;

}
void Singleton::closeConection(){
    close(this->client_sock);
}

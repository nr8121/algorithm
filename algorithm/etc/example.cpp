/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//socket
#include <sys/socket.h>
//sockaddr_in
#include <netinet/in.h>
//inet_ntoa
#include <arpa/inet.h>
//close
#include <unistd.h>

#define PORT 12346
#define BUF_SIZE 1024

int main(){
    int socket_fd,accepted_fd;
    struct sockaddr_in host_addr, client_addr;
    socklen_t size;
    int recv_length;
    char buffer[BUF_SIZE];

    socket_fd=socket(PF_INET,SOCK_STREAM,0);

    host_addr.sin_family=AF_INET;
    host_addr.sin_port=htons(PORT);
    host_addr.sin_addr.s_addr=0;
    memset(&(host_addr.sin_zero),0,8);

    bind(socket_fd,(struct sockaddr *)&host_addr,sizeof(struct sockaddr));

    listen(socket_fd,3);

    while(1){
            size=sizeof(struct sockaddr_in);
            accepted_fd=accept(socket_fd,(struct sockaddr *)&client_addr,&size);

            send(accepted_fd,"Connected",10,0);
            printf("Client Info : IP %s, Port %d\n", inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

            recv_length=recv(accepted_fd,&buffer,BUF_SIZE,0);
            while(recv_length>0){
                    printf("From Client : %s\n",buffer);
                    recv_length=recv(accepted_fd,&buffer,BUF_SIZE,0);
            }

            close(accepted_fd);
    }
    return 0;

}
*/


/*
#include <iostream>
#include "example.h"

class Test{
    public:
        Test();
        ~Test();
        bool start();
};

bool Test::start(){
    printf("start!\n");
    return true;
}
int main(){
    t->start();
}
*/

#include <iostream>
#include <stdlib.h>

struct Node
{
    Node* left = 0;
    Node* right = 0;
    int value;
};
void inorder(Node* node)
{
    if(node->left)
    {
        inorder(node->left);
    }
    printf("%d ", node->value);
    if(node->right)
    {
        inorder(node->right);
    }
}
void remove(Node* node)
{
    node = node->left;
}


int main()
{
    Node* nd = new Node;
    nd->value = 1;

    Node* temp = new Node;
    temp->value = 2;

    nd->left = temp;
    remove(nd);
    inorder(nd);
}
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "conn.h"


int initialize_inet_socket (int* sockfd)
{
    *sockfd = socket (AF_INET, SOCK_DGRAM, 0); 

    return *sockfd >= 0; 
}


void init_local_sockaddr (struct sockaddr_in* localaddr)
{
    memset((char *) localaddr, 0, SAIN_LEN); 
    localaddr->sin_family   = AF_INET; 
    localaddr->sin_port     = htons(APPL_PORT); 
}


void init_remote_sockaddr (struct sockaddr_in* remoteaddr, char *remote_ip_address)
{
    memset((char *) remoteaddr, 0, SAIN_LEN); 
    remoteaddr->sin_family = AF_INET; 
    remoteaddr->sin_port = htons(APPL_PORT); 
    inet_pton(AF_INET, remote_ip_address, &(remoteaddr->sin_addr)); 
}


int bind_socket (int sockfd, struct sockaddr_in* localaddr)
{
    return bind(sockfd, (struct sockaddr *) localaddr, SAIN_LEN) >= 0;  
}


void listen_to_message (int sockfd, struct sockaddr_in *remoteaddr, char *buffer)
{
    socklen_t len = sizeof(struct sockaddr_in); 

    recvfrom (sockfd, buffer, 256, 0, (struct sockaddr *) &remoteaddr, &len); 
}


void send_message_to_server (int sockfd, struct sockaddr_in *remoteaddr, char *buffer)
{
    sendto(sockfd, buffer, 256, 0, (struct sockaddr *) &remoteaddr, SAIN_LEN); 
}
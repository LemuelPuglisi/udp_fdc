#ifndef CONN_H
#define CONN_H

#define APPL_PORT 6660
#define SAIN_LEN sizeof(struct sockaddr_in)


/**
 * Initialize the socket with AF_INET family 
 * using SOCK_DGRAM communication
 * 
 * @param int* sockfd | socket to initialize
 * @return positive integer if socket call is successfull
 */
int initialize_inet_socket (int* sockfd); 


/**
 * Initialize the struct sockaddr_in with the  
 * listening port and AF_INET family
 * 
 * @param struct sockaddr_in* localaddr | sockaddr_in to configure
 * @param char *remote_ip_address | ip address of comunicating machine 
 * @return void 
 */
void init_local_sockaddr (struct sockaddr_in* localaddr); 


/**
 * Initialize the struct sockaddr_in with the  
 * listening port and AF_INET family
 * 
 * @param struct sockaddr_in* localaddr | sockaddr_in to configure
 * @param char *remote_ip_address | ip address of comunicating machine 
 * @return void 
 */
void init_remote_sockaddr (struct sockaddr_in* remoteaddr, char *remote_ip_address); 


/**
 * Bind a socket within an existing sockaddr_in 
 *
 * @param int sockfd | socket descriptor 
 * @param struct sockaddr_in* localaddr | configured sockaddr_in
 * @return positive integer if binding is successfull
 */
int bind_socket (int sockfd, struct sockaddr_in* localaddr); 


/**
 * Listen to a datagram to be received. 
 * Also put remote sockaddr_in in the sockaddr_in param 
 *
 * @param int sockfd | listening socket
 * @param struct sockaddr_in* remoteaddr | to host remote sockaddr 
 * @param char* buffer | buffer where message will be stored
 * @return void 
 */
void listen_to_message (int sockfd, struct sockaddr_in *remoteaddr, char *buffer); 


/**
 * Send a message to the server host 
 *
 * @param int sockfd | sending socket
 * @param struct sockaddr_in* remoteaddr | host to send message
 * @param char* buffer | message to send 
 * @return void
 */
 void send_message_to_server (int sockfd, struct sockaddr_in *remoteaddr, char *buffer); 

#endif
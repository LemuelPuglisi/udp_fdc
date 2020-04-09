/**
 * Two way messaging tool 
 * through UDP datagrams 
 *
 * @university UniCT
 * @author Lemuel Puglisi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#include "errh.h"
#include "conn.h"
#include "colr.h"


void print_message_to_screen (struct sockaddr_in *remote_addr, char* buffer)
{
    char* remote_ip_rcv   = inet_ntoa(remote_addr->sin_addr); 
    short remote_port_rcv = ntohs(remote_addr->sin_port); 

    printf(
        "[%s:%u] %ssays%s \"%s\"\n", 
        remote_ip_rcv, 
        remote_port_rcv, 
        GRN, 
        END, 
        buffer
    ); 
}


int main (int argc, char* argv[]) 
{
    int sockfd;
    struct sockaddr_in local_addr;  
    struct sockaddr_in remote_addr;  

    char* remote_ip_address; 
    char* init_state; 
    char* current_state; 


    char rcv_buffer[256]; 
    char snd_buffer[256]; 

    if (argc < 3 || (strcmp(argv[2], "client") == 0 && strcmp(argv[2], "server") == 0)) {

        return report_error(ARGS_PASS_ERR); 
    }

    remote_ip_address   = argv[1];
    current_state = init_state = argv[2]; 

    if (initialize_inet_socket(&sockfd) == 0) {

        return report_error(SOCK_INIT_ERR); 
    }

    init_local_sockaddr(&local_addr); 

    init_remote_sockaddr(&remote_addr, remote_ip_address); 

    if (bind_socket(sockfd, &local_addr) == 0) {

        return report_error(SOCK_BIND_ERR); 
    }  

    system("clear"); 
    printf("\n[%sready%s][%s%s%s] ready to go through network\n", GRN, END, YEL, current_state, END); 

    while (1 == 1) {

        if (strcmp(current_state, "server") == 0) {

            listen_to_message(sockfd, &remote_addr, rcv_buffer); 

            // we received a message! 
            if (strcmp(rcv_buffer, "") != 0) {

                print_message_to_screen(&remote_addr, rcv_buffer); 
            }
        }


        else if (strcmp(current_state, "client") == 0) {

            printf("[%swaiting%s] digit a number: ", YEL, END); 
            scanf("%d", &snd_buffer); 

            send_message_to_server (sockfd, &remote_addr, snd_buffer); 
        }
    }
}


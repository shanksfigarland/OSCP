#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int sockets;
    int connection;
    char *target_ip;
    
    struct sockaddr_in target;
    
    if(argc != 2){
        printf("Usage: %s <target url>\n",argv[0]);
        printf("Example: %s domain.com\n",argv[0]);
    }else{
        struct hostent *ip = gethostbyname(argv[1]);
        if(ip == NULL){
        printf("Invalid hostname!\n");
        }else{ 
            target_ip = inet_ntoa(*((struct in_addr *)ip->h_addr)); 
            printf("Port's found in %s:\n",target_ip);
            for(int i=1; i != 65535; i++){
                sockets = socket(AF_INET, SOCK_STREAM, 0);

                target.sin_family = AF_INET;

                target.sin_port = htons(i);

                target.sin_addr.s_addr = inet_addr(target_ip);

                connection = connect(sockets, (struct sockaddr *)&target, sizeof(target));
            
                if(connection == 0){
                    printf("%i port is open!!\n",i);
                    close(sockets);
                    close(connection); 
                } else {
                    close(sockets);
                    close(connection); 
                }
            }
        }
    }
    return 0;
}

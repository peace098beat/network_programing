#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    
    int sock;
    
    // AF_INET: IPv4
    // SOCK_STREAM: TCP
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sock < 0){
        printf("socket(%d) failed\n", sock);
        return 1;
    }else{
        printf("socket(%d) sccess\n", sock);
    }
    
    
    
    
    return 0;
}
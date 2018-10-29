#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <errno.h> // errno


int main(){
    
    int sock0;
    
    struct sockaddr_in addr;
    struct sockaddr_in client;
    int len;
    int sock;
    
    /* create socket */
    sock0 = socket(AF_INET, SOCK_STREAM, 0);
    
    /* Setting to Socket */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_ANY;
    
    bind(sock0, (struct sockaddr *)&addr, sizeof(addr));
    
    /* TCP Listen */
    listen(sock0, 5);

    
    while(1){
        /* start TCP Connection */
        len = sizeof(client);
        sock = accept(sock0, (struct sockaddr *)&client, &len);
        
        /* send 5chars */
        write(sock, "HELLO", 5);
        
        /* Close TCP Session */
        close(sock);        
    }
    
    /* Close Socket */
    close(sock0);
  
    
    return 0;
}
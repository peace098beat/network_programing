#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(){
    
    int sock0;
    
    struct sockaddr_in addr;
    struct sockaddr_in client;
    int len;
    int sock;
    int n;
    
    /* create socket */
    sock0 = socket(AF_INET, SOCK_STREAM, 0);
    if(sock0 < 0){
        perror("socket");
        return 1;
    }
    
    /* Setting to Socket */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345); // ホストバイトオーダーとネットワークバイトオーダーの間で値を変換する  
    addr.sin_addr.s_addr = INADDR_ANY;
    
    /* TIME_WAIT状態のポートが存在してもbindできるようになる */
    int yes = 1;
    setsockopt(sock0, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes));
    
    if(bind(sock0, (struct sockaddr *)&addr, sizeof(addr)) != 0){
        perror("bind");
        close(sock0);
        
        return 1;
    }
    
    /* TCP Listen */
    if(listen(sock0, 5) != 0){
        perror("listen");
        return 1;
    }

    printf("Listen .. \n");
    
    while(1){
        /* start TCP Connection */
        len = sizeof(client);
        sock = accept(sock0, (struct sockaddr *)&client, &len);
        if(sock < 0){
            perror("accept");
            break;
        }
        
        printf("accepted connection from %s, port=%d\n",
        inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        
        /* send 5chars */
        n = write(sock, "HELLO", 5);
        if(n<1){
            perror("write");
            break;
        }
        
        /* Close TCP Session */
        close(sock);        
    }
    
    /* Close Socket */
    close(sock0);
  
    
    return 0;
}
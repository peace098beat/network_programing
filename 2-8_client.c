#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h> // memset
#include <errno.h> // errno


int main(int argc, char *argv[]){
    
    
    struct sockaddr_in server;
    int sock;
    char buf[32];
    char *deststr;
    unsigned int **addrptr;
    int n;
    
    /* Argument Check */
    if(argc != 2){
        perror("argc");
        printf("[ ERROR ] Usage : %s <<IPADDR: (Ex)192.0.0.1>>\n", argv[0]);
        return 1;
    }
    
    deststr=argv[1];
    printf("[ OK ] hostname : %s\n", deststr);
    
        
    /* Make Socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("[ ERROR ] Socket");
        return 1;
    }else{
        perror("[ OK ] Create Socket");
    }
    
    /* 接続先指定用構造体の準備 */
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = inet_addr(deststr);
    
    if(server.sin_addr.s_addr == 0xffffffff){
        struct hostent *host;
        
        host = gethostbyname(deststr);
        if(host==NULL){
            perror("[ ERROR ] gethostbyname\n");
            printf("[ ERROR ] '%s' is not hostname \n", deststr);
            return 1;
        }else{
            printf("[ OK ] '%s' is hostname \n", deststr);
        }
        
        addrptr = (unsigned int **)host->h_addr_list;
        while(*addrptr != NULL){
            server.sin_addr.s_addr = *(*addrptr);
            
            n = connect(sock, (struct sockaddr *)&server, sizeof(server));
            if(n == 0){
                printf("[ OK ] Server connect\n");
                break;
            }
            addrptr++;
        }

    }else{
        /* inet_addr()が成功したとき */
        n = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if(n != 0){
            perror("[ ERROR ] Server connect\n");
            return 1;
        }
    }
    
    /* サーバーからデータを受信 */
    memset(buf, 0, sizeof(buf));
    n = read(sock, buf, sizeof(buf));
    
    printf("---------------\n");
    printf("%s\n", buf);
    printf("---------------\n");
    
    /* socketの終了 */
    if( close(sock) < 0 ){
        perror("CLOSE");
    }
    
    printf("[ OK ] fin.. \n");
    
    
    
    return 0;
}
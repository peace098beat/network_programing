#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> //inet_ntoa
#include <string.h> // memset

int main(){
    
    int sock0;
    
    struct sockaddr_in addr;
    struct sockaddr_in client;
    int len;
    int sock;
    
    int n; // 送信データ書き込みバイト数
    
    /* HTML返却用 */
    char buf[2048];
    char inbuf[2048];
    
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
    
    /* ソケットに名前をつける  */
    if(bind(sock0, (struct sockaddr *)&addr, sizeof(addr)) != 0){
        perror("[ ERROR ] bind");
        close(sock0);
        return 1;
    }else{
        printf("[ OK ] Server Socket: from %s, port=%d\n",
                             inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
    }
    
    
    /* TCP Listen */
    if(listen(sock0, 5) != 0){
        perror("[ ERROR] listen");
        return 1;
    }else{
        printf("[ OK ] Listen .. \n");
    }
    
    /* 応答用HTTPメッセージ作成 */
    memset(buf, 0, sizeof(buf));
    snprintf(buf, sizeof(buf),
                "HTTP/1.0 200 OK\r\n"
                "Content-Length: 20\r\n"
                "Content-Type: text/html\r\n"
                "\r\n"
                "HELLO\r\n");
    
    while(1){
        /* start TCP Connection */
        len = sizeof(client);
        sock = accept(sock0, (struct sockaddr *)&client, &len);
        if(sock < 0){
            perror("[ ERROR ] accept");
            break;
        }else{
            printf("[ OK ] accepted connection from %s, port=%d\n",
                    inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        }
        
        
        /* クライアントからメッセージの受け取り */
        // memset(inbuf, 0, sizeof(inbuf));
        // recv(sock, inbuf, sizeof(inbuf), 0);
        
        /* クライアントからの要求内容をパース */
        /* ... */
        
        /* 返信 */
        n = send(sock, buf, (int)strlen(buf), 0); //ソケットへメッセージを送る  
        
        // n = write(sock, "HELLO", 5);
        if(n<1){
            perror("[ ERROR ] write\n");
            break;
        }else{
            printf("[ OK ] Send Message %d\n", n);
        }
        
        /* Close TCP Session */
        close(sock);        
    }
    
    /* Close Socket */
    close(sock0);
  
    
    return 0;
}
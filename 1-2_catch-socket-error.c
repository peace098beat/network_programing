#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>


#include <errno.h> // errno


int main(){
    
    int sock;
    
    // try error
    sock = socket(3000, 4000, 5000);
    
    if(sock < 0){
        printf("[ NG ] socket(%d) failed\n", sock);
        perror("socket");
        printf("[ NG ] Error No: %d\n", errno);
        return 1;
    }else{
        printf("[ OK ] socket(%d) sccess\n", sock);
    }
    
    
    
    
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
 
struct {
long mtype;
char mtext[50];
} buf;
 
int main()
{
int j;
#define KLUCZ 123
int id_kolejki=msgget(KLUCZ, IPC_CREAT);
buf.mtype=123;
fread(buf.mtext,50,1,stdin);
j=msgsnd(id_kolejki, &buf, 50, 0);
if(j==-1) perror("msgsnd");
}

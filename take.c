#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <time.h>
 
struct {
        long mtype;
        char mtext[50];
} buf;
 
int main()
{
        int i = 1, j;
        int id_kolejki = 123;
 
        time_t wsk_sekund;
        time(&wsk_sekund);
 
        if (localtime(&wsk_sekund)->tm_mday >= 5)
        {
                j = msgrcv(id_kolejki, &buf, 50, 123, 0);
                if (j == -1) { perror("msgrcv"); }
                if ((buf.mtext[0] > 64 && buf.mtext[0]<91) || (buf.mtext[0]>96 && buf.mtext[0]<123))
                {
                        do
                        {
                                i++;
                        } while (buf.mtext[i]>32 && buf.mtext[i]<127);
                }
                else {
printf("komunikat nie zaczyna sie od litery!");
                }
                if (buf.mtext[i]>32 && buf.mtext[i] < 127)
                {
                        printf("otrzymany komunikat to: %s\n", buf.mtext);
                        i = 1;
                }
                else {
                        printf("komunikat ma znaki specjalne!");
                }
        }
        else {
                printf("nie ma weekendu, nie ma komunikatu.");
}
}

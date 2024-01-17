// C Program for Message Queue (Reader Process) 
#include <stdio.h> 
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

// structure for message queue 
struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[100]; 
} message; 

int main() 
{ 
	key_t key; 
	int msgid, toend; 

	// ftok to generate unique key 
	key = ftok("progfile", 65); 

	// msgget creates a message queue 
	// and returns identifier 
	msgid = msgget(key, 0644); 

	// msgrcv to receive message 
    for(;;) 
    {
	    if(msgrcv(msgid, &message, sizeof(message), 0, 0) == -1)
        {
            perror("msgrcv");
            exit(1);
        }
        
        printf("Data Received is : %s \n", 
					message.mesg_text); 
        toend = strcmp(message.mesg_text,"end");
        if (toend == 0)
            break;            
    }
	// display the message 
	

	// to destroy the message queue 
	msgctl(msgid, IPC_RMID, NULL); 

	return 0; 
} 

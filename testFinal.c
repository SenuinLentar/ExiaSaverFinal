#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/time.h> 
#include <termios.h>  


static struct termios g_old_kbd_mode; 


// put the things as they were befor leave..!!! 
static void old_attr(void)
{ 
    tcsetattr(0, TCSANOW, &g_old_kbd_mode); 
} 

int main()
{
    char touche='\0'; 
    static char init; 
    struct termios new_kbd_mode; 
	

    if(init) 
    {
        return 0; 
    }
    
    // put keyboard (stdin, actually) in raw, unbuffered mode 
    tcgetattr(0, &g_old_kbd_mode); 
    memcpy(&new_kbd_mode, &g_old_kbd_mode, sizeof(struct termios)); 
     
    new_kbd_mode.c_lflag &= ~(ICANON | ECHO); 
    new_kbd_mode.c_cc[VTIME] = 0; 
    new_kbd_mode.c_cc[VMIN] = 1; 
    tcsetattr(0, TCSANOW, &new_kbd_mode); 
    atexit(old_attr); 
     
   // printf( "Press Any Key for exit\n"); 
    

        touche = getchar();
        if(touche!='0')
		{
			//printf("Quitte\n");
 			exit (0);
		}
        return 0; 

    } 
    
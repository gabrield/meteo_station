#include <stdio.h>
#include <string.h>  
#include <unistd.h>
#include <time.h>
#include <xively.h>
#include <xi_helpers.h>

#include "serial_lib.h"


int main(int argc, char **argv)
{
    int fd = 0 ;    
    /*int baudrate = 9600;*/  /* default */
    /*char quiet=0;*/
    char eolchar = '\n';
    int timeout = 6000;
    char buf[MAX_BUFF];
    unsigned int counter = 0;
    unsigned int len = 0;
    float light = 0;
    float temperature = 0;
    unsigned int rain;
    char **c = malloc(3*sizeof(char*));
    
    c[0]  = malloc(sizeof(char)*5);
    strcpy(c[0], "aaaaa");
    c[1]  = "b";
    c[2]  = "c";


    printf("%s\n", c[0]);
    printf("%d\n", *c[0]);
    printf("%d\n", *c[1]);
    printf("%d\n", *c[2]);
    printf("%d\n", **c);
    **c++;
    **c++;
    printf("%d\n", **c);






    fd = serialport_init(argv[1], 9600);

c[0] =  "opa;"; 
    // create the xi library context
    xi_context_t* xi_context
        = xi_create_context(
                  XI_HTTP, argv[ 2 ]
                , atoi( argv[ 3 ] ) );

    // check if everything works
    if( xi_context == 0 )
    {
        return -1;
    }


    if(fd != -1)
    {    
	while(1)
	{
	    serialport_read_until(fd, buf, eolchar, MAX_BUFF, timeout);
	    len = strlen(buf);
    
	    if(len > 1)
	    {
		    sscanf(buf, "[%f,%i,%f]", &temperature, &rain, &light);
		    printf("=====%i time(s)=====\n", counter++);
		    printf("TEMPERATURE > %2.1f\n", temperature);
		    printf("RAIN        > %s\n", (rain ? "NO" : "YES"));
		    /*printf("RAIN LEVEL  > %d%%\n", 100-(100*rain_level)/1024);*/
		    printf("LIGHT (LUX) > %f\n", light);
		    memset(buf, 0, MAX_BUFF);
	    }
	    usleep(100);
	}
    }
    return 0;
}



#include <stdio.h>
#include <fcntl.h>

int main()
{


char buff[16];
int fd = open("file.txt",O_RDONLY);
unlink("file.txt");
read(fd,buff,sizeof(buff));
printf("buff == %s\n",buff);
close(fd);

return 0;
}

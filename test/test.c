#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
  int fd, n;
  char buf[10];
  if((fd = open(argv[1], O_RDONLY)) < 0)
  {
      write(1, "File open error\n", 15);
      return 0;
  }
  else
  {
    n = read(fd, buf, 6);
    close(fd);
    buf[n] = '\n';
    n = write(1, buf, n+1);
    //printf("fd is %d and read %d byte. result is %s", fd, n, buf);
  }
  return 0;
}

#include "dex_format.h"

int main(int argc, char *argv[])
{
  int fd; // file descriptor
  if(argc == 2) // if 2 argument ?
  {
    if((fd = open(argv[1], O_RDONLY)) > 0) // file exits?
    {
      /*Some works about parsing*/
      char str[] = "File Opened Successfully\n";
      write(1, str, sizeof(str));
      dex_parser_header(fd);
    }
    else
    {
      char str[] =  "There is no such file\n";
      write(1,str,sizeof(str)); // print error
      return 0;
    }
  }
  else
  {
    char str[] = "Wrong Format.\nYou sould follow format\nparser [filepath]\n";
    write(1, str,sizeof(str));// print error
    return 0;
  }
  return 0;
}

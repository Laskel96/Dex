#include "dex_format.h"
#include <sys/mman.h>
#include <stdio.h>

void dex_parser_header(int fd)
{
  char str[] = "dex_parser_header called\n";
  write(1, str , sizeof(str));
  unsigned char * f;
  f = mmap(0, sizeof(header_item), PROT_READ, MAP_PRIVATE, fd, 0);
  //write(1, f, sizeof(header_item));

  int i;
  for(i = 0; i < sizeof(header_item); i++)
  {
    printf("data in raw : %d\n", f[i]);
  }
  printf("size : %d", i);


}

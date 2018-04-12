#include "dex_format.h"
#include <sys/mman.h>

void dex_parser_header(int fd, header_item ** h_item)
{
  if((*h_item = (header_item *)mmap(0, sizeof(header_item), PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED) // mmap failed
  {
    char str[] = "Error occurs while header parsing. (mmap)\n";
    write(1, str , sizeof(str));
  }
 else// mmap success
 {
   char str[] = "pasre header successfully\n";
   write(1, str , sizeof(str));
 }
}

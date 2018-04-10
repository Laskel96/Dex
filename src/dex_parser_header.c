#include "dex_format.h"

void dex_parser_header(int fd)
{
  char[] str = "dex_parser_heard called\n"
  write(1, str , sizeof(str));
}

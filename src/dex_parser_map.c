#include "dex_format.h"
#include <sys/mman.h>

void dex_parser_map(int fd, map_item ** m_item)
{
  if((*h_item = (header_item *)mmap(0, sizeof(header_item), PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED) // mmap failed
}

#include "dex_format.h"

void parse(char * file, header_item ** h_item, uint32_t ** map_list_size, map_item ** map_item_list)
{
  *h_item = (header_item *)file; // header_item => start from 0 to header_item struct size

  *map_list_size = (uint32_t *)(file + (*h_item)->map_off); // map_list_size => start from 0 to map offset
  *map_item_list = (map_item *)(file + (*h_item)->map_off + sizeof(uint32_t)); // map_item_list => start from 0 to (map offset + map_list size)
}

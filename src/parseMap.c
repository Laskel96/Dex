#include "dex_format.h"

void parseMap(char * base, map_list * mlist, uint32_t offset)
{
  if(memmove(&mlist->size, base+offset, sizeof(uint32_t)) != NULL)
  {
    mlist->list = malloc(sizeof(map_item) * mlist->size);
    if(memmove(mlist->list, base+offset+sizeof(uint32_t), sizeof(map_item)*mlist->size) != NULL)
    {
      char str[] = "Map Parsed Successfully\n";
      write(1, str, sizeof(str));
    }
  }
}

void map_list_test(map_list mlist)
{
  int i;
  printf("------map list------\n");
  printf("list size : %d\n", mlist.size);
  for(i = 0; i < mlist.size; i++)
  {
    printf("%d element offset : %d\n", i, mlist.list[i].offset);
  }
}

#include "dex_format.h"
#include <stdio.h>

void header_test(header_item * h_item);
void map_list_test(uint32_t * size, map_item * list);

void print_test(header_item * h_item, uint32_t * map_list_size, map_item * map_item_list)
{

  header_test(h_item); // test head parser
  map_list_test(map_list_size, map_item_list); // test map parser

}

void header_test(header_item * h_item)
{
  int i;
  printf("------header------\n");
  printf("dex magic : ");
  for(i = 0; i < 8; i++)
  {
    printf("%02x ", h_item->magic[i]);
  }
  printf("\nchecksum : %02x\n", h_item->checksum);
  printf("signature : ");
  for(i = 0; i < 20; i++)
  {
    printf("%02x ", h_item->signature[i]);
  }
  printf("\nfile_size : %d\n", h_item->file_size);
  printf("size : %d\n", i);
}

void map_list_test(uint32_t * size, map_item * list)
{
  int i;
  printf("------map list------\n");
  printf("list size : %d\n", *size);
  for(i = 0; i < *size; i++)
  {
    printf("%d element offset : %d\n", i, list[i].offset);
  }
}

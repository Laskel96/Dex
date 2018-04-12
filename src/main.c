#include "dex_format.h"
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>

void header_test(header_item * h_item);
//void map_list_test(map_list * m_list);
void map_list_test(uint32_t * size, map_item * list);

int main(int argc, char *argv[])
{
  int fd; // file descriptor
  struct stat sb;
  char * file;
  header_item * h_item; // store parsed header
  map_list * m_list; // store parsed map list;
  uint32_t * map_list_size;
  map_item * map_item_list;

  if(argc == 2) // if 2 argument ?
  {
    if((fd = open(argv[1], O_RDONLY)) > 0) // file exits?
    {
      /*Some works about parsing*/
      char str[] = "File Opened Successfully\n";
      write(1, str, sizeof(str));

      if((lstat(argv[1], &sb)) == -1) // get file size from path
      {
        char err[] = "Error while Istat\n";
        write(1, err, sizeof(err));
      }

      if((file = (char *)mmap(0, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED) //read entire file
      {
        char err[] = "Error while mmap\n"; // mmap failed
        write(1, err, sizeof(err));
      }

      //dex_parser_header(fd, &h_item); // paser header
      h_item = (header_item *)file; // header_item => start from 0 to header_item struct size
      header_test(h_item); // test head parser

      map_list_size = (uint32_t *)(file + h_item->map_off); // map_list_size => start from 0 to map offset
      map_item_list = (map_item *)(file + h_item->map_off + sizeof(uint32_t)); // map_item_list => start from 0 to (map offset + map_list size)
      map_list_test(map_list_size, map_item_list); // test map parser

      close(fd);
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

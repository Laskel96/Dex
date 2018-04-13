#include "dex_format.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>

void header_test(header_item * h_item);
void map_list_test(uint32_t * size, map_item * list);

int main(int argc, char *argv[])
{
  int fd; // file descriptor
  struct stat sb;
  char * file;
  header_item * h_item; // store parsed header
  uint32_t * map_list_size; // store size of map_list
  map_item * map_item_list; //

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
      parse(file, &h_item, &map_list_size, &map_item_list);
      print_test(h_item, map_list_size, map_item_list);
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

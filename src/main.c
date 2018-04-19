#include "dex_format.h"
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  int fd; // file descriptor
  struct stat sb;
  char * base;
  header_item hitem; // store parsed header
  map_list mlist;
  string_id_item * si_item;
  string_data_item * sd_item;

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

      if((base = (char *)mmap(0, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED) //read entire file
      {
        char err[] = "Error while mmap\n"; // mmap failed
        write(1, err, sizeof(err));
      }

      parseHeader(base, &hitem);
      header_test(hitem);
      parseMap(base, &mlist, hitem.map_off);
      map_list_test(mlist);
      parseStringId(base, &si_item, hitem.string_ids_size, hitem.string_ids_off);
      string_id_test(si_item);
      parseStringData(base, &sd_item, hitem.string_ids_size, si_item);
      string_data_test(sd_item);
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

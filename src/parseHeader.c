#include "dex_format.h"

void parseHeader(char * base, header_item * hitem)
{
  if(memmove(hitem, base, sizeof(header_item)) != NULL)
  {
    char str[] = "Header Parsed Successfully\n";
    write(1, str, sizeof(str));
  }
}

void header_test(header_item hitem)
{

  int i;
  printf("------header------\n");
  printf("dex magic : ");
  for(i = 0; i < 8; i++)
  {
    printf("%02x ", hitem.magic[i]);
  }
  printf("\nchecksum : %02x\n", hitem.checksum);
  printf("signature : ");
  for(i = 0; i < 20; i++)
  {
    printf("%02x ", hitem.signature[i]);
  }
  printf("\nfile_size : %d\n", hitem.file_size);
  printf("size : %d\n", i);

}

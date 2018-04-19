#include "dex_format.h"

void parseStringId(char * base,  string_id_item ** si_item, uint32_t size , uint32_t offset)
{
  *si_item = malloc(sizeof(uint32_t)*size);
  if(memmove(*si_item, base+offset, sizeof(uint32_t)*size) != NULL)
  {
    char str[] = "String Parsed Successfully\n";
    write(1, str, sizeof(str));
  }
  else{
    free(si_item);
  }
}

void parseStringData(char * base, string_data_item ** sd_item, uint32_t size, string_id_item * si_item)
{
  uint8_t * string_data;
  int i;
  string_data = base + si_item[0].string_data_off;
  *sd_item = malloc(sizeof(string_data_item)*size);

  for(i = 0; i < size; i ++)
  {
    (*sd_item)[i].utf16_size = readUnsignedLeb128(&string_data);
    (*sd_item)[i].data = malloc(sizeof(uint8_t *)*(*sd_item)[i].utf16_size+1);
    memmove((*sd_item)[i].data, string_data, (*sd_item)[i].utf16_size+1);
    string_data += (*sd_item)[i].utf16_size+1;
  }
}

void string_id_test(string_id_item * si_item)
{
  printf("------string id------\n");
  printf("0 string data off : %d\n", si_item[0].string_data_off);
  printf("10 string data off : %d\n", si_item[100].string_data_off);
  printf("100 string data off : %d\n", si_item[1000].string_data_off);
  printf("4309 string data off : %d\n", si_item[4309].string_data_off);
}

void string_data_test(string_data_item * sd_item)
{
  printf("------string data------\n");
  printf("[100]th size : %d\n", sd_item[100].utf16_size);
  printf("[100]th data : %s\n", sd_item[100].data);
  printf("[800]th size : %d\n", sd_item[800].utf16_size);
  printf("[800]th data : %s\n", sd_item[800].data);
  printf("[3000]th size : %d\n", sd_item[3000].utf16_size);
  printf("[3000]th data : %s\n", sd_item[3000].data);
}

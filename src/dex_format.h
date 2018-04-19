#include<stdint.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
  uint8_t magic[8]; // ubyte
  uint32_t checksum; // uint
  uint8_t signature[20];
  uint32_t file_size;
  uint32_t header_size;
  uint32_t endian_tag;
  uint32_t link_size;
  uint32_t link_off;
  uint32_t map_off;
  uint32_t string_ids_size;
  uint32_t string_ids_off;
  uint32_t type_ids_size;
  uint32_t type_ids_off;
  uint32_t proto_ids_size;
  uint32_t proto_ids_off;
  uint32_t field_ids_size;
  uint32_t field_ids_off;
  uint32_t method_ids_size;
  uint32_t method_ids_off;
  uint32_t class_defs_size;
  uint32_t class_defs_off;
  uint32_t data_size;
  uint32_t data_off;
} header_item;

typedef struct
{
  uint16_t type;
  uint16_t unused;
  uint32_t size;
  uint32_t offset;
} map_item;

typedef struct
{
  uint32_t size;
  map_item * list;
} map_list;

typedef struct
{
  uint32_t string_data_off;
} string_id_item;

typedef struct
{
  uint32_t utf16_size; //uleb128
  uint8_t * data; // MUTF-8
} string_data_item;

void parseHeader(char * base, header_item * hitem);
void header_test(header_item h_item);
void parseMap(char * base, map_list * mlist, uint32_t offset);
void map_list_test(map_list mlist);
void parseStringId(char * base,  string_id_item ** si_item, uint32_t size , uint32_t offset);
void string_id_test(string_id_item * si_item);
void parseStringData(char * base, string_data_item ** sd_item, uint32_t size, string_id_item * si_item);
void string_data_test(string_data_item * sd_item);
uint32_t readUnsignedLeb128( uint8_t** data);
uint32_t readSignedLeb128( uint8_t** data);
uint8_t * writeUnsignedLeb128(uint8_t * dest, uint32_t value);
uint8_t * writeSignedLeb128(uint8_t * dest, int32_t value);

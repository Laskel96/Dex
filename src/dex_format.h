#include<stdint.h>
#include<unistd.h>
#include<fcntl.h>
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
  uint32_t * size;
  map_item * list;
} map_list;

//void dex_parser_header(int fd, header_item ** h_item);
//void dex_parser_map(int fd, map_item ** m_item);

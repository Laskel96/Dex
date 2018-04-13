#include "dex_format.h"

uint32_t DecodeUnsignedLeb128(const uint8_t** data)
{
  const uint8_t* ptr = *data;
  int result = *(ptr++);
  if( result > 0x7f)
  {
    int cur = *(ptr++);
    result = (result & 0x7f) | ((cur & 0x7f) << 7);
    if (cur > 0x7f) {
      cur = *(ptr++);
      result |= (cur & 0x7f) << 14;
      if (cur > 0x7f) {
        cur = *(ptr++);
        result |= (cur & 0x7f) << 21;
        if (cur > 0x7f) {
          /*
           * Note: We don't check to see if cur is out of
           * range here, meaning we tolerate garbage in the
           * high four-order bits
           */
            cur = *(ptr++);
            result |= cur << 28;
        }
      }
    }
  }
  *data = ptr;
  return (uint32_t)result;
}

#include "dex_format.h"

uint32_t readUnsignedLeb128(uint8_t** data)
{
  uint8_t* ptr = *data;
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

uint32_t readSignedLeb128(uint8_t** data)
{
  uint8_t * ptr = *data;
  int32_t result = *(ptr++);
  if (result <= 0x7f)
  {
    result = (result << 25) >> 25;
  }
  else
  {
    int cur = *(ptr++);
    result = (result & 0x7f) | ((cur & 0x7f) << 7);
    if (cur <= 0x7f)
    {
      result = (result << 18) >> 18;
    }
    else
    {
      cur = *(ptr++);
      result |= (cur & 0x7f) << 14;
      if (cur <= 0x7f)
      {
        result = (result << 11) >> 11;
      }
      else
      {
        cur = *(ptr++);
        result |= (cur & 0x7f) << 21;
        if (cur <= 0x7f)
        {
          result = (result << 4) >> 4;
        }
        else {
          // Note: We don't check to see if cur is out of range here,
          // meaning we tolerate garbage in the four high-order bits.
          cur = *(ptr++);
          result |= cur << 28;
        }
      }
    }
  }
  *data = ptr;
  return result;
}

uint8_t * writeUnsignedLeb128(uint8_t * dest, uint32_t value)
{
  uint8_t out = value & 0x7f;
  value >>= 7;
  while (value != 0)
  {
  *dest++ = out | 0x80;
  out = value & 0x7f;
  value >>= 7;
  }
  *dest++ = out;
  return dest;
}

uint8_t * writeSignedLeb128(uint8_t * dest, int32_t value)
{
  uint32_t extra_bits = (uint32_t)(value ^ (value >> 31)) >> 6;
  uint8_t out = value & 0x7f;
  while (extra_bits != 0u)
  {
    *dest++ = out | 0x80;
    value >>= 7;
    out = value & 0x7f;
    extra_bits >>= 7;
  }
  *dest++ = out;
  return dest;
}

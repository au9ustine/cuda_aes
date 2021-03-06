#include "utils.h"
#include <assert.h>

void my_cp_print_hexbytes(uint32_t *bytes, size_t bytes_len)
{
  size_t i;
  for(i = 0; i < bytes_len; i++){
    printf("%02x", bytes[i]);
    if(!(i%16))
      printf("\n");
  }
  printf("\n");
}

size_t 
my_str2bytes(uint32_t **dst_ref, const char *src)
{
  uint32_t i, len = strlen(src) >> 1;
  uint32_t *dst = (uint32_t *)*dst_ref;
  dst = (uint32_t *)malloc(len * sizeof(uint32_t));

  for(i = 0; i < len; i++)
    sscanf(src + i*2, "%02X", dst + i);

  for(i = 0; i < len; i++)
    printf("%02X", dst[i]);

  return len;
}

size_t
str2bytearray(void *dst_buf, size_t buf_len, const char src[], size_t src_len)
{
  size_t i = 0;
  uint8_t *dst = (uint8_t *)dst_buf;
  size_t dst_len = buf_len;
  assert(dst_len == (src_len >> 1));

  uint32_t c = 0;
  for(i = 0; i < dst_len; i++) {
    sscanf(src + i*2, "%02x", &c);
    dst[i] = c;
  }

  return dst_len;
}

size_t
str2uintarray(uint32_t dst[], size_t dst_len, const char src[], size_t src_len)
{
  size_t i = 0;
  assert(dst_len == (src_len >> 1));

  uint32_t c = 0;
  for(i = 0; i < dst_len; i++) {
    sscanf(src + i*2, "%02x", &c);
    dst[i] = c;
  }

  return dst_len;
}

void 
my_print_hexbytes(void *bytes, size_t bytes_len)
{
  size_t i = 0;
  uint32_t *int_buf_ptr = (uint32_t *)bytes;
  for(i = 0; i < bytes_len; i++)
    printf("%02x", int_buf_ptr[i]);
  printf("\n");
}

void
print_helloworld()
{
  printf("Hello, World\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid(char *bits) {
  int result = 1;
  size_t len = strlen(bits);
  if (len == 35) {
    for (size_t i = 0; i < len; i++) {
      if (i == 8 || i == 17 || i == 26) {
        if (bits[i] != '.') {
          result = 0;
          break;
        }
      } else if (bits[i] != '0' && bits[i] != '1') {
        result = 0;
        break;
      }
    }
  } else
    result = 0;
  return result;
}

int convert_to_int(const char *bits) {
  int result = 0;
  for (int i = 0; i < 8; i++) {
    result = (result << 1) | (bits[i] == '1' ? 1 : 0);
  }
  return result;
}

void get_ip(int *ip, char *bits) {
  for (int i = 0; i < 4; i++) {
    ip[i] = convert_to_int(bits);
    bits += 9;
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2 && strlen(argv[1]) == 35) {
    char *bits = argv[1];
    if (is_valid(bits)) {
      int ip[4] = {0};
      get_ip(ip, bits);
      printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    } else {
      printf("Invalid binary data provided.\n");
    }
  } else {
    printf(
        "Please provide binary ip address in the following "
        "format:\n\t00000000.00000000.00000000.00000000\n");
  }
  return 0;
}
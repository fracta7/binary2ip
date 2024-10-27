#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid(char *bits) {
  int result = 1;
  size_t len = strlen(bits);
  for (size_t i = 0; i < len; i++) {
    if (i == 8 || i == 17 || i == 26) {
      if (bits[i] != '.') {
        result = 0;
      }
    } else if (bits[i] != '0' && bits[i] != '1') {
      result = 0;
    }
  }
  return result;
}

int convert_to_int(char *bits) {
  int result = 0;
  for (int i = 0; i < 8; i++) {
    switch (i) {
      case 0:
        if (bits[i] == '1') result += 128;
        break;
      case 1:
        if (bits[i] == '1') result += 64;
        break;
      case 2:
        if (bits[i] == '1') result += 32;
        break;
      case 3:
        if (bits[i] == '1') result += 16;
        break;
      case 4:
        if (bits[i] == '1') result += 8;
        break;
      case 5:
        if (bits[i] == '1') result += 4;
        break;
      case 6:
        if (bits[i] == '1') result += 2;
        break;
      case 7:
        if (bits[i] == '1') result += 1;
        break;
      default:
        break;
    }
  }
  return result;
}

void get_ip(int *ip, char *bits) {
  for (int i = 0; i < 4; i++) {
    ip[i] = convert_to_int(bits);
    for (int j = 0; j <= 8; j++) bits++;
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2 && strlen(argv[1]) == 35) {
    char *bits = (char *)calloc(36, sizeof(char));
    strncpy(bits, argv[1], 36);
    if (is_valid(bits)) {
      int *ip = (int *)calloc(4, sizeof(int));
      get_ip(ip, bits);
      printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
      free(ip);
      ip = NULL;
    } else {
      printf("Invalid binary data provided.\n");
    }
    free(bits);
    bits = NULL;
  } else {
    printf(
        "Please provide binary ip address in the following "
        "format:\n\t00000000.00000000.00000000.00000000\n");
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void __sleep(unsigned int ms);

#if defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
#include <windows.h>

void sleep(unsigned int ms) { Sleep(ms); }
#else
#include <unistd.h>

void __sleep(unsigned int ms) { usleep(ms * 20); }
#endif

void clear_line(int line_num) {
  for (int i = 0; i < line_num; i++) {
    printf("\033[1A");
    printf("\033[0G");
    printf("\033[0K");
  }
}

int main(int argc, char const *argv[]) {
  const char *freaky_string;
  int len;
  if (argc > 1) {
    freaky_string = argv[1];
    len = strlen(freaky_string);
  } else {
    perror("No string has been provided\n");
    return 1;
  }
  int line_num = 1;

  char *anim_string = malloc(len * sizeof(char));
  if (!anim_string) {
    perror("Failed to allocate memory\n");
    return 1;
  }
  memset(anim_string, 0, len);

  int anim_idx = 0;
  while (anim_idx != len) {
    int begin_char_code = 20;
    if (freaky_string[anim_idx] == ' ') {
      anim_string[anim_idx] = ' ';
      anim_idx += 1;
      continue;
    }
    if (freaky_string[anim_idx] == '\n') {
      anim_string[anim_idx] = '\n';
      anim_idx += 1;
      line_num += 1;
      continue;
    }
    while (begin_char_code < (int)freaky_string[anim_idx]) {
      begin_char_code += 1;
      anim_string[anim_idx] = (char)begin_char_code;
      printf("%s\n", anim_string);
      __sleep(1);
      clear_line(line_num);
    }
    anim_idx += 1;
  }
  printf("%s\n", freaky_string);

  return 0;
}

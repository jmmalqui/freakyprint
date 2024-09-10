#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sleep(unsigned int ms);

#if defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__)
    #include <windows.h>

    void sleep(unsigned int ms) {
        Sleep(ms);
    }
#else
    #include <unistd.h>

    void sleep(unsigned int ms) {
        usleep(ms * 1000);
    }
#endif

void clear_line(void)
{
    printf("\033[1A");
    printf("\033[0G");
    printf("\033[2K");
}

int main(int argc, char const* argv[])
{
    const char* freaky_string;
    int len;
    if (argc > 1) {
        freaky_string = argv[1];
        len = strlen(freaky_string);
    }

    char* anim_string = malloc(len * sizeof(char));
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
        while (begin_char_code < (int)freaky_string[anim_idx]) {
            begin_char_code += 1;
            anim_string[anim_idx] = (char)begin_char_code;
            printf("%s\n", anim_string);
            sleep(1);
            clear_line();
        }
        anim_idx += 1;
    }
    printf("%s\n", freaky_string);

    return 0;
}

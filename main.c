#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char buf[1024][100];
    int wc = -1;
    do {
        ++wc;
    } while (fgets(buf[wc], 100, stdin) != NULL);

    char tmp[100];
    for (int i = 0; i < wc - 1; ++i) {
        for (int j = i + 1; j < wc; ++j) {
            if (strncmp(buf[i], buf[j], 100) > 0) {
                strncpy(tmp, buf[i], 100);
                strncpy(buf[i], buf[j], 100);
                strncpy(buf[j], tmp, 100);
            }
        }
    }

    for (int i = 0; i < wc; ++i)
        printf("%s", buf[i]);

    return 0;
}

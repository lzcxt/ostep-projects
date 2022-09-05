#include <stdio.h>
#include <stdlib.h>
char buf[1 << 28];
int main(int argc, char* argv[]) {
    for (int fid = 1; fid < argc; ++fid) {
        FILE* fptr = fopen(argv[fid], "r");
        if (fptr == NULL) {
            printf("wcat: cannot open file\n");
            return 1;
        }
        size_t n = fread(buf, 1, sizeof buf, fptr);
        for (int i = 0; i < n; ++i) putchar(buf[i]);
        fclose(fptr);
    }
    return 0;
}
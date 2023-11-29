// generate sine wave data
#include <stdio.h>
#include <math.h>

int main() {
    int i, k;
    for (i = 0; i < 256; i++) {
        k = 128 + 128 * sin(360.0 * i / 256.0 * 3.1415926 / 180);
        printf("%d:%d;\n", i, k);
    }
    return 0;
}
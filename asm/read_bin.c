#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BASE_PATH "/home/hrock/Documents/asm/bin/"

int main(int argc, char *argv[])
{
    char full_path[512];
    snprintf(full_path, sizeof(full_path), "%s%s", BASE_PATH, argv[1]);

    FILE *file = fopen(full_path, "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    uint8_t buffer[8];   // read 8 bytes at a time
    unsigned long block_index = 0;
    size_t bytes_read;

    printf("<---------anything--------->\n");
    while ((bytes_read = fread(buffer, 1, 8, file)) > 0) {
        printf("Block %lu:\n", block_index);

        // Go over each byte
        for (size_t b = 0; b < bytes_read; b++) {
            // Go over each bit (MSB first)
            for (int bit = 7; bit >= 0; bit--) {
                int value = (buffer[b] >> bit) & 1;
                int bit_index = (b * 8) + (7 - bit); // 0..63 inside the block
                printf("%lu/%2d -> %d\n", block_index*64 + bit_index, bit_index, value);
            }
        }

        block_index++;
    }

    if (block_index == 0)
        printf("<    no entries in file    >\n");

    printf("<-----------end------------>\n");

    fclose(file);
    return 0;
}

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
   
    if (argc != 2) {
        printf("Usage: hexdump <filename>\n");
        return 1;
    }
   
    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Oops, file not found.\n");
        return 1;
    }

    printf("File opened successfully!\n");

    unsigned char buffer[16];
    size_t bytes_read;
    size_t offset = 0;

    while ((bytes_read = fread(buffer, 1, 16, file)) > 0) {
        printf("%08zX ", offset);

        for (size_t i = 0; i < bytes_read; i++) {
            printf("%02X ", buffer[i]);
        }

        for (size_t i = 0; i < bytes_read; i++) {
 
            if(isprint(buffer[i])){
            printf("%c", buffer[i]);
            }

        }

        offset += bytes_read;

        printf("\n");
    }

    fclose(file);

    return 0;
}
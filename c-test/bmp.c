#include <stdio.h>

#define SQUARE_SIZE (24U)

typedef struct {
    struct {
        char signature[2];
        unsigned int file_size;
        unsigned int reserved;
        unsigned int data_offset;
    } __attribute__((packed)) header;
    struct {
        unsigned int dib_size;
        signed int width;
        signed int height;
        unsigned short num_planes;
        unsigned short bpp;
        unsigned int compression;
        unsigned int image_size;
        signed int x_ppm;
        signed int y_ppm;
        unsigned int num_colors;
        unsigned int important_colors;
    } __attribute__((packed)) dib_header;
} __attribute__((packed)) bmp_header;

typedef struct {
} __attribute__((packed)) color_palette;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} __attribute__((packed)) pixel;

typedef struct {
    bmp_header file_header;
    color_palette palette;
    pixel pixel_data[SQUARE_SIZE][SQUARE_SIZE];
} __attribute__((packed)) image;

int main() {
    image o_file;

    o_file.file_header.header.signature[0] = 'B';
    o_file.file_header.header.signature[1] = 'M';
    o_file.file_header.header.file_size = sizeof(o_file);
    o_file.file_header.header.reserved = 0;
    o_file.file_header.header.data_offset = sizeof(o_file.file_header);
    o_file.file_header.dib_header.dib_size = sizeof(o_file.file_header.dib_header);
    o_file.file_header.dib_header.width = SQUARE_SIZE;
    o_file.file_header.dib_header.height = SQUARE_SIZE;
    o_file.file_header.dib_header.num_planes = 1;
    o_file.file_header.dib_header.bpp = sizeof(pixel) * 8;
    o_file.file_header.dib_header.compression = 0;
    o_file.file_header.dib_header.image_size = sizeof(o_file.pixel_data);
    o_file.file_header.dib_header.x_ppm = 0;
    o_file.file_header.dib_header.y_ppm = 0;
    o_file.file_header.dib_header.num_colors = 0;
    o_file.file_header.dib_header.important_colors = 0;

    for (int x = 0; x < SQUARE_SIZE; x++) {
        for (int y = 0; y < SQUARE_SIZE; y++) {
            o_file.pixel_data[x][y].blue = 0;
            o_file.pixel_data[x][y].green = 0;
            o_file.pixel_data[x][y].red = 255;
        }
    }

    FILE *file = fopen("read_square.bmp", "wb");
    fwrite(&o_file, sizeof(o_file), 1, file);
    fclose(file);

    return 0;
}
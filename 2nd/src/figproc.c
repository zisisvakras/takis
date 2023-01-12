/* Use OPTION 1 with flag -DOPTION=1 for bonus(30%) */
#include <stdio.h>
#include <ctype.h>
#define ERROR -1
#ifndef OPTION
#define OPTION 0
#endif

/* A modified getchar() that returns only non-blank characters */
int read(void) {
    int ch = getchar();
    while (isspace(ch)) { /* Keep getting new character until its not blank */
        ch = getchar();
    }
    return ch;
}

/* A modified version of read() that returns the next integer(ascii) */
int readint(void) {
    int ch = read(); /* Get first digit, ignoring blanks */
    int integer = 0;
    while (!isspace(ch)) { /* Stop after you find blank */
        if (!('0' <= ch && ch <= '9')) { /* If character is not a digit throw error */
            return ERROR;
        }
        integer = integer * 10 + ch - '0'; /* Integer builder base 10 */
        ch = getchar();
    }
    return integer;
}

int main(void) {

    /* Reading P at the start */
    if (getchar() != 'P') { /* First character must be P */
        fprintf(stderr, "Couldn't find magic number.\n");
        return ERROR;
    }

    /* Reading the magic number */
    int magicnumber = getchar() - '0';
    if (!OPTION) {
        if (magicnumber < 2 || magicnumber > 6 || magicnumber == 4) { /* Default assignment supports magicnums 6,5,3,2 */
            fprintf(stderr, "Not supported magic number.\n");
            return ERROR;
        }
    }
    if (OPTION) {
        if (magicnumber < 1 || magicnumber > 6) { /* Bonus assignment supports magicnums 6 through 1 */
            fprintf(stderr, "Not supported magic number.\n");
            return ERROR;
        }
    }

    /* Ignoring any comments till image size */
    int ch = read();
    while (ch == '#') { /* Ignore all comment lines */
        while (getchar() != '\n'); /* Dump everything after # */
        ch = getchar();
    }
    ungetc(ch, stdin); /* Throw last character back into stream */

    /* Getting width */
    int width = readint(); /* Getting data in ascii */
    if (width == ERROR) { /* Check readint() to see why this occurs */
        fprintf(stderr, "Couldn't read width.\n");
        return ERROR;
    }

    /* Getting height */
    int height = readint(); /* Getting data in ascii */
    if (height == ERROR) { /* Check readint() to see why this occurs */
        fprintf(stderr, "Couldn't read height.\n");
        return ERROR;
    }

    /* Getting max color */
    int max = magicnumber != 1 && magicnumber != 4 ? readint() : 0; /* P1, P4 don't have max so return 0 */
    if (max == ERROR) { /* Check readint() to see why this occurs */
        fprintf(stderr, "Couldn't read max.\n");
        return ERROR;
    }
    if (max > 255) { /* Can't support more than 255 max */
        fprintf(stderr, "Can't support max higher than 255.\n");
        return ERROR;
    }
    
    /* Convertions */
    if (!OPTION) {
        /* Printing image definitions */
        printf("P%d\n", magicnumber - 1);
        printf("%d %d\n", width, height);
        if (magicnumber != 5 && magicnumber != 2) { /* P4, P1 Don't have max */
            printf("%d\n", max); /* Printing max */
        }

        /* P6 -> P5 */
        if (magicnumber == 6) {
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width ; j++) { /* Loop through all pixels */
                    int red = getchar(); /* Getting data in binary */
                    int green = getchar();
                    int blue = getchar();
                    if (red > max || green > max || blue > max) { /* Colors can't be higher than max */
                        fprintf(stderr, "Pixel %d had bigger value than max.\n", i * j);
                        return ERROR;
                    }
                    putchar((299 * red + 587 * green + 114 * blue) / 1000); /* Luminosity formula */
                }
            }
        }

        /* P5 -> P4 */
        else if (magicnumber == 5) {
            int modulo = width % 8; /* Get how many pixels the last byte will have */
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width - modulo ; j += 8) { /* Do all pixels in current width except last byte */
                    int pixels = 0; /* Start with 00000000 */
                    for (int h = 7 ; h >= 0 ; h--) { /* Looping through 8 pixels to build the byte */
                        int lum = getchar(); /* Getting data in binary */
                        if (lum > max) { /* Colors can't be higher than max */
                            fprintf(stderr, "Pixel %d had bigger value than max.\n", i * j + 7 - h);
                            return ERROR;
                        }
                        if (lum <= ((max + 1) / 2)) { /* Check if pixel is black */
                            pixels |= 1 << h; /* Throw 1 to the appropriate position */
                        }
                    }  
                    putchar(pixels); /* Print data in binary */
                }
                if (modulo) { /* Last byte */
                    int pixels = 0; /* Start with 00000000 */
                    for (int j = 7 ; j > 7 - modulo ; j--) { /* Do last few pixels */
                        int lum = getchar(); /* Getting data in binary */
                        if (lum > max) { /* Colors can't be higher than max */
                            fprintf(stderr, "Pixel %d had bigger value than max.\n", i * width + 7 - j);
                            return ERROR;
                        }
                        if (lum <= ((max + 1) / 2)) { /* Check if pixel is black */
                            pixels |= 1 << j; /* Throw 1 to the appropriate position */
                        }
                    }
                    for (int j = 7 - modulo ; j >= 0 ; j--) { /* Last bits left on the byte */
                        pixels |= 1 << j; /* Throw 1 to the appropriate position */
                    }  
                    putchar(pixels); /* Print data in binary */
                }
            }
        }

        /* P3 -> P2 */
        else if (magicnumber == 3) {
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width ; j++) { /* Loop through all pixels */
                    int red = readint(); /* Getting data in ascii */
                    int green = readint();
                    int blue = readint();
                    if (red == ERROR || green == ERROR || blue == ERROR) { /* Check readint() to see why this occurs */
                        fprintf(stderr, "Couldn't read pixel %d.\n", i * j);
                        return ERROR;
                    }
                    if (red > max || green > max || blue > max) { /* Colors can't be higher than max */
                        fprintf(stderr, "Pixel %d had bigger value than max.\n", i * j);
                        return ERROR;
                    }
                    /* Luminosity formula, Print data in ascii with 3d so its nicely ordered */
                    printf("%3d ", (299 * red + 587 * green + 114 * blue) / 1000);
                }
                printf("\n"); /* Printing new line at the end of width */
            }
        }

        /* P2 -> P1 */
        else if (magicnumber == 2) {
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width ; j++) { /* Loop through all pixels */
                    int pixel = 0; /* Assume pixel is white */
                    int lum = readint(); /* Getting data in ascii */
                    if (lum == ERROR) { /* Check readint() to see why this occurs */
                        fprintf(stderr, "Couldn't read pixel %d.\n", i * j);
                        return ERROR;
                    }
                    if (lum > max) { /* Colors can't be higher than max */
                        fprintf(stderr, "Pixel %d had bigger value than max.\n", i * j);
                        return ERROR;
                    }
                    if (lum <= ((max + 1) / 2)) { /* Check if pixel is black */
                        pixel = 1; /* Switch pixel to black */
                    }
                    printf("%d ", pixel); /* Print data in ascii */
                }   
                printf("\n"); /* Printing new line at the end of width */
            }
        }
    }

    if (OPTION) {
        /* P6 -> P3 */
        if (magicnumber == 6) {
            /* Printing image definitions */
            printf("P3\n");
            printf("%d %d\n", width, height);
            printf("%d\n", max);
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width * 3 ; j++) { /* Loop through all pixels, *3 because we have 3 colors */
                    int num = getchar(); /* Getting data in binary */
                    if (num > max) { /* Colors can't be higher than max */
                        /* (i * j / 3 + j % 3) is needed because we are reading colors not pixels */
                        fprintf(stderr, "Pixel %d had bigger value than max.\n", (i * j / 3) + j % 3);
                        return ERROR;
                    }
                    printf("%3d ", num); /* Print data in ascii with 3d so its nicely ordered */
                }
                printf("\n"); /* Printing new line at the end of width */
            }
        }
        
        /* P3 -> P6 */
        else if (magicnumber == 3) {
            /* Printing image definitions */
            printf("P6\n");
            printf("%d %d\n", width, height);
            printf("%d\n", max);
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width * 3 ; j++) { /* Loop through all pixels, *3 because we have 3 colors */
                    int num = readint(); /* Getting data in ascii */
                    if (num == ERROR) { /* Check readint() to see why this occurs */ 
                        fprintf(stderr, "Couldn't read pixel %d.\n", (i * j / 3) + j % 3); 
                        return ERROR;
                    }
                    if (num > max) { /* Colors can't be higher than max */
                        fprintf(stderr, "Pixel %d had bigger value than max.\n",(i * j / 3) + j % 3);
                        return ERROR;
                    }
                    putchar(num); /* Printing data in binary */
                }
            }
        }

        /* P5 -> P2 */
        else if (magicnumber == 5) {
            /* Printing image definitions */
            printf("P2\n");
            printf("%d %d\n", width, height);
            printf("%d\n", max);
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width ; j++) { /* Loop through all pixels */
                    int num = getchar(); /* Getting data in binary */
                    if (num > max) { /* Colors can't be higher than max */
                        fprintf(stderr, "Pixel %d had bigger value than max.\n", i * j);
                        return ERROR;
                    }
                    printf("%3d ", num); /* Print data in ascii with 3d so its nicely ordered */
                }
                printf("\n"); /* Printing new line at the end of width */
            }
        }

        /* P2 -> P5 */
        else if (magicnumber == 2) {
            /* Printing image definitions */
            printf("P5\n");
            printf("%d %d\n", width, height);
            printf("%d\n", max);
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width ; j++) { /* Loop through all pixels */
                    int num = readint(); /* Getting data in ascii */
                    if (num == ERROR) { /* Check readint() to see why this occurs */ 
                        fprintf(stderr, "Couldn't read pixel %d.\n", i * j);
                        return ERROR;
                    }
                    if (num > max) { /* Colors can't be higher than max */
                        fprintf(stderr, "Pixel %d had bigger value than max.\n", i * j);
                        return ERROR;
                    }
                    putchar(num); /* Printing data in binary */
                }
            }
        }

        /* P4 -> P1 */
        else if (magicnumber == 4) {
            /* Printing image definitions */
            printf("P1\n");
            printf("%d %d\n", width, height);
            int modulo = width % 8; /* Get how many pixels the last byte will have */
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width - modulo ; j += 8) { /* Do all pixels in current width except last byte */
                    int lum = getchar(); /* Getting data in binary */
                    for (int h = 7 ; h >= 0 ; h--) { /* Looping through 8 pixels to decode the byte */
                        int pixel = 0; /* Assume its white */
                        if ((lum >> h) & 1) { /* Is pixel in 7 - h position black? */
                            pixel = 1; /* Assign it to black */
                        }
                        printf("%d ", pixel); /* Printing pixel in ascii */
                    }
                }
                if (modulo) { /* Last byte */
                    int lum = getchar(); /* Getting data in binary */
                    for (int h = 7 ; h > 7 - modulo ; h--) { /* Looping through last few bits */
                        int pixel = 0; /* Assume its white */
                        if ((lum >> h) & 1) { /* Is pixel in 7 - h position black? */
                            pixel = 1; /* Assign it to black */
                        }
                        printf("%d ", pixel); /* Printing pixel in ascii */
                    }
                }
                printf("\n"); /* Printing new line at the end of width */
            }
        }

        /* P1 -> P4 */
        else if (magicnumber == 1) {
            /* Printing image definitions */
            printf("P4\n");
            printf("%d %d\n", width, height);
            int modulo = width % 8; /* Get how many pixels the last byte will have */
            for (int i = 1 ; i <= height ; i++) {
                for (int j = 1 ; j <= width - modulo ; j += 8) { /* Do all pixels in current width except last byte */
                    int pixels = 0; /* Start with 00000000 */
                    for (int h = 7 ; h >= 0 ; h--) { /* Looping through 8 pixels to build the byte */
                        int lum = readint(); /* Getting data in ascii */
                        if (lum == ERROR) { /* Check readint() to see why this occurs */
                            fprintf(stderr, "Couldn't read pixel %d.\n", i * j + 7 - h);
                            return ERROR;
                        }
                        if (lum > 1) { /* Color can't be higher than 1 */
                            fprintf(stderr, "Pixel %d had bigger value than 1.\n", i * j + 7 - h);
                            return ERROR;
                        }
                        pixels |= lum << h; /* Throw pixel value to the appropriate position in the byte */
                    }
                    putchar(pixels); /* Print pixels in binary */
                }
                if (modulo) { /* Last byte */
                    int pixels = 0; /* Start with 00000000 */
                    for (int h = 7 ; h > 7 - modulo ; h--) { /* Looping through last few pixels */
                        int lum = readint(); /* Getting data in ascii */
                        if (lum == ERROR) { /* Check readint() to see why this occurs */
                            fprintf(stderr, "Couldn't read pixel %d.\n", i * width + 7 - h);
                            return ERROR;
                        }
                        if (lum > 1) { /* Color can't be higher than 1 */
                            fprintf(stderr, "Pixel %d had bigger value than 1.\n", i * width + 7 - h);
                            return ERROR;
                        }
                        pixels |= lum << h; /* Throw pixel value to the appropriate position in the byte */
                    }
                    /* Fill the rest of the byte with 1s*/
                    for (int h = 7 - modulo ; h >= 0 ; h--) {
                        pixels |= 1 << h;
                    }
                    putchar(pixels); /* Print pixels in binary */
                }
            }
        }
    }

    /* If file is ascii we can have spaces at the end so we need read() */
    int end = magicnumber <= 3 && magicnumber >= 1 ? read() : getchar();
    if (end != EOF) { /* After the pixels we expect no more data */
        fprintf(stderr, "Found more data than expected\n");
        return ERROR;
    }
    return 0;
}
/* Random crossword generator */
/* Usage: exec (size) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIVISOR 3

// int main(int argc, char** argv) {
//     srand(time(NULL));
//     if (argc != 2) return 1;
//     int size = atoi(argv[1]);
//     if (size < 1) return 1;
//     char** crossword = malloc(size * sizeof(char*));
//     for (int i = 0 ; i < size ; ++i) {
//         crossword[i] = calloc(size, sizeof(char));
//     }
//     int hashes = size * size / DIVISOR;
//     int mod = hashes;
//     printf("%d\n", size);
//     while (hashes) {
//         for (int i = 0 ; i < size ; ++i) {
//             for (int j = 0 ; j < size ; ++j) {
//                 if (!crossword[i][j] && !(rand() & 0x7F) && hashes) {
//                     crossword[i][j] = 1;
//                     --hashes;
//                 }
//             }
//         }
//     }
//     for (int i = 0 ; i < size ; ++i) {
//         for (int j = 0 ; j < size ; ++j) {
//             fputc(crossword[i][j] ? '#' : ' ', stderr);
//             fputc(crossword[i][j] ? '#' : '-', stderr);
//             fputc(crossword[i][j] ? '#' : ' ', stderr);
//             if (crossword[i][j]) printf("%d %d\n", i + 1, j + 1);
//         }
//         fputc('\n', stderr);
//     }
//     return 0;
// }

//chessboard
int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int size = atoi(argv[1]);
    if (size < 1) return 1;
    char** crossword = malloc(size * sizeof(char*));
    for (int i = 0 ; i < size ; ++i) {
        crossword[i] = calloc(size, sizeof(char));
    }
    for (int i = 0 ; i < size ; ++i) {
        for (int j = 0 ; j < size ; ++j) {
            if ((i + j) % 2) {
                crossword[i][j] = 1;
            }
        }
    }
    printf("%d\n", size);
    for (int i = 0 ; i < size ; ++i) {
        for (int j = 0 ; j < size ; ++j) {
            fputc(crossword[i][j] ? '#' : ' ', stderr);
            fputc(crossword[i][j] ? '#' : '-', stderr);
            fputc(crossword[i][j] ? '#' : ' ', stderr);
            if (crossword[i][j]) printf("%d %d\n", i + 1, j + 1);
        }
        fputc('\n', stderr);
    }
    return 0;
}
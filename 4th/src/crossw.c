#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "extratypes.h"
#include "extrafuns.h"

int main(int argc, char** argv) {

    /* Sanity check section */
    if (sizeof(unsigned long long) * CHAR_BIT < 64) {
        fprintf(stderr, "Buy new pc -_-\n");
        return 1;
    }

    /* Argument error handling */
    if (argc < 2) {
        fprintf(stderr, "Not enough arguments\n");
        return 1;
    }

    /* Initiliazing argument flags to default values */
    char* dictionary_path = "Words.txt";
    char* crossword_path = argv[1];
    int check_mode = 0, draw_mode = 0;

    /* Loop reading arguments */
    for (int i = 2 ; i < argc ; ++i) { /* Skip 1 because its the crossword_path */
        /* Setting the flags as needed */
        if (!strcmp(argv[i], "-dict")) {
            if(argv[++i] == NULL) { /* Argument error handling */
                fprintf(stderr, "Could not find dictionary\n");
                return 1;
            }
            dictionary_path = argv[i];
        }
        else if (!strcmp(argv[i], "-check")) {
            check_mode = 1;
        }
        else if (!strcmp(argv[i], "-draw")) {
            draw_mode = 1;
        }
        else {
            fprintf(stderr, "Invalid argument \"%s\"\n", argv[i]);
            return 1;
        }
    }

    /* Intialize the crossword grid */
    char** crossword = NULL;
    int max_word_size, crossword_size;
    init_crossword(crossword_path, &crossword, &crossword_size, &max_word_size);

    /* These markers will lessen the work and memory before solve */
    int* lengths_on_grid = calloc(max_word_size, sizeof(int));
    mallerr(lengths_on_grid);
    int* ascii_on_dict = calloc(256, sizeof(int));
    mallerr(ascii_on_dict);

    /* Map the crossword */
    int grid_count = count_words_on_grid(crossword, crossword_size, lengths_on_grid);
    Word** grid_words = map_words_on_grid(crossword, crossword_size, grid_count);

    /* Just in case */
    if (grid_count < 1) {
        fprintf(stderr, "Nice crossword, no need of solving!\n");
        return 1;
    }

    /* Initialize dictionaries */
    int* dict_count = NULL; /* Counts words in each dictionary */
    char* all_of_dict = NULL; /* Points to the memory block that has all of dict */
    Dictionary* bigdict = init_dictionary(dictionary_path, max_word_size, &all_of_dict, &dict_count, lengths_on_grid, ascii_on_dict);

    /* Initialize dict_maps */
    Map*** dict_maps = init_dict_maps(bigdict, max_word_size, dict_count, lengths_on_grid, ascii_on_dict);

    /* Initializing maps for all words */
    for (int i = 0 ; i < grid_count ; ++i) {
        Map* src = dict_maps[grid_words[i]->size - 1][grid_words[i]->size];
        grid_words[i]->map = malloc(sizeof(Map));
        mallerr(grid_words[i]->map);
        grid_words[i]->map->size = src->size;
        grid_words[i]->map->array = malloc(src->size * sizeof(unsigned long long));
        mallerr(grid_words[i]->map->array);
        /* Copying the map with 1s (full domain) */
        memcpy(grid_words[i]->map->array, src->array, src->size * sizeof(unsigned long long));
        sum_bit(grid_words[i]->map);
    }

    /* Making an array of words thats in the proper order for check and print */
    Word** ord_words = malloc(grid_count * sizeof(Word*));
    mallerr(ord_words);
    int ord_i = 0; /* index */
    for (int i = 0 ; i < grid_count ; ++i) {
        if (grid_words[i]->orientation == Horizontal) {
            ord_words[ord_i++] = grid_words[i];
        }
    }
    for (int i = 0 ; i < grid_count ; ++i) {
        if (grid_words[i]->orientation == Vertical) {
            ord_words[ord_i++] = grid_words[i];
        }
    }

    /* Program behavior based on flags */
    if (check_mode) {
        check_crossword(crossword, ord_words, dict_maps, grid_count);
        if (draw_mode) draw_crossword(crossword, crossword_size);
    }
    else {
        solve_crossword(crossword, bigdict, grid_words, grid_count, dict_maps);
        if (draw_mode) draw_crossword(crossword, crossword_size);
        else print_solution(crossword, ord_words, grid_count);
    }

    /* Cleanup */
    free(ord_words);
    free_dictionary(bigdict, max_word_size, all_of_dict);
    free(dict_count);
    free_maps(dict_maps, max_word_size);
    free(lengths_on_grid);
    free(ascii_on_dict);
    free_words(grid_words, grid_count);
    free(*crossword);
    free(crossword);
    return 0;
}
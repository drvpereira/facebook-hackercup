#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 4

char board[BOARD_SIZE][BOARD_SIZE] = {
    { 'S', 'T', 'N', 'G' },
    { 'E', 'I', 'A', 'E' },
    { 'D', 'R', 'L', 'S' },
    { 'S', 'E', 'P', 'O' }
};

int visited_positions[BOARD_SIZE * BOARD_SIZE][2];
int visited_index;

void add_to_visited(int *position) {
    visited_positions[visited_index][0] = position[0];
    visited_positions[visited_index][1] = position[1];
    visited_index++;
}

bool was_visited(int i, int j) {
    for (int k = 0; k < visited_index; k++) {
        if (visited_positions[k][0] == i && visited_positions[k][1] == j) {
            return true;
        }
    }
   
    return false;
}


bool valid_position(int i, int j) {
    return i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && !was_visited(i, j);
}

bool find_letter(int* position, int index, char* word) {
    bool found_letter = board[position[0]][position[1]] == word[index];
   
    if (found_letter) {
        add_to_visited(position);
   
        if (index == strlen(word) - 1) {
            return true;
        }
   
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (valid_position(position[0] + i, position[1] + j) && find_letter((int[2]){ position[0] + i, position[1] + j }, index+1, word)) {
                    return true;
                }
            }
        }
   
    }
   
    return false;
}

bool find_word(char* word) {
   
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            visited_index = 0;
           
            if (find_letter((int[2]){ i, j }, 0, word)) {
                return true;
            }
        }
    }
   
    return false;
}

int main(void) {
    char* words[11] = { "STING", "GEL", "SOLAR", "GAIN", "SET", "PERIL", "REST", "TIRE", "SILO", "PRINT", "PAINT" };
   
    for (int i = 0; i < 11; i++) {
        char* word = words[i];
       
        if (find_word(word)) {
            printf("Word \"%s\" found in positions: \n", word);
            for (int i = 0; i < visited_index; i++) {
                printf("   %c -> (%d,%d)\n", board[visited_positions[i][0]][visited_positions[i][1]], visited_positions[i][0], visited_positions[i][1]);
            }
           
        } else {
            printf("Word \"%s\" not found!", word);
        }
    }
   
    printf("\nDONE!\n");
    return 0;
}
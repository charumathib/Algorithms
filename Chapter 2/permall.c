//
// Created by Charumathi Badrinath on 7/19/18.
//

#include <stdio.h>

int buffer[0];
int counter = 0;

const int SIZE = 3;

void display (int array[]) {
    printf ("Permutation : ");
    for (int i = 0; i <= SIZE; i++) {
        printf ("%i", array[i]);
    }
    counter++;
    puts (" ");
}

void permall (int height) {
    int temp = 0;
    if (height == -1)
        display (buffer);
    else {
        for (int i = 0; i <= height; i++) {
            /*swap*/
            //printf("%i\n", buffer[height]);
            temp = buffer[height];
            buffer[height] = buffer[i];
            buffer[i] = temp;
            /*perm*/
            permall (height - 1);
            /*swap*/
            temp = buffer[height];
            buffer[height] = buffer[i];
            buffer[i] = temp;
        }
    }
}

int main () {
    for (int i = 0; i <= SIZE; i++) {
        buffer[i] = i;
    }
    permall (SIZE);
    printf ("The number of permutations is %i", counter);
}

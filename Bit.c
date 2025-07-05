#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char path[] = "Bit.bin";

int save(int n);

int load(int *n);

int main() {
  int bit = 0;

  while (1) {
    char command[10];
    printf("> ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0';

    if (!strcmp(command, "++")) {
      bit++;
    } else if (!strcmp(command, "--")) {
      bit--;
    } else if (!strcmp(command, "out")) {
      printf("%d\n", bit);
    } else if (!strcmp(command, "reset")) {
      bit = 0;
    } else if (!strcmp(command, "save")) {
      if (save(bit)) {
        return 1;
      }
    } else if (!strcmp(command, "load")) {
      if (load(&bit)) {
        return 1;
      }
    } else if (!strcmp(command, "quit")) {
      printf("Do you want to save (y/n): " );
      fgets(command, sizeof(command), stdin);
      if (!strcmp(command, "y")) {
        save(bit);
      } else if (!strcmp(command, "n")) {
        return 0;
      } else {
        save(bit);
        return 0;
      }
    } else {
      printf("Invalid command. Available commands are: ++, --, out, reset, save, load, quit\n");
    }
  }

  return 0;
}

int save(int n) {
  FILE *f = fopen(path, "wb");
  if (f == NULL) {
    return 1;
  }

  if (fwrite(&n, sizeof(int), 1, f) != 1) {
    fclose(f);
    return 1;
  }

  fclose(f);
  
  return 0;
}

int load(int *n) {
  FILE *f = fopen(path, "rb");
  if (f == NULL) {
    return 1;
  }

  if (fread(n, sizeof(int), 1, f) != 1) {
    fclose(f);
    return 1;
  }

  fclose(f);

  return 0;
}

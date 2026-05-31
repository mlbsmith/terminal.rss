#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 256

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Exactly 2 arguments are required.\n");
    return 1;
  }
  char *file_name = argv[1];

  FILE *file = fopen(file_name, "rb");

  if (file == NULL) {
    fprintf(stderr, "File not found!");
    return 1;
  }

  // figure out the length of the file
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  // allocate the memory
  char buffer[file_size + 1];

  size_t bytes_read = 0;
  // now read the bytes!
  bytes_read = fread(buffer, 1, sizeof buffer - 1, file);
  fclose(file);
  buffer[bytes_read] = '\0';
  // we did this inefficiently but that's ok! learning!
  // now iterate back through the buffer and find the title

  for (size_t i = 0; i < sizeof(buffer); i++) {
    // look for a <
    if (buffer[i] == '<') {
      // once we find a <, see if the next few chars are t i t l e then >
      char tokens[7];
      int j = 0;
      while (j < 6) {
        i++;
        if (i < sizeof(buffer)) {
          tokens[j] = buffer[i];
          j++;
        } else {
          break;
        }
      }
      tokens[j] = '\0';
      if (strcmp(tokens, "title>") == 0) {
        // found the title!
        int n = 0;
        char title[MAX_TITLE_LENGTH];
        while (n < MAX_TITLE_LENGTH - 1) {
          i++;
          if (i < sizeof(buffer)) {
            if (buffer[i] != '<') {
              title[n] = buffer[i];
              n++;
            } else {
              title[n] = '\0';
              printf("%s\n", title);
              return 0;
            }
          } else {
            fprintf(stderr, "title node is unterminated\n");
            return 1;
          }
        }
        // we got there without returning, which means the title is too long
        fprintf(stderr, "title is longer than the 255 char limit\n");
        return 1;
      }
    }
  }

  fprintf(stderr, "No title found :( \n");
  return 1;
}

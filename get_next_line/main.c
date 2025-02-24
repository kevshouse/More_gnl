#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    // Open a file for reading
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Read lines from the file using get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print the line
        free(line);         // Free the allocated memory
    }

    // Close the file descriptor
    close(fd);

    // Test with an invalid file descriptor
    fd = -1;
    line = get_next_line(fd);
    if (line == NULL)
        printf("Invalid file descriptor handled correctly.\n");

    return (0);
}

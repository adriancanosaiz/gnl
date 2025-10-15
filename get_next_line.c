#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *remainder;
    char buffer[BUFFER_SIZE + 1];
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    remainder = read_and_accumulate(fd, remainder, buffer);
    if (!remainder)
        return (NULL);

    line = extract_line(remainder);
    remainder = save_remainder(remainder);

    return (line);
}

char *read_and_accumulate(int fd, char *remainder, char *buffer)
{
    int bytes_read;

    while (!ft_strchr(remainder, '\n') &&
           (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        remainder = ft_strjoin(remainder, buffer);
    }
    if (bytes_read < 0)
        return (NULL);
    return (remainder);
}

char *extract_line(char *remainder)
{
    int i = 0;
    char *line;

    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (remainder[i] == '\n')
        line = ft_substr(remainder, 0, i + 1);
    else
        line = ft_substr(remainder, 0, i);
    return (line);
}

char *save_remainder(char *remainder)
{
    int i = 0;
    char *tmp;
    char *new_rem;

    while (remainder[i] && remainder[i] != '\n')
        i++;
    tmp = remainder;
    if (remainder[i] == '\n')
        new_rem = ft_substr(remainder, i + 1, ft_strlen(remainder) - (i + 1));
    else
        new_rem = NULL;
    free(tmp);
    return (new_rem);
}

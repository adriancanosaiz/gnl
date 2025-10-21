# get_next_line (gnl)

Este repositorio contiene una implementación en C de la función get_next_line, tal como se pide en el proyecto de 42. La función lee una línea desde un descriptor de archivo (fd) y devuelve esa línea como una cadena terminada en '\0'.

## Descripción

- Implementación en C que respeta las restricciones habituales del proyecto (gestión de memoria, retorno correcto en EOF, manejo de BUFFER_SIZE, etc.).
- Función principal: `char *get_next_line(int fd);`
- Maneja varios descriptores de archivo a la vez y devuelve `NULL` cuando no hay más líneas o en caso de error.

## Estructura del repositorio

- get_next_line.c - implementación principal
- get_next_line_utils.c - funciones auxiliares (ft_strlen, ft_strchr, ft_strjoin, ...)
- get_next_line.h - prototipos y defines
- Makefile - reglas para compilar y limpiar
- tests/ - ejemplos y programas de prueba (opcional)

> Si no encuentras alguno de estos archivos, adáptalo según tu versión local.

## Compilación

El repositorio incluye un Makefile con reglas típicas. Para compilar ejecuta:

make

O compilar manualmente (ejemplo):

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c -o gnl_test

Ajusta `BUFFER_SIZE` al valor que quieras probar.

## Uso

Ejemplo mínimo de uso en un `main.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    char *line;

    if (fd < 0) return 1;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

El comportamiento esperado:
- Cada llamada devuelve la siguiente línea completa incluyendo el '\n' si existe.
- Al alcanzar EOF devuelve la última línea (si no termina con '\n') y luego `NULL`.

## Reglas y notas

- Asegúrate de liberar la memoria devuelta por `get_next_line` para evitar fugas.
- `BUFFER_SIZE` puede ser cualquier número entero positivo; se debe compilar con `-D BUFFER_SIZE=<valor>` para probar distintos tamaños.
- Manejo correcto de retornos: `NULL` en caso de error o cuando no hay más líneas.

## Tests

Incluye tus propios programas en `tests/` o crea un `main.c` como el ejemplo para validar la implementación en distintos ficheros y tamaños de buffer.

## Autor

by acano-sa (adriancanosaiz)

---

Este README sigue el estilo de los repositorios ft_printf y libft del mismo usuario: descripción breve, instrucciones de compilación, uso y estructura del proyecto.

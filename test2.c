#include <unistd.h>

int main()
{
    char *str = "123\nsdf";

    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}
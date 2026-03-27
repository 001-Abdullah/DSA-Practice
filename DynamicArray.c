#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *memory = malloc(1 * sizeof(int)), value;
    if (memory == NULL)
    {
        return 1;
    }

    int index = 0, size = 1;
    int *tmp;
    printf("Enter the array: ");
    scanf("%d", &value);
    while (1)
    {
        if (value == -1)
        {
            tmp = malloc(index * sizeof(int));
            if (tmp == NULL)
            {
                free(memory);
                return 1;
            }
            for (int i = 0; i < index; i++)
            {
                tmp[i] = memory[i];
            }
            free(memory);
            memory = tmp;
            break;
        }

        memory[index] = value;
        index++;
        if (index == size)
        {
            tmp = malloc((size *= 2) * sizeof(int));
            if (tmp == NULL)
            {
                free(memory);
                return 1;
            }

            for (int i = 0; i < index; i++)
            {
                tmp[i] = memory[i];
            }
            free(memory);
            memory = tmp;
        }
        scanf("%d", &value);
    }

    for (int i = 0; i < index; i++)
    {
        printf("%d ", *(memory + i));
    }
    free(memory);
    return 0;
}
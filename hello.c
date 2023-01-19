#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char matrix[20][10];
    char *password[] = {"?", "{", "}", ".", ",", "Onur", "Anil", "Alperen"};
    int isfinish = 1;
    int a;
    int prevrnd;

    for(int i = 0; i < 20; i++)
    {
        printf("%d ", i + 1);
        for(int j = 0; j < 10;)
        {
            int rndn1 = rand() % 8;

            if (isfinish == 0)
            {
                for(; a < strlen(password[prevrnd]); a++)
                {
                    printf("%s", password[prevrnd][a]);
                    j++;
                }

                isfinish = 1;
                password[prevrnd] = "";
                continue;
            }
            
            if(strlen(password[rndn1]) > 10 - j)
            {
                int z = 0;

                for(; z < 10 - j; z++)
                {
                    printf("%s", password[rndn1][z]);
                }

                j += 10 - j;
                isfinish = 0;
                a = z + 1;
                prevrnd = rndn1;
            }
            else if (password[rndn1] == "")
            {
                printf("%s", password[rand() % 5]);
                j++;
            }
            else
            {
                printf("%s", password[rndn1]);
                j += strlen(password[rndn1]);
                if(strlen(password[rndn1]) > 1)
                {
                    password[rndn1] = "";
                }
            }
        }
        printf("\n");
    }

    return 0;
}
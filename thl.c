#include <stdio.h>
#include <string.h>

void checkword(char s[])
{
    int l = strlen(s);
    // verification du mot vuide
    if (l == 0)
    {
        printf("le mot appartient au langage");
        return;
    }
    else
    {
        l--;
        int i = 0;
        // intialisation à l'état initial 0
        int state = 0;
        while (i <= l)
        {
            // vérification de l'alphabet
            if (s[i] == 'a')
            {
                // traitmenet d'un cas spécial, la transition (q2,a) est refusé
                if (state == 2)
                {
                    printf("le mot appartient pas au langage");
                    return;
                }
                // q(0,a) ==> (q1)
                if (state == 0)
                {
                    state = 1;
                }
                // (q1, a) == (q1)
                else if (state == 1)
                {
                    ;
                }
            }
            else if (s[i] == 'b')
            {
                // q(0,b) ==> (q0)
                if (state == 0)
                {
                    ;
                }
                // (q1, b) ==> (q2)
                else if (state == 1)
                {
                    state = 2;
                }
                // (q2,b ==> (q0))
                else if (state == 2)
                {
                    state = 0;
                }
            }
            // le mot contient des mots n'appartenant pas au langage
            else
            {
                printf("le mot contient des caractères hors de l'alphabet");
                return;
            }
            i = i + 1;
        }
        // le mot a été vérfier sans detecter d'erreur et donc appartient au langage.
        printf("le mot appartient au langage ");
        return;
    }
}
int main()
{
    char a[200];
    printf("le Langage est  : \n");
    printf("L = {w € {a,b}* , tel que w ne contient pas la chaine 'aba '}\n");
    int i = 0;
    while (i == 0)
    {
        printf("si vous voulez insérer un epsilon entrez 0, 1 sinon");
        scanf("%d", &i);
        if (i == 0)
        {
            checkword("");
        }
        else
        {

            printf("Veuillez insérer le mot que vous voulez vérifier : \n");
            scanf("%s", a);
            checkword(a);
        }
        printf("\nvous voulez continuer ? insérer 0, insérer autre chose sinon \n");
        scanf("%d", &i);
    }

    return 0;
}
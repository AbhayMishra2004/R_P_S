// GAME OF ROCK , PAPER and SCISSORS . MADE BY ABHAY MISHRA .

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int genrateRandomNumber(int n);
greater(char player, char computer);

int main()
{
    char name[20];
    char dict[3] = {'R', 'P', 'S'};
    int playerscore = 0, CompScore = 0;
    int temp, n, i;
    char PlayerChoose, CompChoose; /* ISNE DICT AUR TEMP KI HELP SE CHAR CHOOSE KIYA HAI */
    int stone, paper, scissors;

    printf("\nWELCOME TO THE GAME\n");
    printf("\nEnter your name : ");
    gets(name);
    printf("How many times you want to play the game : ");
    scanf("%d", &n);
    printf("\n");

    for (i = 1; i <= n; i++)
    {
        // Take player input .
        printf("Choose 1 for ROCK , 2 for PAPER and 3 for scissors \n");
        printf("%s : ", name);
        scanf("%d", &temp);
        PlayerChoose = dict[temp - 1]; /* JO bhi choose kara vo index 0 se suru ho dict mai pata lagaye ki kya chuna hai user ne */
        printf("%s CHOOSE : %c \n", name, PlayerChoose);

        // GENRATE COMPUTER'S INPUT
        temp = genrateRandomNumber(3) + 1;
        CompChoose = dict[temp - 1];
        printf("COMPUTER CHOOSE : %c\n\n", CompChoose);

        // CONDITION
        if (greater(PlayerChoose, CompChoose) == 1)
        {
            CompScore += 1;
        }
        else if (greater(PlayerChoose, CompChoose) == -1)
        {
            CompScore += 0;
            playerscore += 0;
        }
        else
        {
            playerscore += 1;
        }
    }

    // NOW TIME FOR RESULT .
    printf("\n");
    if (playerscore > CompScore)
    {
        printf("%s score : %d\n", name, playerscore);
        printf("Computer score : %d\n", CompScore);
        printf("Congratulation %s , You Win the game . ", name);
    }
    else if (CompScore > playerscore)
    {
        printf("%s score : %d\n", name, playerscore);
        printf("Computer score : %d\n", CompScore);
        printf("Computer win the game . Better luck next time.");
    }
    else
    {
        printf("%s score : %d\n", name, playerscore);
        printf("Computer score : %d\n", CompScore);
        printf("Game draw !");
    }
    return 0;
}

int genrateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

greater(char player, char computer)
{
    /* AGAR DONO KE SAME HO GAYE TO */
    if (player == computer)
    {
        return -1;
    }
    /* IS CONDITION MAI APNE KO TEENO SE CONNECT KARWANA HAI AIK KO PLAYER KE EQUAL BARTA DIYA AUR USKE ANDAR DONO KI CONDITION SE JOD DIYA */

    else if (player == 'R')
    {
        if (computer == 'P')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else if (player == 'P')
    {
        if (computer == 'S')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else // if (player == 's')
    {
        if (computer == 'R')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
#include <stdio.h>
int x[12][4];
void tishi()
{
    printf("************Bowling Score************\n");
    printf("rule：Generally, 1 point per pin knocked down.\nStrike - Score of 10 (for knocking down all ten pins), plus the total of the next two rolls.\nSpare - Score of 10, plus the total number of pins knocked down on the next roll only\nEach frame displays the cumulative score up to that point for all complete frames. If a frame has a strike or spare, the score for that frame is not displayed until sufficient subsequent rolls have been input\n");
}
void score()
{
    int j;
    for (j = 1; j <= 10; j++)
    {
        if (x[j][0] == 10)
        {
            if (x[j + 1][0] == 10)
                x[j][2] = 20 + x[j + 2][0];
            else
                x[j][2] = 10 + x[j + 1][0] + x[j + 1][1];
        }
        else
        {
            if (x[j][0] + x[j][1] == 10)
                x[j][2] = 10 + x[j + 1][0];
            else
                x[j][2] = x[j][0] + x[j][1];
        }
    }

    x[1][3] = x[1][2];
    for (j = 2; j <= 10; j++)
        x[j][3] = x[j - 1][3] + x[j][2];
}

void out()
{
    int i, j;
    printf("**********See below for Score***********************************\n\n\n");
    printf("   F1   F2   F3   F4   F5   F6   F7   F8   F9   F10   Bonus\n");
    for (i = 0; i <= 3; i++)
        for (j = 1; j <= 11; j++)
        {

            printf("%5d", x[j][i]);
            if (j % 11 == 0)
                printf("\n");
        }
    printf("********************Finished********************************\n");
}
void input()
{
    int i;

    for (i = 1; i <= 9; i++)
    {
        printf("Input throw for frame %d ball 1：\n", i);
        scanf("%d", &x[i][0]);
        if (x[i][0] == 10)
        {
            printf("strike！\n");
            x[i][1] = 0;
        }
        else
        {
            printf("Input throw for frame %d ball 2：\n", i);
            scanf("%d", &x[i][1]);
        }
        score();
        out();
    }
    printf("Input throw for frame 10\n");
    scanf("%d", &x[10][0]);
    if (x[10][0] == 10)
    {
        x[10][1] = 0;
        printf("You are so lucky to be given two balls(Enter to Continue)\n");
        printf("Please enter how many pins you knocked down for the two balls：\n");
        scanf("%d%d", &x[11][0], &x[11][1]);
    }
    else
    {
        printf("Input throw for ball 2：\n");
        scanf("%d", &x[10][1]);
        if (x[10][0] + x[10][1] == 10)
        {
            printf("Only grant you another one time to throw(Enter to Continue)\n");
            printf("Please enter how many pins you knocked down for this ball: \n");
            scanf("%d", &x[11][0]);
        }
        else
        {
            x[11][0] = 0;
            x[11][1] = 0;
        }
    }
    printf("**********Done*********************\n\n\n\n");
    score();
    out();
}

int main()
{
    tishi();
    input();
    return 0;
}
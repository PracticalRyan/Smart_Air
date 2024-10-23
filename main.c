#include <stdio.h>
#include <string.h>
// Functions to set variables
int settemp, mode, smart;
void setAir(choose)
{
    int airoff;

    switch (choose)
    {
    case 1:
        if (mode == 1)
            printf("\nPlease turn on the Airconditioner first.\n");
        else
        {
            printf("Please input your desired temperature: ");
            scanf("%d", &settemp);
            fflush(stdin);
        }
        break;

    case 2:
        printf("Please set the mode for Airconditioner.\n");
        printf("[1]Off \n[2]Eco \n[3]Cool \n");
        scanf("%d", &mode);
        fflush(stdin);
        break;

    case 3:
        printf("Please set the state of SMART airconditioner.\n");
        printf("[1]On \n[2]Off \n");
        scanf("%d", &smart);
        fflush(stdin);
        break;

    case 4:
        return;
    }
}

int people = 0, roomtemp = 0;
void setEnvironment(enset)
{
    switch (enset)
    {
    case 1:
        printf("Please put in the number of people here: ");
        scanf(people);
        break;

    case 2:
        printf("Please put in the room temperature: ");
        scanf(roomtemp);
        break;

    case 3:
        break;
    }
}

// Functions to run simulation

void runSimulation()
{
}

void main()
{
    int like, choose, enset;
    do
    {

        printf("What would you like to do?\n");
        printf("[1] Control Air conditioner \n[2] Set Environment \n[3] Run Simulation & View Dashboard\n");
        scanf("%d", &like);
        fflush(stdin);

        switch (like)
        {
        case 1:
            do
            {
                printf("What do you want to control regarding airconditioner?\n");
                printf("[1]Set temperature \n[2]Set mode \n[3]Set SMART \n[4]Exit\n");
                scanf("%d", &choose);
                fflush(stdin);
                if (choose == 4)
                {
                    break;
                }
                setAir(choose);
            } while (1);
            break;

        case 2:
            printf("What type of environment do you want to change?\n");
            printf("[1]Number of People \n[2]Room Temperature \n[3]Exit\n");
            scanf(enset);
            fflush(stdin);
            setEnvironment(enset);
            break;
        }
    } while (1);
}
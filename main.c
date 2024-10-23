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
        if (airoff == 1)
            printf("\nPlease turn on the Airconditioner first.");
        else
        {
            printf("Please input your desired temperature: ");
            scanf("%d", &settemp);
            fflush(stdin);
        }
        break;

    case 2:
        printf("Please set the mode for Airconditioner.");
        printf("[1]Off \n[2]Eco \n[3]Cool \n");
        scanf("%d", &mode);
        fflush(stdin);
        if (mode == 0)
            airoff = 1;
        else
            airoff = 0;
        break;

    case 3:
        printf("Please set the state of SMART airconditioner.");
        printf("[1]On \n[2]Off \n");
        scanf("%d", &smart);
        fflush(stdin);
        break;

    case 4:
        break;
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
    printf("What would you like to do?\n");
    printf("[1] Control Air conditioner [2] Set Environment [3] Run Simulation & View Dashboard: ");
    scanf("%d", &like);
    fflush(stdin);

    switch (like)
    {
    case 1:
        printf("What do you want to control regarding airconditioner?");
        printf("[1]Set temperature [2]Set mode [3]Set SMART [4]Exit: ");
        scanf("%d", &choose);
        fflush(stdin);
        setAir(choose);
        break;

    case 2:
        printf("What type of environment do you want to change?\n");
        printf("[1]Number of People [2]Room Temperature [3]Exit: ");
        scanf(enset);
        fflush(stdin);
        setEnvironment(enset);
        break;
    }
}
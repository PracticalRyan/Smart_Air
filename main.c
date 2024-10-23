#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
// Functions to set variables
int settemp = 27, mode = 2, smart = 1;
int people = 21, roomtemp = 55;

void setAir(choose)
{
    int airoff;

    switch (choose)
    {
    case 1:
        printf("= Set Temperature =\n");
        if (mode == 1)
            printf("Please turn on the Airconditioner first.\n");
        else
        {
            printf("Please input your desired temperature: ");
            scanf("%d", &settemp);
            fflush(stdin);
        }
        break;

    case 2:
        printf("= Set Mode =\n");
        printf("Please set the mode for Airconditioner.\n");
        printf("[1]Off \n[2]Eco \n[3]Cool \n");
        scanf("%d", &mode);
        fflush(stdin);
        break;

    case 3:
        printf("= Set SMART =\n");
        printf("Please set the state of SMART airconditioner.\n");
        printf("[1]On \n[2]Off \n");
        scanf("%d", &smart);
        fflush(stdin);
        break;

    case 4:
        return;
    }
}

void showDashboard()
{
    char mOff[100] = "🔴 Off 🔴";
    char mEco[100] = "🍃 Eco 🍃";
    char mCool[100] = "❄️ Cool ❄️";
    char emoSmart[100] = "🔴";
    char pp[100] = "🙎";

    int loopCount = 0;

    if (smart == 1)
    {
        strcpy(emoSmart, "🟢");
    }
    else
    {
        strcpy(emoSmart, "🔴");
    }

    char fanFrames[4][10] = {
        "|",
        "/",
        "-",
        "\\"};
    int fanIndex = 0;

    for (int i = 1; i < 4; i++)
    {
        system("cls");

        printf(" ____________________________________________________\n");
        printf("|     Temp       |     Set Temp     |      Mode      |\n");
        printf("|    ________    |     _________    |                |\n");
        if (mode == 1)
        {
            printf("|   |        |   |    |         |   |    %s   |\n", mOff);
        }
        else if (mode == 2)
        {
            printf("|   |        |   |    |         |   |    %s   |\n", mEco);
        }
        else
        {
            printf("|   |        |   |    |         |   |   %s   |\n", mCool);
        }
        printf("|   |   %d   |   |    |   %d    |   |                |\n", roomtemp, settemp);
        printf("|   |________|   |    |_________|   |                |\n");
        printf("|                |                  |                |\n");
        printf("|________________|__________________|________________|\n");
        printf("|                |                  |                |\n");
        printf("|                |                  |                |\n");

        printf("|      fan %s     |      Smart %s    |     %s = %2d    |\n", fanFrames[fanIndex], emoSmart, pp, people);
        printf("|                |                  |                |\n");
        printf("|________________|__________________|________________|\n");
        if (++loopCount == 4)
        {
            loopCount = 0;
        }

        fanIndex = (fanIndex + 1) % 4;

        usleep(500000);
    }
}

void setEnvironment(enset)
{
    switch (enset)
    {
    case 1:
        printf("= Number of People =\n");
        printf("Please put in the number of people here: ");
        scanf("%d", &people);
        break;

    case 2:
        printf("= Room Temperature =\n");
        printf("Please put in the room temperature: ");
        scanf("%d", &roomtemp);
        break;

    case 3:
        return;
    }
}

// Functions to run simulation

void runSimulation()
{
    showDashboard();
    do
    {
        // If not OFF
        if (mode != 1)
        {
            if (smart == 1)
            {
                if (people < 5)
                {
                    // Eco
                    mode = 2;
                }
                else
                {
                    // Cool
                    mode = 3;
                }
            }
            // If ECO mode
            if (mode == 2)
            {
                if (roomtemp > settemp + 2)
                {
                    roomtemp--;
                }
                else
                {
                    break;
                }
            }
            // If COOL mode
            else if (mode == 3)
            {
                if (roomtemp > settemp)
                {
                    roomtemp -= 2;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
        showDashboard();
    } while (1);
    return;
}

void main()
{
    SetConsoleOutputCP(CP_UTF8);

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
                printf("=== Control Air Conditioner ===\n");
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
            do
            {
                printf("=== Set Environment ===\n");
                printf("What type of environment do you want to change?\n");
                printf("[1]Number of People \n[2]Room Temperature \n[3]Exit\n");
                scanf("%d", &enset);
                fflush(stdin);
                if (enset == 3)
                    break;
                setEnvironment(enset);
            } while (1);
            break;
        case 3:
            runSimulation();
            break;
        }

    } while (1);
}
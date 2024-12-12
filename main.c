#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#define RED "\033[1;31m"
#define RESET "\033[0m" // Reset color to default

// Functions to set variables
int settemp = 27, mode = 2, smart = 1;
int people = 21, roomtemp = 43;

FILE *readfile, *writefile;

void readData()
{
    readfile = fopen("data.smart", "r");
    fscanf(readfile, "SetTemp=%d \n", &settemp);
    fscanf(readfile, "Mode=%d \n", &mode);
    fscanf(readfile, "Smart=%d \n", &smart);
    fscanf(readfile, "People=%d \n", &people);
    fscanf(readfile, "RoomTemp=%d \n", &roomtemp);
    fclose(readfile);
}

void saveData()
{
    writefile = fopen("data.smart", "w");
    fprintf(writefile, "SetTemp=%d \n", settemp);
    fprintf(writefile, "Mode=%d \n", mode);
    fprintf(writefile, "Smart=%d \n", smart);
    fprintf(writefile, "People=%d \n", people);
    fprintf(writefile, "RoomTemp=%d \n", roomtemp);
    fclose(writefile);
}

char *getMode(int x)
{
    switch (x)
    {
    case 1:
        return ("Off 🚫");
        break;
    case 2:
        return ("Eco 🍃");
        break;
    case 3:
        return ("Cool ❄️");
        break;
    }
}

void setAir(int choose)
{
    system("cls");
    printf("=== Control Air Conditioner ===\n");
    printf("╔════════════════╦══════════════════╦════════════════╗\n");
    printf("║ 1. 🌡️: %-3d     ║ 2. ⚙️: %-9s   ║ 3. 🤖: %-3s     ║\n", settemp, getMode(mode), (smart == 1) ? "On" : "Off");
    printf("╚════════════════╩══════════════════╩════════════════╝\n");

    switch (choose)
    {
    case 1:
        printf("= Set Temperature =\n");
        if (mode == 1)
        {
            printf("ERROR: Please turn on the Air conditioner first.\n");
            usleep(1000000);
        }
        else
        {

            printf("Please input your desired temperature: ");
            do
            {
                if (settemp < 18 || settemp > 30)
                    printf("Invalid input. [18-30]\n");
                scanf("%d", &settemp);
            } while (settemp < 18 || settemp > 30);
        }
        break;

    case 2:
        printf("= Set Mode =\n");
        printf("Please set the mode for Air conditioner.\n");
        printf("[1]Off \n[2]Eco \n[3]Cool \n");
        do
        {
            if (mode > 3 || mode < 1)
            {
                printf("Invalid input. [1-3]\n");
            }
            scanf("%d", &mode);
        } while (mode > 3 || mode < 1);

        break;

    case 3:
        printf("= Set SMART =\n");
        printf("Please set the state of SMART air conditioner.\n");
        printf("[1]On \n[2]Off \n");
        do
        {
            if (smart > 2 || smart < 1)
            {
                printf("Invalid input. [1-2]\n");
            }
            scanf("%d", &smart);

        } while (smart > 2 || smart < 1);
        break;

    case 4:
        return;
    }
    saveData();
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

        printf("╔════════════════════════════════════════════════════╗\n");
        printf("║           🌡️  Air Conditioner Dashboard            ║\n");
        printf("╠════════════════╦══════════════════╦════════════════╣\n");
        printf("║  Current Temp  ║     Set Temp     ║      Mode      ║\n");
        printf("║   ╔════════╗   ║    ╔════════╗    ║                ║\n");
        if (mode == 1)
        {
            printf("║   ║        ║   ║    ║        ║    ║    %-10s   ║\n", mOff);
        }
        else if (mode == 2)
        {
            printf("║   ║        ║   ║    ║        ║    ║    %-10s   ║\n", mEco);
        }
        else
        {
            printf("║   ║        ║   ║    ║        ║    ║   %-10s   ║\n", mCool);
        }
        printf("║   ║   %-2d   ║   ║    ║   %-2d   ║    ║                ║\n", roomtemp, settemp);
        printf("║   ║        ║   ║    ║        ║    ║                ║\n");
        printf("║   ╚════════╝   ║    ╚════════╝    ║                ║\n");
        printf("║                ║                  ║                ║\n");
        printf("╠════════════════╬══════════════════╬════════════════╣\n");
        printf("║                ║                  ║                ║\n");
        printf("║      Fan %s     ║     SMART %s     ║    %s = %-3d    ║\n", fanFrames[fanIndex], emoSmart, pp, people);
        printf("║                ║                  ║                ║\n");
        printf("╚════════════════╩══════════════════╩════════════════╝\n");
        if (++loopCount == 4)
        {
            loopCount = 0;
        }

        fanIndex = (fanIndex + 1) % 4;

        usleep(500000);
    }
}

void setEnvironment(int enset)
{
    system("cls");
    printf("=== Set Environment ===\n");
    printf("╔══════════════════════════╦═════════════════════════╗\n");
    printf("║ 1. 🧑:%-3d                ║ 2. 🌡️:%-3d               ║\n", people, roomtemp);
    printf("╚══════════════════════════╩═════════════════════════╝\n");

    switch (enset)
    {
    case 1:
        printf("= Number of People =\n");
        printf("Please put in the number of people here [0-20]: ");
        do
        {
            if (people > 20 || people < 0)
            {
                printf("Invalid input. [0-20]\n");
            }
            scanf("%d", &people);
            
        } while (people > 20 || people < 0);
        break;

    case 2:
        do
        {
            if (roomtemp > 50 || roomtemp < 20)
            {
                printf("Invalid input. [20-50]\n");
            }
            printf("= Room Temperature =\n");
            printf("Please put in the room temperature [20-50]: ");
            scanf("%d", &roomtemp);
        } while (roomtemp > 50 || roomtemp < 20);
        break;

    case 3:
        return;
    }
    saveData();
}

void runSimulation()
{
    readData();
    showDashboard();
    int onStart = 1;
    int initialMode = mode;
    do
    {
        // If not OFF and on start
        if (mode == 1 && onStart == 1)
        {
            break;
        }
        onStart = 0;
        // If OFF mode
        if (mode == 1)
        {
            if (settemp > roomtemp)
            {
                roomtemp++;
            }
            else
            {
                mode = initialMode;
                break;
            }
        }
        else if (smart == 1)
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
            else if (roomtemp < settemp + 2)
            {
                mode = 1;
            }
            else
            {
                break;
            }
        }
        // If COOL mode
        else if (mode == 3)
        {
            // Reduce fan speed if nearly at set temp
            if (roomtemp > settemp)
            {
                if (roomtemp <= settemp + 2)
                {
                    roomtemp--;
                }
                else
                {
                    roomtemp -= 2;
                }
            }
            else if (roomtemp < settemp)
            {
                mode = 1;
                continue;
            }
            else
            {
                break;
            }
        }
        saveData();
        showDashboard();
    } while (1);
    saveData();
    showDashboard();

    printf("The air conditioner has reached it's set temperature.\nPress any key to continue.");
    char str[20];
    // Remove the newline that fgets will consume
    scanf("%*c");
    fgets(str, sizeof(str), stdin);
    return;
}

void main()
{
    readData();
    SetConsoleOutputCP(CP_UTF8);
    int like, choose, enset, exit = 0;
    do
    {
        system("cls");
        printf("   _____                      __  ___    _\n");
        printf("  / ___/____ ___  ____ ______/ /_/   |  (_)____\n");
        printf("  \\__ \\/ __ `__ \\/ __ `/ ___/ __/ /| | / / ___/\n");
        printf(" ___/ / / / / / / /_/ / /  / /_/ ___ |/ / /\n");
        printf("/____/_/ /_/ /_/\\__,_/_/   \\__/_/  |_/_/_/\n\n");
        printf("SmartAir | Smart Air, Cool Planet 🌎 \n\n");
        printf("What would you like to do?\n");
        printf("[1] Control Air conditioner \n[2] Set Environment \n[3] Run Simulation & View Dashboard\n%s[4] Exit%s\n", RED, RESET);
        scanf("%d", &like);
        switch (like)
        {
        case 1:
            do
            {
                system("cls");
                printf("=== Control Air Conditioner ===\n");
                printf("╔════════════════╦══════════════════╦════════════════╗\n");
                printf("║ 1. 🌡️: %-3d     ║ 2. ⚙️: %-9s   ║ 3. 🤖: %-3s     ║\n", settemp, getMode(mode), (smart == 1) ? "On" : "Off");
                printf("╚════════════════╩══════════════════╩════════════════╝\n");

                printf("What do you want to control regarding air conditioner?\n");
                printf("[1]Set temperature \n[2]Set mode \n[3]Set SMART \n%s[4]Exit%s\n", RED, RESET);
                scanf("%d", &choose);
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
                system("cls");
                printf("=== Set Environment ===\n");
                printf("╔══════════════════════════╦═════════════════════════╗\n");
                printf("║ 1. 🧑:%-3d                ║ 2. 🌡️:%-3d               ║\n", people, roomtemp);
                printf("╚══════════════════════════╩═════════════════════════╝\n");
                printf("What type of environment do you want to change?\n");
                printf("[1]Number of People \n[2]Room Temperature \n%s[3]Exit%s\n", RED, RESET);
                scanf("%d", &enset);
                if (enset == 3)
                    break;
                setEnvironment(enset);
            } while (1);
            break;
        case 3:
            runSimulation();
            break;
        case 4:
            exit = 1;
            break;
        case 4321:
            settemp = 27, mode = 2, smart = 1, people = 21, roomtemp = 43;
            saveData();
            printf("DEMO MODE SET");
            usleep(300000);
            break;
        }

    } while (!exit);
}
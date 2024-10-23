#include <stdio.h>
// Functions to set variables
int temp,mode,smart;
void setAir()
{
    int choose,airoff;
    printf("What do you want to control regarding airconditioner?");
    printf("[1]Set temperature \n[2]Set mode \n[3]Set SMART \n[4]Exit \n");
    scanf("%d", &choose);
    fflush(stdin);
    switch(choose)
    {
        case 1: if(airoff==1) printf("\nPlease turn on the Airconditioner first.");
                else {
                    printf("Please input your desired temperature: ");
                    scanf("%d",&temp);
                    fflush(stdin);
                    }
        
        case 2: printf("Please set the mode for Airconditioner.")
                printf("[1]Off \n[2]Eco \n[3]Cool \n");
                scanf("%d", &mode);
                fflush(stdin);
                if(mode==1) airoff=1;
                else airoff=0;

        case 3: printf("Please set the state of SMART airconditioner")
    }
}

int people=0,roomtemp=0;
void setEnvironment()
{
    int enset
    printf("What type of environment do you want to change?\n");
    printf("[1]Number of People \n[2]Room Temperature \n[3]Exit \n");
    get(enset);
    switch(enset){
        case 1: printf("Please put in the number of people here: ");
                get(people);
        
        case 2: printf("Please put in the room temperature: ");
                get(roomtemp));

        case 3: break;
    }
}

// Functions to run simulation

void runSimulation()
{
}

void main()
{
    printf("What would you like to do?\n");
    printf("[C] Control Air conditioner [E] Set Environment [R] Run Simulation & View Dashboard");
}
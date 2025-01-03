/*  main.c
 *  Created on: Aug 26, 2022
 *  Author: AbdElRuhman Abdallah
 */
#include<stdio.h>

#define WITH_ENGINE_TEMP_CONTROLLER 1    // preprocessor for condition to run the program

void print_state(void);        // function to printing States of Vehicle
void traffic_light(char);      // function to test the Required color
void room_temperature(int);    // function to test the Required Room temperature
void engine_temperature(int);  // function to test the Required engine temperature

#define True 1
#define ON 1
#define OFF 0

//====================================================================================
int Engine_state=OFF,AC=OFF,Engine_Temp_Cont=OFF;  //global variable for known to all functions
int Vehicle_Speed=0;
int Room_Temp=25,Engine_Temp=110;
int room_temp,engine_temp;
char set_speed;
//=====================================================================================
int main(void){

#if(WITH_ENGINE_TEMP_CONTROLLER==1)     // if condition  is True the program will be  run the program

while(True)
{
	char stateOne,stateTwo;  // this variables to take options form user
	printf("a. Turn on the vehicle engine\n");    //display the options to choose one
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	printf("Whit do you want?\n\n");
	fflush(stdout);
	scanf(" %c",&stateOne);
	if(stateOne=='a'){
		Engine_state=ON;
		while(True){
		printf("a. Turn off the engine\n");           //display the options to choose one
		printf("b. Set the traffic light color.\n");
		printf("c. Set the room temperature \"Temperature Sensor\"\n");
		printf("d. Set the engine temperature \"Engine Temperature Sensor\"\n\n");
		fflush(stdout);
		scanf(" %c",&stateTwo);
		if(stateTwo=='a')       // if 'a' reset the values to default and ask again
		{
			Engine_state=OFF;
			AC=OFF;
			Engine_Temp_Cont=OFF;
			Vehicle_Speed=0;
			Room_Temp=25;
			Engine_Temp=112;
			break;
		}
		else if(stateTwo=='b')  //if 'b'  we will take input from user and traffic_light function will call
		{
			printf("Enter The Required Color:\n");
			fflush(stdout);
			scanf(" %c",&set_speed);
			traffic_light(set_speed);

		}
		else if(stateTwo=='c') //if 'c'  we will take input from user and room_temperature function will call
		{
			printf("Enter The Required Room Temperature:\n");
			fflush(stdout);
			scanf(" %d",&room_temp);
			room_temperature(room_temp );
		}
		else if(stateTwo=='d') //if 'c'  we will take input from user and engine_temperature function will call
		{
			printf("Enter The Required Engine Temperature:\n");
			fflush(stdout);
			scanf(" %d",&engine_temp);
			engine_temperature(engine_temp);
		}
		else printf("Invalid option,Tray Again\n\n"); //for anther option ,user tray again
	}

	}
	else if(stateOne=='b')  // if 'b'  the vehicle Turn off the vehicle engine
	{
		printf("Turn off the vehicle engine\n\n");
		continue;
	}
	else if(stateOne=='c') // if 'c' we will Quit the system
	{
		printf("Quit the system\n\n");
		break;
	}
	else  //for anther option ,user tray again
		printf("Invalid option,Tray Again\n\n");

}
#endif   // end of preprocessor function

	return 0;
}

//=========================================================================

void print_state()
{
	if(set_speed=='O' ||set_speed=='o')  // this condition if the user enter 'O' option
	{                                    // the system will set this values  for variable even there are values of this variables
		AC=ON;
		Engine_Temp_Cont=ON;
		Room_Temp=(Room_Temp*((float)5/4)+1);
		Engine_Temp=(Engine_Temp*((float)5/4)+1);
	}

	if(Engine_state==1)
		printf("Engine state: ON\n");
	else
		printf("Engine state: OFF\n");

	if(AC==1)
		printf("AC: ON\n");
	else
		printf("AC: OFF\n");

	printf("Vehicle Speed: %d km/h\n",Vehicle_Speed);
	printf("Room Temperature: %d C\n",Room_Temp);

	if(Engine_Temp_Cont==1)
		printf("Engine Temperature Controller State: ON\n");
	else
		printf("Engine Temperature Controller State: OFF\n");

	printf("Engine Temperature: %d C\n\n",Engine_Temp);
}
//==================================================================

void traffic_light(char set_speed)
{

	if(set_speed=='G' || set_speed=='g')
	{
		Vehicle_Speed=100;
         print_state();
	}
	else if(set_speed=='O' ||set_speed=='o')
	{
		Vehicle_Speed=30;
         print_state();
	}
	else if(set_speed=='R' ||set_speed=='r')
	{
		Vehicle_Speed=0;
         print_state();
	}
	else printf("Invalid\n\n");

}
//======================================================================

void room_temperature(int room_temp )
{
	if(room_temp<10 || room_temp>30)
	{
		AC=ON;
		Room_Temp=20;
		print_state();
	}
	else
	{
		AC=OFF;
		Room_Temp=room_temp;
    	print_state();
	}

}
//=========================================================================

void engine_temperature(int engine_temp)
{
	if(engine_temp<100 || engine_temp>150)
	{
		Engine_Temp_Cont=ON;
		Engine_Temp=125;
		print_state();

	}
	else
	{
		Engine_Temp_Cont=OFF;
		Engine_Temp=engine_temp;
		print_state();
	}

}




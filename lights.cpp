//CS325
//Group Assignment: 4
//11/30/2017
//David Jansen, Eytan Brodsky, Pierre-Louis Sixdenier
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "cnf2sat.hpp"

using namespace std;

typedef struct _light
{
int state;
vector <int> Switches;
}Light;


int main()
{
	//These char *'s are how I am grabbing information from the input.txt file.
	char getter[10000];
	char Switches[1000];
	char Lights[1000];
	
	//Open the file
	FILE* fp;
	fp = fopen("input.txt", "rb");
	int lin = 0;

	//Here I am just grabbing the first line so I can get the number of switches and lights for use throughout this code. 
	fgets(getter, 1000, fp);

	char pch[1000];

	strcpy(Switches, strtok(getter, ","));
	strcpy(Lights, strtok(NULL, "\n"));
	
	int Switch_num = atoi(Switches);
	int Light_num = atoi(Lights);

	cout << "Lights: " << Light_num << " Switches: " << Switch_num << endl;

//This is the 2d array for the switches 
	int Switch_arr[Switch_num-1][20];

//I had to make this grab huge for the 3rd test or it seg faults
	fgets(getter, 100000, fp);

//Array to hold light on and off values
	int light_arr[Light_num];

//Do this so you can run the NULL value in the next for loop for strtok, don't ask me why it needs this but it works lol.
	strcpy(pch, strtok(getter, ","));
	light_arr[0] = atoi(pch);

//Here I am filling the light array up with the on and off values of each light
	for(int i =1; i<Light_num; i++)
	{
		strcpy(pch, strtok(NULL, ","));
		light_arr[i] = atoi(pch);
	}

//Here I am setting each number in the first column to the switch number
	for(int i = 0; i<Switch_num; i++)
	{
		Switch_arr[0][i] = i+1;
	}

	//Here is where I am filling out the 2d array of switches and all of the connections for each switch.
	for(int j = 0; j<Switch_num; j++)
	{
		int i = 0;
		fgets(getter, 1000, fp);
		char *tok =	strcpy(pch, strtok(getter, ","));
		Switch_arr[j][i] = atoi(pch);
		i++;
		while(tok != NULL)
		{
			strcpy(pch, tok);
			tok = strtok(NULL, ",");
			Switch_arr[j][i] = atoi(pch);
			i++;
			if(tok == NULL)
			{
			Switch_arr[j][i] = -1;
			}
		}

	}

//Use this to print the 2d array that holds each switch and its connections.

/*for(int j = 0; j <Switch_num; j++)
{
	int i = 0;
	while(Switch_arr[j][i] != -1)
	{
		cout << Switch_arr[j][i] << " ";
		i++;
	}
	cout << endl;
}
*/



	
	
//Allocating memory for the lights
Light* new_L = new Light[Light_num];

int L;

//Add the connected switches to each of the lights	
for(int j = 0; j < Switch_num; j++)
{
	int l = 1;
	while(Switch_arr[j][l] != -1)
	{
	L = Switch_arr[j][l];
	new_L[L-1].Switches.push_back(j+1);
	l++;
	}
}

//This Vector holds each of the lights
vector<Light> Vec_L;

//Function to give each light its state, it also fills the vector that holds the lights.
for(int p = 0; p < Light_num; p++)
{
	new_L[p].state = light_arr[p];
	Vec_L.push_back(new_L[p]);
}








//Use this to print the vector that hold each lights connections

/*
for(int f = 0; f < Light_num; f++)
{
for(vector<int>::const_iterator i = new_L[f].Switches.begin(); i != new_L[f].Switches.end(); i++)
{
	cout << *i << " ";

}
cout << endl;
}
*/


fclose(fp);


	
return 0;
}


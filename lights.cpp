#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "cnf2sat.hpp"

using namespace std;

//Reference https://www.programiz.com/dsa/graph-adjacency-list, my code is significantly different from this but I used this for the structure.
//Struct to create a light and hold its current on/off status

struct Lights
{
	int Light;
	int Status;
};

//Struct to create a switch and hold each of the lights it is connected to.
struct Switches
{
	int Switch;
	struct Lights* connect;
};

//Graph to hold the adjacency list of Lights and Switches
struct Graph
{
	int Num_Switches;
	int Num_Lights;
	struct Switches** S_List;
	struct Lights** L_List;
};

//Function to create a light and add its status.
struct Lights* createLight(int L, int Stat)
{
	struct Lights* newLight = (Lights*)malloc(sizeof(struct Lights));
	newLight->Light = L;
	newLight->Status = Stat;
	return newLight;
}

//Function to create a switch
struct Switches* createSwitch(int S)
{
	struct Switches* newSwitch = (Switches*)malloc(sizeof(struct Switches));
	newSwitch->Switch = S;
	newSwitch->connect = NULL;
	return newSwitch;

}


struct Graph* createGraph(int Light, int Switch)
{
	struct Graph* graph = (Graph*)malloc(sizeof(struct Graph));
	graph->Num_Switches = Switch;
	graph->Num_Lights = Light;

	graph->S_List = (Switches**)malloc(Switch * sizeof(struct Switches*));
	graph->L_List = (Lights**)malloc(Light * sizeof(struct Lights*));
	
		for(int i =0; i < Switch; i++)
		{
			graph->S_List[i] = NULL;
		}
		
		for(int i = 0; i < Light; i++)
		{

			graph->L_List[i] = NULL;
		}

	
return graph;
}

void addLight(struct Graph* graph, int L int Stat)
{
	struct Lights* newLight = createLight(L, Stat);
	graph->L_List[L] = newLight;
}



int main()
{

return 0;
}

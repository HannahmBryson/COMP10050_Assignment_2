#include<string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// Struct that hold all players values
typedef struct player
{
	char name[20];
	char type[6];
	int life;
	int smartness;
	int strength;
	int magic;
	int luck;
	int dexterity;
	int stillalive;
}player;
player players[6];
//function header
player elf( player players[], int numplayers);
player human(player players[], int numplayers);
player ogre(player players[], int numplayers);
player wizard(player players[], int numplayers);
void showvalues(player players[], int numplayers);
player attack (player players[], int numplayers, int input);
// Main program
int main(void) 
{
	int input, numplayers, inputtype, game= 1;
	
	// Asks the user to input a set of players (max 6). 
	printf("Please input  number of players 2-6");
	scanf ("%d", &input);
	while (input <2 || input > 6)
	{
   		printf("Input is invaid, Please input  number of players 2-6");
   		scanf ("%d", &input);
	}
   
	// Asks the user to input a name.
	for (numplayers=0;numplayers >= 0 && numplayers < input; ++numplayers)
  	{
		printf("Please input name for player %d", numplayers);
		scanf("%s", &players[numplayers].name);
   	}
	
	//life points are initially set to 100.	
	for (numplayers=0;numplayers >= 0 && numplayers <input; ++numplayers)
	{
		players[numplayers].life= 100;
	}
	 
	// For each player the user has to select a type (Elf, Human, Ogre, Wizard) 
	for (numplayers=0;numplayers >= 0 && numplayers <input; ++numplayers)
 	{
		printf("Please input choose a chartcter type for player %d :/n 1 Elf/n 2 Human/n 3 Ogre/n 4 Wizard/n ", numplayers);
		scanf ("%d", &inputtype);
		while (inputtype <1 || inputtype > 4)
		{
			printf("Input is invaid, Please input number of between 1 and 4");
			scanf ("%d", &input);
		}
		// Switch calls functions to randomly assign values and print value
		switch (inputtype)
		{
			case 1:
			elf(players, numplayers);
			showvalues(players,numplayers);
			break;
		
			case 2: 
			human(players, numplayers);
			showvalues(players, numplayers);
			break;
		
			case 3: 
			ogre(players, numplayers);
			showvalues(players,numplayers);
			break;
		
			case 4:
			wizard(players,numplayers);
			showvalues(players, numplayers);
			break;
		}			
	}
	
	// The game continues as long as two players are still alive
  	while ( game != input)
  	{
		for (numplayers=0;numplayers >= 0 && numplayers < input; ++numplayers)
		{

			if (players[numplayers].life >0)
			{
				printf("<%s>(<%s>, <%d>", players[numplayers].name,players[numplayers].type,players[numplayers].life);
				attack(players, numplayers, input);
			}
		
			// Changes the player alive status
			else if (players[numplayers].stillalive ==0)
			{
				printf("player %d is out of the game", numplayers);
				players[numplayers].stillalive = 1;
				++game;
			}
		}
	}
	
	// Prints the winner and losers
  	for (numplayers=0;numplayers >= 0 && numplayers < input; ++numplayers)
	{
		if (players[numplayers].stillalive ==0)
		{
			printf("player %d is the winner", numplayers);
		}
		else
		{
			printf("player %d lost", numplayers);
		}
	}
	return 0;
}
// Randomly assign values Elf
player elf( player players[], int numplayers)
{
	srand(time(NULL));
	strcpy(players[numplayers].type, "Elf");
	players[numplayers].smartness = (rand()%(100-70))+70;
	players[numplayers].strength=(rand()%(50-1))+1;
	players[numplayers].magic =(rand()%(80-51))+51;
	players[numplayers].luck = (rand()%(100-60))+60;
	players[numplayers].dexterity=(rand()%(100-1))+1;
	
	return players[numplayers];
}

// Randomly assign values Human
player human(player players[], int numplayers)
{
	strcpy(players[numplayers].type, "Human");

	while ((players[numplayers].smartness + players[numplayers].strength + players[numplayers].magic+ players[numplayers].luck + players[numplayers].dexterity)== 0 ||(players[numplayers].smartness + players[numplayers].strength + players[numplayers].magic+ players[numplayers].luck + players[numplayers].dexterity)>300)
	{
		srand(time(NULL));
		players[numplayers].smartness =(rand()%(100-1))+1;
		players[numplayers].strength=(rand()%(100-1))+1;
		players[numplayers].magic =(rand()%(100-1))+1;
		players[numplayers].luck=(rand()%(100-1))+1;
		players[numplayers].dexterity=(rand()%(100-1))+1;	
	}
	return players[numplayers];
}

// Randomly assign values Ogre
player ogre(player players[], int numplayers)
{
	srand(time(NULL));
	strcpy(players[numplayers].type, "Ogre");
	players[numplayers].smartness =(rand()%(20-1))+1;
	players[numplayers].strength=(rand()%(100-80))+80;
	players[numplayers].magic = 0;
	players[numplayers].luck=(rand()%(100-1))+1;
	players[numplayers].dexterity=(rand()%(100-80))+80;

	return players[numplayers];
}

// Randomly assign values Wizard
player wizard(player players[], int numplayers)
{
	srand(time(NULL));
	strcpy(players[numplayers].type, "Wizard");
	players[numplayers].smartness =(rand()%(100-90))+90;
	players[numplayers].strength=(rand()%(20-1))+1;
	players[numplayers].magic = (rand()%(100-80))+80;
	players[numplayers].luck=(rand()%(100-50))+50;
	players[numplayers].dexterity=(rand()%(100-1))+1;

	return players[numplayers];
}

// Prints values
void showvalues(player players[], int numplayers)
{
	printf("Player %d %s\n", numplayers, players[numplayers].name);
	printf("Smartness = %d\n",players[numplayers].smartness);
	printf("Strength = %d\n",players[numplayers].strength);
	printf("Magic = %d\n",players[numplayers].magic);
	printf("Luck = %d\n",players[numplayers].luck);
	printf("Dexterity = %d\n",players[numplayers].dexterity);
}

// Attack function
player attack (player players[], int numplayers, int input)
{
	int attacker, attacked;
	attacker=numplayers;
	printf("Select a Player to attack");
	scanf("%d", &attacked);
	if (attacked==attacker)
	{
		printf("You can't attack your self, please select another player");
		scanf("%d", &attacked);
	}
	else if (attacked >= input)
	{
		printf("Input is invalid, Please input another number 1");
		scanf ("%d", &attacked);
	}
	else{
		if (players[attacked].strength <= 70 && players[attacked].life >0 )
			{
				players[attacked].life= players[attacked].life -  (0.5 * players[attacked].strength);
			}
		else
			{
				if(players[attacker].life >0)
				{
					players[attacker].life= players[attacked].life -  (0.3 * players[attacked].strength);
				}
			}
		printf("Player %d  attacks Player %d \n", attacker, attacked);
		printf("Player %d  life points are  now %d \n", attacker, players[attacker].life);
		printf("Player %d  life points are  now %d \n", attacked, players[attacked].life);
		}
		return players[attacker],players[attacked];
}

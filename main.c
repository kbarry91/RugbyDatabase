//kevin barry G00339811 Advanced Procedural Project
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct loginDetails// create login struct
{
	char username[6];
	char password[6];
	struct loginDetails* NEXT;
};

struct node// create struck node
{
	int numIRFU;
	char firstName[10];
	char secondName[10];
	int age;
	float height;
	float weight;
	char club[15];
	char email[25];
	char position;
	char missed;
	char metresRan;
	struct node* NEXT;
};

//Declare Functions
void addnode_atStart(struct node** headptr);
void displayAllPlayers(struct node* headptr);
void deletePlayer_atStart(struct node** headptr);
void deletePlayer_atPosition(struct node* headptr, int pos);
void deletePlayer_atEnd(struct node* headptr);
int searchIRFU(struct node* headptr);
int length(struct node* headptr);
void displayPlayer(struct node* top);
void updatePlayer(struct node* top);
void generateStats(struct node* headptr);
void outputReport(struct node* headptr);
void saveFile(struct node* headptr);
void loadfile(struct node** headptr);
int verifyLogin();

//global Variables declared to allow values to be accesed in menu and for report
float noTackleP = 0;
float l3TackleP = 0;
float l5TackleP = 0;
float m5TackleP = 0;
float noMetreP = 0;
float l10MetreP = 0;
float l20MetreP = 0;
float m20MetreP = 0;

void main()
{
	//loginAuth();
	struct node* head_ptr;
	struct loginDetails* login_head_ptr;
	int option;
	int loginOption = 0;
	int position;
	int result;

	head_ptr = NULL;//initilize head ptr

	//load old database 
	loadfile(&head_ptr);

	//programme header
	printf("Rugby	 Performance	 Metric Ltd.\n");
	printf("===================================.\n");
	//login menu
	printf("Login Menu\n");
	printf("==========\n");
	printf("1. login");
	printf("\n2. exit\n");
	scanf("%d", &loginOption);

	//check for exit
	if (loginOption == 2) {
		loginOption = -1;
		printf("\nYou have chosen to exit the program.");
	}

	while (loginOption != -1) {
		if (loginOption == 1) {
			printf("\nEnter Login details");

			//if (loginCheck(login_head_ptr) == 1) {
			if (verifyLogin() == 1) {
				printf("\nLogin succesfull !\n");

				//main menu
				printf("1. Add a new Player\n");
				printf("2. Display All Players\n");
				printf("3. Display Player Details\n");
				printf("4. Update Players Statistics\n");
				printf("5. Delete Player\n");
				printf("6. Generate Statistics\n");
				printf("7. Print all player Details to a Report file\n");
				printf("Please enter -1 to exit\n");
				scanf("%d", &option);
				if (option == -1)
					printf("You have chosen to exit the program.No changes have been made to database");

				while (option != -1)
				{
					if (option == 1)
						//printf("Adding node to start");
						//addnode_atStart(&head_ptr);
						if (searchIRFU(head_ptr) == 0)
						{
							addnode_atStart(&head_ptr);
						}
						else
						{
							printf("This IRFU number is already in the system.....\n");
						}

					else if (option == 2)
					{
						if (head_ptr == NULL)
						{
							printf("The list is empty\n");
						}
						else
							displayAllPlayers(head_ptr);
					}
					else if (option == 3) {
						displayPlayer(head_ptr);
					}
					else if (option == 4) {
						updatePlayer(head_ptr);
					}
					else if (option == 5) {
						if (head_ptr == NULL)
						{
							printf("The list is already empty\n");
						}
						else {
							result = searchIRFU(head_ptr);
							if (result <= 0)
								printf("This position does not exist\n");
							else if (result == 1)
								deletePlayer_atStart(&head_ptr);
							else if (result <= length(head_ptr))
								deletePlayer_atPosition(head_ptr, result);
							else
								printf("The value that you entered is greater than the lenght of the list\n");
						}

					}// (option ==5)
					else if (option == 6) {
						generateStats(head_ptr);
					}//option 6
					else if (option == 7) {
						printf("Please not in order to Print statistics you must first generate using option 7 ! ");
						outputReport(head_ptr);
					}//option7
					else
						printf("Please enter a valid selection!\n");

					printf("1. Add a new Player\n");
					printf("2. Display All Players\n");
					printf("3. Display Player Details\n");
					printf("4. Update Players Statistics\n");
					printf("5. Delete Player\n");
					printf("6. Generate Statistics\n");
					printf("7. Print all player Details to a Report file\n");
					printf("Please enter -1 to exit\n");
					scanf("%d", &option);
					if (option == -1) {
						saveFile(head_ptr);
						printf("You have chosen to exit the program.The database will now be updated.");
					}//option-1
				}//while(option != -1)
			}//if succesfull login
			else
				printf("\nLogin Unsuccessfull !");
		}// (loginOption == 1
		else if (loginOption == 2) {
			loginOption = -1;
			printf("\nYou have chosen to exit the program.");

		}//(loginOption == 2)
		else
			printf("\nInvalid option !");

		//programme header
		printf("Rugby	 Performance	 Metric Ltd.\n");
		printf("===================================.\n");
		//loginMenu
		printf("Login Menu\n");
		printf("==========\n");
		printf("\n1. login");
		printf("\n2. exit\n");
		scanf("%d", &loginOption);
		if (loginOption == 2) {
			loginOption = -1;
			printf("\nYou have chosen to exit the program.");
		}
	}//(loginOtion)while

	getch();
}//main

void addnode_atStart(struct node** headptr)
{
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please confirm the Players IRFU number :\n");
	scanf("%d", &newNode->numIRFU);
	printf("First Name :\n");
	scanf("%s", newNode->firstName);
	printf("Surname :\n");
	scanf("%s", newNode->secondName);
	printf("Age :\n");
	scanf("%d", &newNode->age);
	printf("Height :\n");
	scanf("%f", &newNode->height);
	printf("Weight :\n");
	scanf("%f", &newNode->weight);
	printf("Club :\n");
	scanf("%s", newNode->club);
	printf("Email  :\n");
	scanf("%s", newNode->email);
	printf("Position  :\n \t a:Prop \n \t b:hooker \n \t c:Second Row \n \t d:BackRow \n \t e:Half Back \n \t f:Centre \n \t g:Winger\n");
	scanf(" %c", &newNode->position);
	printf("Missed  :\n \t a:Never \n \t b:Less than three times per match \n \t c:Less than five times per match \n \t d:More than five times per match\n");
	scanf(" %c", &newNode->missed);
	printf("Metres Made Per Game  :\n \t a:None \n \t b:Less than 10 metres \n \t c:Less than 20 metres \n \t d:More than 20 metres\n");
	scanf(" %c", &newNode->metresRan);
	newNode->NEXT = *headptr;
	*headptr = newNode;
}

void displayAllPlayers(struct node* headptr)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	char position[20];
	char amtMissed[30];
	char amtMetres[30];
	temp = headptr;
	while (temp != NULL)
	{
		//position
		if (temp->position == 'a')
			strcpy(position, "Prop");
		if (temp->position == 'b')
			strcpy(position, "Hooker");
		if (temp->position == 'c')
			strcpy(position, "Second Row");
		if (temp->position == 'd')
			strcpy(position, "Back Row");
		if (temp->position == 'e')
			strcpy(position, "Half Back");
		if (temp->position == 'f')
			strcpy(position, "Centre");
		if (temp->position == 'g')
			strcpy(position, "Wingers/Full Back");
		//missed
		if (temp->missed == 'a')
			strcpy(amtMissed, "Never");
		if (temp->missed == 'b')
			strcpy(amtMissed, "Less than three times per match");
		if (temp->missed == 'c')
			strcpy(amtMissed, "Less than five times per match");
		if (temp->missed == 'd')
			strcpy(amtMissed, "More than five times per match");
		//metres ran
		if (temp->metresRan == 'a')
			strcpy(amtMetres, "None");
		if (temp->metresRan == 'b')
			strcpy(amtMetres, "Less than 10 metres");
		if (temp->metresRan == 'c')
			strcpy(amtMetres, "Less than 20 metres");
		if (temp->metresRan == 'd')
			strcpy(amtMetres, "More than 20 metres");

		printf("IRFU Number    : %d\n", temp->numIRFU);
		printf("First Name     : %s\n", temp->firstName);
		printf("Surname        : %s\n", temp->secondName);
		printf("Age            : %d\n", temp->age);
		printf("Height         : %.2f\n", temp->height);
		printf("Weight         : %.2f\n", temp->weight);
		printf("Club           : %s\n", temp->club);
		printf("Email          : %s\n", temp->email);
		printf("Position       : %s\n", position);
		printf("Missed Tackles : %s\n", amtMissed);
		printf("Metres made    : %s\n", amtMetres);
		printf("  \n");
		temp = temp->NEXT;
	}
}//displayAllPlayers

void deletePlayer_atStart(struct node** headptr)
{
	struct node *temp;

	temp = *headptr;

	*headptr = temp->NEXT;

	free(temp);
}//deletePlayer_atStart

void deletePlayer_atEnd(struct node* headptr)
{
	struct node* temp;
	struct node* old_temp;

	temp = headptr;

	//Loop until the function is at the last node -- also kept track of the node immediately before that
	while (temp->NEXT != NULL)
	{

		old_temp = temp;
		temp = temp->NEXT;
	}

	// Make the node immediately before the last element the new end of the list...
	old_temp->NEXT = NULL;

	// Delete last element
	free(temp);
}//deletePlayer_atEnd

void deletePlayer_atPosition(struct node* headptr, int pos)
{
	struct node* temp;
	struct node* prev_temp;
	int i = 0;

	temp = headptr;

	for (i = 0; i < pos - 1; i++)
	{
		prev_temp = temp;
		temp = temp->NEXT;

	}

	prev_temp->NEXT = temp->NEXT;
	free(temp);

}//deletePlayer_atPosition

int searchIRFU(struct node* headptr)
{
	struct node *temp;
	int i = 0;
	int found = 0;
	int search;

	printf("Please enter Players IRFU number\n");
	scanf("%d", &search);

	temp = headptr;

	while (temp != NULL)
	{
		i++;

		if (search == temp->numIRFU)
			found = i;
		temp = temp->NEXT;
	}

	return found;
}//search|IRFU

int length(struct node* headptr)
{
	int len = 0;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));

	temp = headptr;
	while (temp != NULL)
	{
		len++;
		temp = temp->NEXT;
	}

	return len;
}//length

void displayPlayer(struct node* top) {

	struct node* temp;
	int count = 0;
	int found = 0;
	int searchStyle;
	int searchIrfu = 0;
	char searchName[15];
	char position[20];
	char amtMissed[30];
	char amtMetres[30];
	temp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	//check how user would like to search
	printf("Search by \n \t1.First Name\n \t2.IRFU number\n");
	scanf("%d", &searchStyle);
	switch (searchStyle) {
	case 1:
		printf("\tPlayerName :\n");
		scanf("%s", searchName);
		break;
	case 2:
		printf("\tIRFU number :\n");
		scanf("%d", &searchIrfu);
		break;
	default:
		printf("Invalid option\n");
	}//switch

	while (temp != NULL) {
		//Search for irfu or name
		if (temp->numIRFU == searchIrfu || strcmp(temp->firstName, searchName) == 0) {
			if (temp->position == 'a')
				strcpy(position, "Prop");
			if (temp->position == 'b')
				strcpy(position, "Hooker");
			if (temp->position == 'c')
				strcpy(position, "Second Row");
			if (temp->position == 'd')
				strcpy(position, "Back Row");
			if (temp->position == 'e')
				strcpy(position, "Half Back");
			if (temp->position == 'f')
				strcpy(position, "Centre");
			if (temp->position == 'g')
				strcpy(position, "Wingers/Full Back");
			//missed
			if (temp->missed == 'a')
				strcpy(amtMissed, "Never");
			if (temp->missed == 'b')
				strcpy(amtMissed, "Less than three times per match");
			if (temp->missed == 'c')
				strcpy(amtMissed, "Less than five times per match");
			if (temp->missed == 'd')
				strcpy(amtMissed, "More than five times per match");
			//metres ran
			if (temp->metresRan == 'a')
				strcpy(amtMetres, "None");
			if (temp->metresRan == 'b')
				strcpy(amtMetres, "Less than 10 metres");
			if (temp->metresRan == 'c')
				strcpy(amtMetres, "Less than 20 metres");
			if (temp->metresRan == 'd')
				strcpy(amtMetres, "More than 20 metres");

			printf("IRFU Number    : %d\n", temp->numIRFU);
			printf("First Name     : %s\n", temp->firstName);
			printf("Surname        : %s\n", temp->secondName);
			printf("Age            : %d\n", temp->age);
			printf("Height         : %.2f\n", temp->height);
			printf("Weight         : %.2f\n", temp->weight);
			printf("Club           : %s\n", temp->club);
			printf("Email          : %s\n", temp->email);
			printf("Position       : %s\n", position);
			printf("Missed Tackles : %s\n", amtMissed);
			printf("Metres made    : %s\n", amtMetres);
			found = 1;
			break;
		}
		temp = temp->NEXT;
	}

	if (found == 0) {
		printf("Player is not in system\n");
	}
}//displyPlayer

void updatePlayer(struct node* top) {

	struct node* temp;
	int count = 0;
	int found = 0;
	int searchStyle;
	int searchIrfu = 0;
	char searchName[15];

	temp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	//check how user would like to search
	printf("Search Update by \n \t1.First Name\n \t2.IRFU number\n");
	scanf("%d", &searchStyle);
	switch (searchStyle) {
	case 1:
		printf("\tPlayerName :\n");
		scanf("%s", searchName);
		break;
	case 2:
		printf("\tIRFU number :\n");
		scanf("%d", &searchIrfu);
		break;
	default:
		printf("Invalid option\n");
	}//switch

	while (temp != NULL) {
		//Search for irfu or name
		if (temp->numIRFU == searchIrfu || strcmp(temp->firstName, searchName) == 0) {
			printf("Please confirm the Players IRFU number :\n");
			scanf("%d", &temp->numIRFU);
			printf("First Name :\n");
			scanf("%s", temp->firstName);
			printf("Surname :\n");
			scanf("%s", temp->secondName);
			printf("Age :\n");
			scanf("%d", &temp->age);
			printf("Height :\n");
			scanf("%f", &temp->height);
			printf("Weight :\n");
			scanf("%f", &temp->weight);
			printf("Club :\n");
			scanf("%s", temp->club);
			printf("Email  :\n");
			scanf("%s", temp->email);
			printf("Position  :\n \t a:Prop \n \t b:hooker \n \t c:Second Row \n \t d:BackRow \n \t e:Half Back \n \t f:Centre \n \t g:Winger\n");
			scanf(" %c", &temp->position);
			printf("Missed  :\n \t a:Never \n \t b:Less than three times per match \n \t c:Less than five times per match \n \t d:More than five times per match\n");
			scanf(" %c", &temp->missed);
			printf("Metres Made Per Game  :\n \t a:None \n \t b:Less than 10 metres \n \t c:Less than 20 metres \n \t d:More than 20 metres\n");
			scanf(" %c", &temp->metresRan);
			found = 1;
			break;
		}
		temp = temp->NEXT;
	}

	if (found == 0) {
		printf("Player is not in system\n");
	}
}//displyPlayer

void generateStats(struct node* headptr) {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = headptr;

	char position[20];
	char playPosition;
	float playWeight = 0;
	int searchStyle = 0;
	int playerCounter = 0;

	int noTackle = 0;
	int l3Tackle = 0;
	int l5Tackle = 0;
	int m5Tackle = 0;
	int noMetre = 0;
	int l10Metre = 0;
	int l20Metre = 0;
	int m20Metre = 0;

	//check how user would like to generate stats
	printf("Generate Stats by \n \t1.Position\n \t2.Weight\n");
	scanf("%d", &searchStyle);
	switch (searchStyle) {
	case 1:
		printf("Player Position  :\n \t a:Prop \n \t b:hooker \n \t c:Second Row \n \t d:BackRow \n \t e:Half Back \n \t f:Centre \n \t g:Winger\n");
		scanf(" %c", &playPosition);

		while (temp != NULL)
		{
			if (playPosition == temp->position) {
				playerCounter++;
				//generate tackles
				if (temp->missed == 'a') {
					noTackle++;
					//printf("in missed a tackles");
				}
				if (temp->missed == 'b') {
					l3Tackle++;
				}
				if (temp->missed == 'c') {
					l5Tackle++;
				}
				if (temp->missed == 'd') {
					m5Tackle++;
				}
				//generate meters ran
				if (temp->metresRan == 'a') {
					noMetre++;
				}
				if (temp->metresRan == 'b') {
					l10Metre++;
				}
				if (temp->metresRan == 'c') {
					l20Metre++;
				}
				if (temp->metresRan == 'd') {
					m20Metre++;
				}
			}//if (position=positiom)
			temp = temp->NEXT;
		}//player position while
		break;
	case 2:
		printf("\tMinimum Player weight :\n");
		scanf("%f", &playWeight);

		while (temp != NULL)
		{
			if (temp->weight > playWeight) {//check if players weight is greater than entered weight
				playerCounter++;
				//generate tackles
				if (temp->missed == 'a') {
					noTackle++;
				}
				if (temp->missed == 'b') {
					l3Tackle++;
				}
				if (temp->missed == 'c') {
					l5Tackle++;
				}
				if (temp->missed == 'd') {
					m5Tackle++;
				}
				//generate meters ran
				if (temp->metresRan == 'a') {
					noMetre++;
				}
				if (temp->metresRan == 'b') {
					l10Metre++;
				}
				if (temp->metresRan == 'c') {
					l20Metre++;
				}
				if (temp->metresRan == 'd') {
					m20Metre++;
				}
			}//if
			temp = temp->NEXT;//move to next node
		}
		break;
	default:
		printf("Invalid option\n");
	}//switch

	//generate statistics
	if (playerCounter > 0) {
		noTackleP = (noTackle / playerCounter) * 100;
		l3TackleP = (l3Tackle / playerCounter) * 100;
		l5TackleP = (l5Tackle / playerCounter) * 100;
		m5TackleP = (m5Tackle / playerCounter) * 100;

		noMetreP = (noMetre / playerCounter) * 100;
		l10MetreP = (l10Metre / playerCounter) * 100;
		l20MetreP = (l20Metre / playerCounter) * 100;
		m20MetreP = (m20Metre / playerCounter) * 100;
	}//(playerCounter > 0)

	//output statistics
	switch (searchStyle) {
	case 1:
		if (playPosition == 'a')
			strcpy(position, "Prop");
		if (playPosition == 'b')
			strcpy(position, "Hooker");
		if (playPosition == 'c')
			strcpy(position, "Second Row");
		if (playPosition == 'd')
			strcpy(position, "Back Row");
		if (playPosition == 'e')
			strcpy(position, "Half Back");
		if (playPosition == 'f')
			strcpy(position, "Centre");
		if (playPosition == 'g')
			strcpy(position, "Wingers/Full Back");

		printf("Statistics based on player position %s\n", position);
		break;
	case 2:
		printf("Statistics based on player weight greater than %.2f\n", playWeight);
		break;
	default:
		printf("No search styles selected");
	}//switch searchStyles

	printf("\tPlayers that missed no tackles          %.0f%%\n", noTackleP);
	printf("\tPlayers that missed less than 3 tackles %.0f%%\n", l3TackleP);
	printf("\tPlayers that missed less than 5 tackles %.0f%%\n", l5TackleP);
	printf("\tPlayers that missed more than 5 tackles %.0f%%\n", m5TackleP);
	printf(" \n ");
	printf("\tPlayers that make 0m in a game            %.0f%%\n", noMetreP);
	printf("\tPlayers that make less than 10m in a game %.0f%%\n", l10MetreP);
	printf("\tPlayers that make less than 20m in a game %.0f%%\n", l20MetreP);
	printf("\tPlayers that make more than 20m in a game %.0f%%\n", m20MetreP);

}//generate stats

void outputReport(struct node* headptr) {//method to ouput to file

	FILE* playerDetails;//file pointer

	struct node *temp;//node pointer temp
	temp = (struct node*)malloc(sizeof(struct node));

	temp = headptr;
	char position[20];
	char amtMissed[30];
	char amtMetres[30];

	playerDetails = fopen("playerReport.txt", "w");//open studentsFile.txt

	while (temp != NULL)
	{
		//position
		if (temp->position == 'a')
			strcpy(position, "Prop");
		if (temp->position == 'b')
			strcpy(position, "Hooker");
		if (temp->position == 'c')
			strcpy(position, "Second Row");
		if (temp->position == 'd')
			strcpy(position, "Back Row");
		if (temp->position == 'e')
			strcpy(position, "Half Back");
		if (temp->position == 'f')
			strcpy(position, "Centre");
		if (temp->position == 'g')
			strcpy(position, "Wingers/Full Back");
		// missed
		if (temp->missed == 'a')
			strcpy(amtMissed, "Never");
		if (temp->missed == 'b')
			strcpy(amtMissed, "Less than three times per match");
		if (temp->missed == 'c')
			strcpy(amtMissed, "Less than five times per match");
		if (temp->missed == 'd')
			strcpy(amtMissed, "More than five times per match");
		//metres ran
		if (temp->metresRan == 'a')
			strcpy(amtMetres, "None");
		if (temp->metresRan == 'b')
			strcpy(amtMetres, "Less than 10 metres");
		if (temp->metresRan == 'c')
			strcpy(amtMetres, "Less than 20 metres");
		if (temp->metresRan == 'd')
			strcpy(amtMetres, "More than 20 metres");
		//print players o file
		fprintf(playerDetails, "IRFU Number    : %d\n", temp->numIRFU);
		fprintf(playerDetails, "First Name     : %s\n", temp->firstName);
		fprintf(playerDetails, "Surname        : %s\n", temp->secondName);
		fprintf(playerDetails, "Age            : %d\n", temp->age);
		fprintf(playerDetails, "Height         : %.2f\n", temp->height);
		fprintf(playerDetails, "Weight         : %.2f\n", temp->weight);
		fprintf(playerDetails, "Club           : %s\n", temp->club);
		fprintf(playerDetails, "Email          : %s\n", temp->email);
		fprintf(playerDetails, "Position       : %s\n", position);
		fprintf(playerDetails, "Missed Tackles : %s\n", amtMissed);
		fprintf(playerDetails, "Metres made    : %s\n", amtMetres);
		fprintf(playerDetails, "  \n");
		temp = temp->NEXT;//move to next node
	}
	//print statistics to file
	fprintf(playerDetails, " \n");
	fprintf(playerDetails, "Players that missed no tackles          %.0f%%\n", noTackleP);
	fprintf(playerDetails, "Players that missed less than 3 tackles %.0f%%\n", l3TackleP);
	fprintf(playerDetails, "Players that missed less than 5 tackles %.0f%%\n", l5TackleP);
	fprintf(playerDetails, "Players that missed more than 5 tackles %.0f%%\n", m5TackleP);
	fprintf(playerDetails, " \n");
	fprintf(playerDetails, "Players that make 0m in a game            %.0f%%\n", noMetreP);
	fprintf(playerDetails, "Players that make less than 10m in a game %.0f%%\n", l10MetreP);
	fprintf(playerDetails, "Players that make less than 20m in a game %.0f%%\n", l20MetreP);
	fprintf(playerDetails, "Players that make more than 20m in a game %.0f%%\n", m20MetreP);

	//confirm to screeen
	printf("All Details recorded in playerReport.txt\n");
	fprintf(playerDetails, "  \n");

	fclose(playerDetails);//close file
}//output Report

void saveFile(struct node* headptr) {//method to ouput to file

	FILE* outfile;//file pointer

	struct node *temp;//node pointer temp
	temp = (struct node*)malloc(sizeof(struct node));

	temp = headptr;
	char position[20];

	outfile = fopen("playerDatabase.txt", "w");//open studentsFile.txt

	while (temp != NULL)
	{
		//print players to file
		fprintf(outfile, "%d\n", temp->numIRFU);
		fprintf(outfile, "%s\n", temp->firstName);
		fprintf(outfile, "%s\n", temp->secondName);
		fprintf(outfile, "%d\n", temp->age);
		fprintf(outfile, "%.2f\n", temp->height);
		fprintf(outfile, "%.2f\n", temp->weight);
		fprintf(outfile, "%s\n", temp->club);
		fprintf(outfile, "%s\n", temp->email);
		fprintf(outfile, "%c\n", temp->position);
		fprintf(outfile, "%c\n", temp->missed);
		fprintf(outfile, "%c\n", temp->metresRan);


		temp = temp->NEXT;//move to next node
	}

	fclose(outfile);//close file
}//saveFile

void loadfile(struct node** headptr) {

	//int result;

	FILE* loadDetails;//file pointer
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	loadDetails = fopen("playerDatabase.txt", "r");

	if (loadDetails == NULL) {//check if file is empty
		printf("Database Not found !\n");
		return;
	}// if NUll
	else {
		//while(loadDetails != NULL)
		//while(fscanf(loadDetails, "%d", &temp->numIRFU)==1)
		//while (!feof(loadDetails))//loop while end of file is not reached(give extra node when loaded)
		
		int irfulawd;
		do {
			struct node* temp;
			temp = (struct node*)malloc(sizeof(struct node));

			fscanf(loadDetails, "%d", &temp->numIRFU);
			fscanf(loadDetails, "%s", temp->firstName);
			fscanf(loadDetails, "%s", temp->secondName);
			fscanf(loadDetails, "%d", &temp->age);
			fscanf(loadDetails, "%f", &temp->height);
			fscanf(loadDetails, "%f", &temp->weight);
			fscanf(loadDetails, "%s", temp->club);
			fscanf(loadDetails, "%s", temp->email);
			fscanf(loadDetails, " %c", &temp->position);
			fscanf(loadDetails, " %c", &temp->missed);
			fscanf(loadDetails, " %c", &temp->metresRan);

			temp->NEXT = *headptr;//next node is headptr
			*headptr = temp;//headpointer takes on temp value
		} while (fscanf(loadDetails, "%d", &temp->numIRFU) > 0);

	}//else
	fclose(loadDetails);
}//InputFromFile

int verifyLogin() {
	FILE* filep;//initlize file
	int input;
	struct node* temp;
	int pCounter;
	char passBlocker;

	char loginUser[10];
	char loginPass[10];
	char fileUser[10];
	char filePass[10];

	//enter username and password
	printf("\nEnter username:\n");
	scanf("%s", loginUser);
	printf("Enter password:\n");

	//replace char with *
	for (pCounter = 0; pCounter < 6; pCounter++)//loop through password input
	{
		passBlocker = getch();//get next char
		loginPass[pCounter] = passBlocker;
		passBlocker = '*';
		printf("%c", passBlocker);
	}//for

	loginPass[pCounter] = '\0';//add null terminater
	filep = fopen("loginFile.txt", "r");//open file for read

	if (filep == NULL) {
		printf("Error Login File not found!!\n");
		return 0;
	}
	while (!feof(filep)) {
		input = fscanf(filep, "%s %s", fileUser, filePass);

		if (strcmp(loginUser, fileUser) == 0 && strcmp(loginPass, filePass) == 0) {
			printf("Credentials found ");
			return 1;
		}// if	
		
	}//while
	return 0;
	fclose(filep);
}//verifyLogin
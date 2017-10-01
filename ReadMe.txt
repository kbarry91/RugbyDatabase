Kevin Barry
Advanced Procedural Programming
Main Assignment 
Rugby Program

The main function of this program is to create a database of rugby players and generate statistics.

The the user runs the program you will be greeted with 2 options
	1.Login
	2.Exit
When Login is selected you will be prompted to enter a username and password.These will be confirmed from the loginfile.txt.For security
reasons the password will be shielded with ******.On successfull login the program will load any saved database from before and the user
enters the main menu and will see the following options :
	1. Add a new Player
	2. Display All Players
	3. Display Player Details
	4. Update Players Statistics
	5. Delete Player\n
	6. Generate Statistics\n
	7. Print all player Details to a Report file
		Please enter -1 to exit
1.Add a new Player:		Allows user to enter all details of new player
2.Display All Players:		Displays all players details to screen
3.Display player details:	You will be prompted to enter either a name or IRFU number and the players details if found will be displayed
4.Update player statistics:	Allows user to edit all of selected players details
5.Delete Player:		Deletes player from database
6.Generate statistics:		Calculates and Displays statistics based on chosen criterea
7.Print all player Details to a Report file: outputs all PLayer Details and statistics to playerReport.txt
	-1 to exit :		This returns the user to login menu,once selected the database will be updated to playerDatabase.txt

Improvements I would have liked to make if I had more time
1.Sorting of data by IRFU number
2.Method 8 (listing of players)
3.Increased validation
4.Divide program in to smaller more concise .h files

/*Header Files Inclusion:

The code includes necessary header files such as stdio.h, stdlib.h, and string.h.
Global Variables Initialization:

Global variables are initialized to define system constraints such as maximum number of candidates, maximum length of candidate names and signs, and maximum number of users.
Structure Definitions:

Two structures are defined:
Candidate: Contains fields for candidate name, sign, and number of votes.
User: Contains fields for user username and number of votes given.
Function Prototypes:

Function prototypes for various functionalities such as admin login, user login, adding candidates, voting, viewing total votes, counting total votes, and sorting candidates are declared.
Main Function:

The main function serves as the entry point of the program.
It presents a menu-driven interface for users to choose between admin login, user login, or exit.
Admin Login Function:

The adminLogin function is called when the user selects the admin login option.
It prints a success message, adds candidates, counts total votes, and sorts candidates based on votes.
User Login Function:

The userLogin function is called when the user selects the user login option.
It checks if candidates have been added and prompts the user to enter their username.
If the user exists, it logs them in; otherwise, it creates a new user if the maximum user limit has not been reached.
Add Candidate Function:

The addCandidate function allows the admin to add candidates to the system.
It checks if the maximum candidate limit has been reached and prompts the admin to enter the candidate's name and sign.
Vote Candidate Function:

The voteCandidate function allows users to vote for their preferred candidates.
It displays the list of candidates and prompts the user to enter the number of their chosen candidate.
If the choice is valid, it records the vote and updates the candidate's vote count.
View Total Votes Function:

The viewTotalVotes function displays the total votes given by a specific user.
Count Total Votes Function:

The countTotalVotes function calculates the total number of votes cast for all candidates.
Sort Candidates Function:

The sortCandidates function sorts the candidates based on the number of votes they have received using the bubble sort algorithm.
Alternatively, there is a commented-out implementation of the selection sort algorithm for sorting candidates based on votes.
*/
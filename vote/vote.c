// WRITTEN BY SHUVO SINGH PARTHO (DIU-CSE_64)
// https://github.com/shuvosinghpartho
// Voting System

// Header Files and Global Variables

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxCandidates = 10;
int maxUsers = 10;
int maxNameLength = 50;
int maxSignLength = 20;

int num_candidates = 0;
int num_users = 0;

/*This section includes necessary header files and defines global variables.
maxCandidates, maxUsers, maxNameLength, and maxSignLength define the maximum number of candidates, users, and lengths for name and sign.
num_candidates and num_users keep track of the current number of candidates and users.*/


//Structures 

typedef struct{
    char name[50];
    char sign[20];
    int votes;
} Candidate;

typedef struct {
    char username[50];
    int votes_given;
} User;

/*Defines two structures: Candidate and User.
Candidate contains name, sign, and votes (number of votes received).
User contains username and votes_given (number of votes the user has given).*/


// Function Prototypes

void adminLogin();
void userLogin();
void addCandidate();
void voteCandidate(User *user);
void viewTotalVotes(User user);
void countTotalVotes();
void sortCandidates();

/*These are function prototypes. Each function's purpose will be explained in detail when we get to its implementation.*/

Candidate candidates[10];
User users[10];

// Main Function 

int main() {
    int choice;

    while (1) {
        printf("\n********** Voting System **********\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminLogin();
                break;
            case 2:
                userLogin();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
/*This is the main function where the program starts execution.
It presents a simple menu for admin and user login or exiting the program.
The program runs in an infinite loop until the user chooses to exit.*/

// Admin Login Function

// For simplicity, assume admin login is successful without checking credentials.
// if we want then we can add login section.

void adminLogin() {
    printf("Admin logged in successfully.\n");
    addCandidate();
    countTotalVotes();
    sortCandidates();
}
/*Simulated admin login (without credentials).
Calls functions to add candidates, count total votes, and sort candidates based on votes.*/

// User Login Function

void userLogin() {
    if (num_candidates == 0) {
        printf("No candidates added yet. Please come back later.\n");
        return;
    }

    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);
    // Check if user already exists

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User already exists. Logging in...\n");
            voteCandidate(&users[i]);
            return;
        }
    }
// Create a new user
    if (num_users < maxUsers) {
        strcpy(users[num_users].username, username);
        users[num_users].votes_given = 0;
        printf("User created successfully. Logging in...\n");
        voteCandidate(&users[num_users]);
        num_users++;
    } else {
        printf("Maximum users reached. Cannot create a new user.\n");
    }
}
 /*Allows a user to log in.
Checks if candidates exist, then prompts for username.
If the user exists, allows the user to vote.
If a new user, creates a new entry in the users array if the maximum limit is not reached.*/

// Add Candidate Function

void addCandidate() {
    if (num_candidates >= maxCandidates) {
        printf("Maximum candidates reached. Cannot add more candidates.\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);

    printf("Enter candidate sign: ");
    scanf("%s", candidates[num_candidates].sign);

    candidates[num_candidates].votes = 0;
    num_candidates++;
}
/*Allows the admin to add a candidate.
Checks if the maximum limit of candidates is reached.
Asks for candidate name and sign, then adds the candidate to the candidates array.*/

// Vote Candidate Function 

void voteCandidate(User *user) {
    printf("\nCandidates List:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%s)\n", i + 1, candidates[i].name, candidates[i].sign);
    }

    int choice;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= num_candidates) {
        candidates[choice - 1].votes++;
        user->votes_given++;
        printf("Vote recorded successfully!\n");
    } else {
        printf("Invalid choice. Please select a valid candidate.\n");
    }
}
/*Displays the list of candidates.
Takes user input for the candidate they want to vote for.
Records the vote and increments the candidate's votes count.
Also increments the user's votes_given count.*/

// View Total Votes Function

void viewTotalVotes(User user) {
    printf("Total votes given by user %s: %d\n", user.username, user.votes_given);
}

/*Displays the total votes given by a specific user.*/

// Count Total Votes Function

void countTotalVotes() {
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        total_votes += candidates[i].votes;
    }
    printf("Total votes counted: %d\n", total_votes);
}
/*Calculates and displays the total number of votes received by all candidates.*/

// Sort Candidates Function
// Algorithm Part
// Bubble sort 

void sortCandidates() {
    for (int i = 0; i < num_candidates - 1; i++) {
        for (int j = 0; j < num_candidates - i - 1; j++) {
            if (candidates[j].votes < candidates[j + 1].votes) {
                Candidate temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }

/*// Selection Sort
void sortCandidates() {
    int maxIdx;
        Candidate temp;
            for (int i = 0; i < num_candidates - 1; i++) {
                maxIdx = i;
                    for(int j = i + 1; j < num_candidates; j++) {
                        if (candidates[j].votes > candidates[maxIdx].votes) {
                    maxIdx = j;
                }
            }
        temp = candidates[maxIdx];
    candidates[maxIdx] = candidates[i];
candidates[i] = temp;
}*/

    printf("\nCandidates sorted based on votes:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%s) - Votes: %d\n", i + 1, candidates[i].name, candidates[i].sign, candidates[i].votes);
    }
}
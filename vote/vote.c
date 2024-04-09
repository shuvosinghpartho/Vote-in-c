// WRITTEN BY SHUVO SINGH PARTHO (DIU-CSE_64)
// https://github.com/shuvosinghpartho
// Voting System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxCandidates = 10;
int maxUsers = 10;
int maxNameLength = 50;
int maxSignLength = 20;

int num_candidates = 0;
int num_users = 0;

typedef struct{
    char name[50];
    char sign[20];
    int votes;
} Candidate;

typedef struct {
    char username[50];
    int votes_given;
} User;

void adminLogin();
void userLogin();
void addCandidate();
void voteCandidate(User *user);
void viewTotalVotes(User user);
void countTotalVotes();
void sortCandidates();


Candidate candidates[10];
User users[10];

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

// For simplicity, assume admin login is successful without checking credentials
// if we want then we can add login section bt ata dorkar nei pera hin thak

void adminLogin() {
    printf("Admin logged in successfully.\n");
    addCandidate();
    countTotalVotes();
    sortCandidates();
}

void userLogin() {
    if (num_candidates == 0) {
        printf("No candidates added yet. Please come back later.\n");
        return;
    }

    char username[50];
    printf("Enter your username: ");
    scanf("%s", username);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("User already exists. Logging in...\n");
            voteCandidate(&users[i]);
            return;
        }
    }

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

void viewTotalVotes(User user) {
    printf("Total votes given by user %s: %d\n", user.username, user.votes_given);
}

void countTotalVotes() {
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        total_votes += candidates[i].votes;
    }
    printf("Total votes counted: %d\n", total_votes);
}

// Algorithm Part
// Algorithm chara sort kora possible na maybe. Ei sorting part ta bubble sort algorithm e porse

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

    printf("\nCandidates sorted based on votes:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%s) - Votes: %d\n", i + 1, candidates[i].name, candidates[i].sign, candidates[i].votes);
    }
}

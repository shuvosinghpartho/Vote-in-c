// WRITTEN BY SHUVO SINGH PARTHO (DIU-CSE_64)
// https://github.com/shuvosinghpartho
// Online Voting System


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_candidates 10
#define max_users 100
#define max_name_length 50
#define max_sign_length 50

typedef struct {
    char name[max_name_length];
    char signature[max_sign_length]; // adding sign for each candidate
    int votes;
} Candidate;

typedef struct {
    char username[max_name_length];
    int votedCandidateIndex;
} User;

void adminLogin();
void userLogin();
void addCandidates();
void castVote(User* user);
void viewTotalVotes(User user);
void viewTotalVotesByUser(char username[]);
void countTotalVotes();
void sortCandidates();

Candidate candidates[max_candidates];
User users[max_users];
int numCandidates = 0;
int numUsers = 0;

int main() {
    int choice;
    while (1) {
        printf("\nVoting System Menu\n");
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
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void adminLogin() {
    char password[20];
    printf("Enter admin password: ");
    scanf("%s", password);
    if (strcmp(password, "admin123") == 0) {
        addCandidates();
    } else {
        printf("Incorrect password. Please try again.\n");
    }
}

void userLogin() {
    char username[max_name_length];
    printf("Enter username: ");
    scanf("%s", username);
    strcpy(users[numUsers].username, username);
    castVote(&users[numUsers]);
    numUsers++;
}

void addCandidates() {
    int i, numVotesAllowed;
    printf("Enter number of votes allowed per user: ");
    scanf("%d", &numVotesAllowed);
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);
    printf("Enter candidate details:\n");
    for (i = 0; i < numCandidates; i++) {
        printf("Candidate %d name: ", i+1);
        scanf("%s", candidates[i].name);
        printf("Candidate %d signature: ", i+1); // Adding signature input
        scanf("%s", candidates[i].signature);
        candidates[i].votes = 0;
    }
    printf("Voting setup completed successfully.\n");
}

void castVote(User* user) {
    int i, choice;
    printf("Candidates:\n");
    for (i = 0; i < numCandidates; i++) {
        printf("%d. %s - %s\n", i+1, candidates[i].name, candidates[i].signature);
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= numCandidates) {
        candidates[choice-1].votes++;
        user->votedCandidateIndex = choice-1;
        printf("Vote casted successfully.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

void viewTotalVotes(User user) {
    printf("Total votes casted by user %s: %d\n", user.username, candidates[user.votedCandidateIndex].votes);
}

void viewTotalVotesByUser(char username[]) {
    int totalVotes = 0;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            totalVotes += candidates[users[i].votedCandidateIndex].votes;
        }
    }
    printf("Total votes casted by user %s: %d\n", username, totalVotes);
}

void countTotalVotes() {
    int totalVotes = 0;
    for (int i = 0; i < numCandidates; i++) {
        totalVotes += candidates[i].votes;
    }
    printf("Total votes casted: %d\n", totalVotes);
}
// Algorithm Part
void sortCandidates() {
    // Bubble sort candidates based on their votes
    for (int i = 0; i < numCandidates - 1; i++) {
        for (int j = 0; j < numCandidates - i - 1; j++) {
            if (candidates[j].votes < candidates[j+1].votes) {
                // Swap candidates
                Candidate temp = candidates[j];
                candidates[j] = candidates[j+1];
                candidates[j+1] = temp;
            }
        }
    }
}

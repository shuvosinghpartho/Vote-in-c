/*#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define MaxCandidates 10
#define MaxUser 10
#define MaxNameLength 50
#define MaxSignLength 20

int num_candidates = 0;
int num_users = 0;

typedef struct {
    char name[MaxNameLength];
    char sign[MaxSignLength];
    int votes;
} Candidate;

typedef struct {
    char username[MaxNameLength];
    char password[MaxNameLength]; // Added password field for user
    int votes_given;
} User;

Candidate candidates[MaxCandidates];
User users[MaxUser];

void adminLogin();
void userLogin();
void userSignup();
void addCandidate();
void countTotalVotes();
void totalCandidates();
void sortCandidates();
void voteCandidate(User *user);

int main() {
    int choice;
    while (1) {
        printf("\n********** Voting System **********\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. User Signup\n");
        printf("4. Exit\n");
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
                userSignup();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

void adminLogin() {
    int choice;
    while (1) {
        printf("\n********** Admin Menu **********\n");
        printf("1. Add Candidate\n");
        printf("2. Count Total Votes\n");
        printf("3. Total Candidates\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                countTotalVotes();
                break;
            case 3:
                totalCandidates();
                break;
            case 4:
                return; // Return to main menu
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}

void addCandidate() {
    char choice; // Variable to store the admin's choice for adding more candidates
    do {
        // Check if maximum candidates have been reached
        if (num_candidates >= MaxCandidates) {
            printf("Maximum candidates reached. Cannot add more candidates.\n");
            return; // Exit the function if no more candidates can be added
        }
        // Prompt for candidate name
        printf("Enter candidate name: ");
        scanf("%s", candidates[num_candidates].name);  // Read the candidate's name

        // Prompt for candidate sign
        printf("Enter candidate sign: ");
        scanf("%s", candidates[num_candidates].sign); // Read the candidate's sign

        // Initialize votes to 0 and increment candidate counter
        candidates[num_candidates].votes = 0;
        num_candidates++;

        // Success message
        printf("Candidate added successfully.\n");

        // Ask if more candidates need to be added
        printf("Do you want to add more candidates? (1: yes / 2: no): ");
        scanf(" %c", &choice); // Read the admin's choice (with a leading space to ignore any newline character)
    } while (choice == '1'); // Continue loop if the choice is '1'
}


void countTotalVotes() {
    // Sort candidates based on votes in descending order
    sortCandidates();
    printf("\n********** Total Votes **********\n");

    // Iterate through the sorted list of candidates and print their votes
    for (int i = 0; i < num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}
void totalCandidates() {
    printf("\n********** Total Candidates **********\n");

    // Iterate through the list of candidates and print their names
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Bubble sort
void sortCandidates() {
    // Perform bubble sort on candidates array
    for (int i = 0; i < num_candidates - 1; i++) {
        for (int j = i + 1; j < num_candidates; j++) {
            // If the current candidate has fewer votes than the next candidate, swap them
            if (candidates[i].votes < candidates[j].votes) {
                Candidate temp = candidates[i]; // Temporary storage for swapping
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}

void userLogin() {
    char username[MaxNameLength];
    char password[MaxNameLength];

    // Prompt user for username
    printf("Enter your username: ");
    scanf("%s", username);
    // Prompt user for password
    printf("Enter your password: ");
    scanf("%s", password);

    // Iterate through the list of registered users
    for (int i = 0; i < num_users; i++) {
         // Check if the entered username and password match a registered user
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            // Successful login
            printf("User logged in successfully.\n");
            // Allow the user to vote
            voteCandidate(&users[i]);
            return;
        }
    }
    // Failed login attempt
    printf("Invalid username or password. Please try again.\n");
}

void userSignup() {
    // Check if the maximum number of users has been reached
    if (num_users >= MaxUser) {
        printf("Maximum users reached. Cannot create a new user.\n");
        return;  // Exit the function if no more users can be added
    }
    
     // Prompt for and read the new user's username
    printf("Enter your username: ");
    scanf("%s", users[num_users].username);

    // Prompt for and read the new user's password
    printf("Enter your password: ");
    scanf("%s", users[num_users].password);

    // Initialize the new user's votes given to 0
    users[num_users].votes_given = 0;
    num_users++;

    // Print a success message and prompt the user to log in
    printf("User created successfully. Please login.\n");
}

void voteCandidate(User *user) {
    printf("\n********** Candidates List **********\n");
    // Iterate through the list of candidates and print their details
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%s)\n", i + 1, candidates[i].name, candidates[i].sign);
    }
    // Prompt the user to enter their choice
    int choice;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);

     // Check if the choice is valid (within the range of available candidates)
    if (choice >= 1 && choice <= num_candidates) {
        // Increment the vote count for the chosen candidate
        candidates[choice - 1].votes++;
        // Increment the count of votes given by the user
        user->votes_given++;
        // Print a success message
        printf("Vote recorded successfully!\n");
    } else {
        // Print an error message if the choice is invalid
        printf("Invalid choice. Please select a valid candidate.\n");
    }
}*/







// supti
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxCandidates 10
#define MaxUser 10
#define MaxNameLength 50
#define MaxSignLength 20

int num_candidates = 0;
int num_users = 0;

typedef struct {
    char name[MaxNameLength];
    char sign[MaxSignLength];
    int votes;
} Candidate;

typedef struct {
    char username[MaxNameLength];
    char password[MaxNameLength];
    int votes_given;
} User;

typedef struct {
    int type;  // Use integers to represent types
    char description[MaxNameLength];
} ElectionType;

Candidate candidates[MaxCandidates];
User users[MaxUser];
ElectionType currentElection = {0, "No Election"};

void adminLogin();
void userLogin();
void userSignup();
void addCandidate();
void countTotalVotes();
void setElectionType();
void sortCandidates();
void voteCandidate(User *user);

int main() {
    int choice;
    while (1) {
        printf("\n===== Voting System =====\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. User Signup\n");
        printf("4. Exit\n");
        printf("=========================\n");
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
                userSignup();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}

void adminLogin() {
    char adminUsername[MaxNameLength];
    char adminPassword[MaxNameLength];

    printf("\n===== Admin Login =====\n");
    printf("Enter admin username: ");
    scanf("%s", adminUsername);
    printf("Enter admin password: ");
    scanf("%s", adminPassword);

    if (strcmp(adminUsername, "admin") == 0 && strcmp(adminPassword, "password") == 0) {
        int choice;
        while (1) {
            printf("\n===== Admin Menu =====\n");
            printf("1. Add Candidate\n");
            printf("2. Count Total Votes\n");
            printf("3. Set Election Type\n");
            printf("4. Back to Main Menu\n");
            printf("======================\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    addCandidate();
                    break;
                case 2:
                    countTotalVotes();
                    break;
                case 3:
                    setElectionType();
                    break;
                case 4:
                    return;
                default:
                    printf("Invalid choice. Please enter a valid option.\n");
            }
        }
    } else {
        printf("Invalid admin credentials. Access denied.\n");
    }
}

void addCandidate() {
    char choice;
    do {
        if (num_candidates >= MaxCandidates) {
            printf("Maximum candidates reached. Cannot add more candidates.\n");
            return;
        }

        printf("Enter candidate name: ");
        scanf("%s", candidates[num_candidates].name);

        printf("Enter candidate sign: ");
        scanf("%s", candidates[num_candidates].sign);

        candidates[num_candidates].votes = 0;
        num_candidates++;
        printf("Candidate added successfully.\n");

        printf("Do you want to add more candidates? (1: yes / 2: no): ");
        scanf(" %c", &choice);
    } while (choice == '1');
}
















// Tanu
void countTotalVotes() {
    sortCandidates();
    printf("\n===== Total Votes =====\n");

    printf("Current Election: %s\n", currentElection.description);

    for (int i = 0; i < num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

void setElectionType() {
    int choice;
    printf("\n===== Set Election Type =====\n");
    printf("1. Upazila Nirbachon\n");
    printf("2. City Corporation Nirbachon\n");
    printf("3. Jatiyo Nirbachon\n");
    printf("=============================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            currentElection.type = 1;
            strcpy(currentElection.description, "Upazila Nirbachon");
            printf("Election type set to Upazila Nirbachon.\n");
            break;
        case 2:
            currentElection.type = 2;
            strcpy(currentElection.description, "City Corporation Nirbachon");
            printf("Election type set to City Corporation Nirbachon.\n");
            break;
        case 3:
            currentElection.type = 3;
            strcpy(currentElection.description, "Jatiyo Nirbachon");
            printf("Election type set to Jatiyo Nirbachon.\n");
            break;
        default:
            printf("Invalid choice. Please select a valid election type.\n");
    }
}

void sortCandidates() {
    for (int i = 0; i < num_candidates - 1; i++) {
        for (int j = i + 1; j < num_candidates; j++) {
            if (candidates[i].votes < candidates[j].votes) {
                Candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
}














// Dipa
void userLogin() {
    char username[MaxNameLength];
    char password[MaxNameLength];

    printf("\n===== User Login =====\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("User logged in successfully.\n");
            voteCandidate(&users[i]);
            return;
        }
    }
    printf("Invalid username or password. Please try again.\n");
}

void userSignup() {
    if (num_users >= MaxUser) {
        printf("Maximum users reached. Cannot create a new user.\n");
        return;
    }

    printf("\n===== User Signup =====\n");
    printf("Enter your username: ");
    scanf("%s", users[num_users].username);

    printf("Enter your password: ");
    scanf("%s", users[num_users].password);

    users[num_users].votes_given = 0;
    num_users++;
    printf("User created successfully. Please login.\n");
}

















// Aman
void voteCandidate(User *user) {
    if (user->votes_given >= 1) {
        printf("You have already voted. You can only vote once.\n");
        return;
    }

    printf("\n===== Candidates List =====\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%s)\n", i + 1, candidates[i].name, candidates[i].sign);
    }

    int choice;
    printf("==========================\n");
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

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>      
#include <strings.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    // Because argc should have candidates list 
    // which will be at index 2 or more according to number of candidates entered
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        // Putting candidate names into our array of candidates
        candidates[i].name = argv[i + 1]; 
        // Initially setting votes to zero so that we can increment later on
        candidates[i].votes = 0;
    }

    // Asking for number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Basically it should return a false if given name is not present in candidates[].name
    for (int i = 0; i < candidate_count; i++) {
        if (strcasecmp(name, candidates[i].name) == 0) {
            // The name is present and we need to increase it's vote count
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Here we just need to find the highest votes and print the winner
    int winner_index = 0;

    for (int i = 0; i < candidate_count; i++) {
        if (candidates[winner_index].votes < candidates[i].votes) {
            winner_index = i;
        }
    }

    // At the end we print the winner with total vote counts
    printf("Winner is %s with %d votes", candidates[winner_index].name, candidates[winner_index].votes);

    return;
}
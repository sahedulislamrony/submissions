#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int voteW; // winer votes
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];
int strength[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void swap(int *num1, int *num2);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }


    pair_count = 0;

    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j + 1, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }
    /*

    for(int i=0;i<candidate_count;i++)
    {
        for(int j=0;j<candidate_count;j++)
        {
            printf("%i   ", preferences[i][j] );
        }
        printf("\n");
    }*/

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    bool status = false;
    for (int i = 0; i < candidate_count; i++)
    {
        int isEqual = strcmp(candidates[i], name);
        if (isEqual == 0)
        {

            ranks[i] = rank;

            status = true;
        }
    }

    return status;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i != j && ranks[i] < ranks[j])
            {
                preferences[i][j] += 1;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int vote1, vote2;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (j > i)
            {
                vote1 = preferences[i][j]; // i-th candidate vote against j
                vote2 = preferences[j][i]; // j-th candidate votes against i

                if (vote1 >= vote2)
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;

                    strength[pair_count] = vote1 - vote2;
                }
                else
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;

                    strength[pair_count] = vote2 - vote1;
                }
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    bool status = true;

    while (status)
    {
        int i = 0;
        int swaps = 0;
        int temp1, temp2;
        for (i = 0; i < pair_count - 1; i++)
        {
            // values
            temp1 = strength[i];
            temp2 = strength[i + 1];

            if (temp1 < temp2)
            {
                // value swap
                swap(&strength[i], &strength[i + 1]);

                // winner index swap

                swap(&pairs[i].winner, &pairs[i + 1].winner);

                // Loser index swap
                swap(&pairs[i].loser, &pairs[i + 1].loser);

                swaps++;
            }
        }

        if (swaps == 0)
            status = false;
    }

    return;
}

// swap two variables
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int indexW, indexL;

    for (int j = 0; j < pair_count; j++)
    {
        indexW = pairs[j].winner;
        indexL = pairs[j].loser;

        locked[indexW][indexL] = true;
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool winner = false;
        int count=0;
        for (int j = 0; j < candidate_count; j++)
        {

            if (i != j)
            {

                if (locked[i][j])
                {
                    winner = true;
                    count++;
                }
                else
                {
                    winner = false;
                    count--;
                }
            }
        }
        if (winner && count == candidate_count - 1)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }

    // if no source found

    locked[pairs[pair_count - 1].winner][pairs[pair_count - 1].loser] = false;
    locked[pairs[pair_count - 1].loser][pairs[pair_count - 1].winner] = true;

    print_winner();

    return;
}

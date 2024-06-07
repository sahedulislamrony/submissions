import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py databases/file.csv sequences/name.txt")
        sys.exit(-1)

    # TODO: Read database file into a variable
    database = []

    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        for row in reader:
            database.append(row)

    # for row in database:
    #     for key in row:
    #         print(key)

    #     print()

   # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2], 'r') as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence

    strC = len(database[0]) - 1    # Number  of the STR
    record = [0] * strC
    STRs = database[0][1:]
    i = 0
    for str in STRs:
        record[i] = longest_match(sequence, str)
        i += 1

    # for j in range(strC):
    #     print(record[j])

    # TODO: Check database for matching profiles
    database = database[1:]

    for row in database:
        match = 0
        for j in range(strC):
            if int(row[j+1]) == record[j]:
                match += 1
        if match == strC:
            print(row[0])
            break

    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

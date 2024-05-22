import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python3 dna.py data.csv sequence.txt")
        sys.exit(1)
    else:
        pass

    # TODO: Read database file into a variable
    rows = []
    column_names = []

    with open(f"{sys.argv[1]}") as database: # By default it opens it in read mode
        reader = csv.DictReader(database) # Gets each entry as a dictionary
        column_names = reader.fieldnames

        for row in reader:
            rows.append(row)
    # print(rows)
    
    # TODO: Read DNA sequence file into a variable
    given_dna_seq = ""
    with open(f"{sys.argv[2]}") as dna_seq:
        given_dna_seq = dna_seq.read()

    # TODO: Find longest match of each STR in DNA sequence
    seq_dict = {}

    for i in range(1, len(column_names)):
        seq_dict[f"{column_names[i]}"] = longest_match(given_dna_seq, column_names[i])

    # print(seq_dict)

    # TODO: Check database for matching profiles
    all_matched_flag = len(column_names) - 1

    for i in rows:
        for j in seq_dict:
            # print(i)
            # print(j)
            if seq_dict[j] == int(i[j]):
                all_matched_flag -= 1
            else:
                break
        if all_matched_flag == 0:
            print(i["name"])
            return 0
        else:
            all_matched_flag = len(column_names) - 1

    print("No Match")
    return 1


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

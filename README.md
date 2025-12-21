# text-analyzer
This program is done when it can read text files, extract words, count their frequencies and display statistics.
Flow:
1. Program starts
2. Read command line input
3. Determine whether input is file or directory
4. Open file(s)
5. Process text
6. Update word count
7. Print results
8. Program ends

- Input handling
- File reading
- Text parsing
- Word normalization
- Counting
- Output formating

UPDATE
* Description ->
This program is a text analyzer that takes one or more files from the command line. It analyzes the files
using a hashmap (std::unordered_map) to count how many times each word appears. The program also displays
the top 10 most frequent words across all given files.

* Usage ->
Simply run:
./text-analyzer <filename1.txt> <filename2.txt>
You may add as many files as you wish.

* How it works ->
1. Checks if files are provided
2. Opens each file and reads its contents line by line
3. Splits lines into words and normalizes them (lowercase + remove punctuation)
4. Word count using a hashmap
5. Sorts words by frequency and displays top 10 words

* Features ->
IN PROGRESS

* Notes ->
- Splitting lines into words and normalzing them:
Each line from the file is broken down into individual words using whitespace as a separator. Each
word is then normalized by converting it to lowercase and removing punctuation. This makes sure that
words like "Hello", "hello" and "HELLO" are all recognized as the same and counted together.


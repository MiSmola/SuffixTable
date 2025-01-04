# SuffixTable
The program, based on the loaded files containing the text and the searched patterns, creates a sorted array of suffixes and searches the loaded patterns in it, finally creating a result file with the patterns and their occurrences in the text.

Software created as a project on Computer Programming laboratory on Silesian University of Technology.

## Usage
The program retrieves two files in *.txt format: a file with the text and a file with the searched patterns. Based on the text file, the program creates an array of suffixes and sorts it. Then, using the binary search algorithm, it looks for patterns in the array and saves their occurrences. At the end, a resultant file in .txt format is generated with information about the occurrences for each of the loaded patterns.

## Algorithm
By 𝑆𝑈𝐵𝑊𝑂𝑅𝐷𝑆(𝑥) we denote a non-empty, lexicographically sorted set of all subwords of a given text x. The consecutive indexes of the sub-words from the set 𝑆𝑈𝐵𝑊𝑂𝑅𝐷𝑆(𝑥) constitute an array of suffixes 𝑆𝑈𝐹(𝑥). We denote the alphabet letters of a given subword of length n as 𝑊𝑂𝑅𝐷(𝑎1 𝑎2 ... 𝑎𝑛), where 𝑆𝑈𝐵𝑊𝑂𝑅𝐷𝑆(𝑥)∈ 𝑊𝑂𝑅𝐷(𝑎1 𝑎2 ... 𝑎𝑛). With the suffix 𝑆𝑈𝐹𝐼𝐾𝑆𝑖 starting at the 𝑖-th position of the text 𝑥, subword 𝑊𝑂𝑅𝐷 and length 𝑙 we denote such a string of characters, which is the prefix of the word 𝑊𝑂𝑅𝐷, meaning that its letters of the alphabet are exactly the same as the initial 𝑙 letters of the word 𝑊𝑂𝑅𝐷.
Arrays of suffixes 𝑆𝑈𝐹(𝑥) were obtained by determining the indexes of subwords from the set 𝑆𝑈𝐵𝑊𝑂𝑅𝑆(𝑥) of the given text 𝑥. The algorithm for finding the pattern 𝑦 in the text 𝑥 is based on a binary search for such subwords from the set 𝑆𝑈𝐵𝑊𝑂𝑅𝐷𝑆(𝑥) whose prefix of the given subword 𝑊𝑂𝑅𝐷 is equal to the searched pattern 𝑦. The feature of the set 𝑆𝑈𝐵𝑊𝑂𝑅𝐷𝑆(𝑥) of lexicographic sorting allowed the use of a binary search strategy.

## External specification
The program is operated from the command line.
When starting the program, a command created from the following three must be given. 
- The first is the exact path to the input text file given with the `-t` switch. Example command: `-t C:\Users\User\git\SuffixTable\textFile.txt`
- The user also specifies the exact path to the pattern file using the `-p` switch, for example: `-p C:\Users\User\git\SuffixTable\patternFile.txt`
- Finally, using the `-o` switch, we specify the path where the resulting file is to be saved, for example: `-o C:\Users\User\git\SuffixTable`

Examples of correct file contents:
- Contents of searchable text file:
```she sells sea shell```
- Contents of the template file:
```
se
set
he
he
```
- Contents of the resulting file:
```
se: 10, 4
set: brak
he : brak
he: 1, 14
```

All three are separated by spaces and form a single string.
If there are any errors or if the user enters incorrect data, the program will display an appropriate notification.
For proper results, input files should not contain Polish characters.
As a result of the program's work, a `resultFile.txt` file is generated in the previously specified location on the disk, which the program will inform about with a message on the console, after which the program exits.

## Internal Specification

The program implementation utilizes the **Strategy design pattern**, enabling the modular separation of interconnected algorithms. This approach facilitates easy extension of the program with additional algorithms and allows for the modification or replacement of existing ones. The program's structure adheres to the **Model-View-Controller (MVC)** architectural pattern.

Additionally, a **template type** was used in the implementation of the singly linked list, enabling the creation of lists of any type and the execution of predefined operations on them. This approach enhances code reusability and avoids redundancy. 



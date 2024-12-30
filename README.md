# SuffixTable
The program, based on the loaded files containing the text and the searched patterns, creates a sorted array of suffixes and searches the loaded patterns in it, finally creating a result file with the patterns and their occurrences in the text.

## Usage
The program retrieves two files in *.txt format: a file with the text and a file with the searched patterns. Based on the text file, the program creates an array of suffixes and sorts it. Then, using the binary search algorithm, it looks for patterns in the array and saves their occurrences. At the end, a resultant file in .txt format is generated with information about the occurrences for each of the loaded patterns.

## External specification
The program is operated from the command line.
When starting the program, a command created from the following three must be given. The first is the exact path to the input text file given with the `-t` switch. Example command: `-t C:\Users\User\git\SuffixTable\textFile.txt`
The user also specifies the exact path to the pattern file using the `-p` switch, for example: `-p C:\Users\User\git\SuffixTable\patternFile.txt`
Finally, using the `-o` switch, we specify the path where the resulting file is to be saved, for example: `-o C:\Users\User\git\SuffixTable`

All three are separated by spaces and form a single string.
If there are any errors or if the user enters incorrect data, the program will display an appropriate notification.
For proper results, input files should not contain Polish characters.
As a result of the program's work, a `resultFile.txt` file is generated in the previously specified location on the disk, which the program will inform about with a message on the console, after which the program exits.

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

# Wordcount Application

Version: 1.0.0
Author: Toby Cook


The function of this program is to read in a text (.txt) file or words entered into the command line. It will then count how many words have been inputted and return the total word count, total unique word count and how many occurrences of each word there is. There is the option to save the results to a text file or display them in the console window as well as ignoring the character case.

  - Read text file or command line input
  - Count total words
  - Count total unique words
  - Count occurrence of each word
  - Ignores punctuation, including: ".,?!:;", quotes, tabs, spaces and new lines.
  - Output to text file or command window
  - Optional ignore character case

---

## How to Build from Source
#### Toolchain Used
This application has been built using the `Microsoft Visual C++ Build Tools 2017` including:

```
Microsoft (R) C/C++ Optimizing Compiler Version 19.12.25835 for x86
Microsoft (R) Incremental Linker Version 14.12.25835.0
```
Included in the necessary makefile needed to compile the wordcount application, including several test functions. These can be ran by typing the following commands into the command line window of the source folder.

#### Compile the Application
This will create the executable file that you can run.
```sh 
C:\words> nmake build
```
#### Read Text File and Output to Console
This test will read in a either the `single_words_test.txt` file or the `sentences_test.txt` file and output the result to the command window.
>Single Words File
```sh 
C:\words> nmake single-file-to-console
```
>Sentences File
```sh
C:\words> nmake sentences-file-to-console
```
#### Read Text File and Output to Text File
This test will read in a either the `single_words_test.txt` file or the `sentences_test.txt` file and output the result to a specified text file.
>Single Words File
```sh
C:\words> nmake single-file-to-file
```
>Sentences File
```sh
C:\words> nmake sentences-file-to-file
```
#### Read from Console and Output to Console
This test will read in a string from the command window and output the result in the same command window.
```sh
C:\words> nmake console-to-console
```
#### Read from Console and Output to Text File
This test will read in a string from the command window and output the result in a specified text file.
```sh
C:\words> nmake console-to-file
```
#### Ignoring Character Case
Tests where the character case of the input words is ignored can be ran by simply adding `-c` to each of the commands listed above. 
For example:
```sh
C:\words> nmake console-to-file-c
```
#### Cleaning Junk Files
Once you have completed all of the tests, you can clean any junk files that were created by running the following command.
```sh
C:\words> nmake clean
```

---

## Manual Testing

The table below outlines each command that can be used when running the wordcount application.

| Command | Description |
| ------ | ------ |
| -i *filename* | The name of file input file to read words from  |
| -o *filename* | The name of the output file where the counted words shall be written |
| -c | Command to indicate the case of words should be ignored during the count |

### Running from Command Line
The program can be ran manually on the command line, as long as you use the build command as above. Use the table to see details about each command.
#### Windows
```sh
C:\words> wordcount -i input.txt -o output.txt -c
```

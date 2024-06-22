# Program Assignment 1

2022-2023 Spring Semester

## Part A

A program that reads integers from a given text file, then prints out the result on the screen and writes the result into another text file, with each integer separated by a space.

The input and output file names are given by the command line arguments. The example below shows the compiled program if it's named as "a.out"

```
./a.out input.txt output.txt
The integers in file input.txt:
4 3 2 1
```

Content of "input.txt" file before the program runs:  
```
4 3 2 1
```

The contents of "output.txt" are blank before the program runs. The content of "output.txt" file after the program runs: 
```
4 3 2 1
```

For this program (Parts A and B) the layout the numbers in "input.txt" doesn't matter. The content of "output.txt", for part A, will be as displayed above. 

So, running the program as mentioned above with the contents of "input.txt" being like below, won't change the expected outcome of "output.txt" contents. 
```
4 

3 
                  2 
     1
```

"output.txt" content will still result as:
```
4 3 2 1
```
------------------------------------------
## Part A: Expected Outcomes

Below are listed a set of expected outcomes to result from typing in specific (or lack of) words. 

If the number of arguments from the user is not equal to three, then the following will be displayed:
```
Please provide the input and output text file names as ./a.out inputFileName outputFileName
```

If the input file cannot be opened, then the following will be displayed: 
```
Input file wrongInputFile.txt cannot be opened
```

If the output file cannot be opened, then the following will be displayed: 
```
Output file wrongOutputFile.txt cannot be opened. 
```
------------------------------------------

## Part B

This part extends from Part A to sort the integers read from the given input text file by increasing order first. Then, the result is printed on the screen as well as written to the output text file specified.

The input and output file names are given by the command line arguments. The example below shows the compiled program if it's named as "a.out"
```

The integers in file input.txt after sorting:
1 2 3 4 
```

Content of "input.txt" file before the program runs:  
```
4 3 2 1
```

The contents of "output.txt" are blank before the program runs. The content of "output.txt" file after the program runs: 
```
1 2 3 4
```
------------------------------------------

## Part B: Expected Outcomes

Below are listed a set of expected outcomes to result from typing in specific (or lack of) words. 

If the number of arguments from the user is not equal to three, then the following will be displayed:
```
Please provide the input and output text file names as ./a.out inputFileName outputFileName
```

If the input file cannot be opened, then the following will be displayed: 
```
Input file wrongInputFile.txt cannot be opened
```

If the output file cannot be opened, then the following will be displayed: 
```
Output file wrongOutputFile.txt cannot be opened. 
```

Due to the nature of sorting in this part of the program, dynamic memory allocation is necessary. So, the following will be displayed if the memory allocation is unsuccessful:
```
Cannot do dynamic memory management
```
------------------------------------------
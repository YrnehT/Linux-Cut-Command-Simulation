# Linux-Cut-Command-Simulation

cut.c       -main function
cutFuncs.c  -functions used by main 
cutFuncs.h  -prototypes for functions defined in cutFuncs.c

The program implements a simplistic version of the Linux cut command.
It is "simplistic" in that: 
 -it only cuts FIELDS (not characters, bytes, etc).
 -it requires between 1 and 100 fields (inclusive)
 -it requires fields to be unique, and specified in increasing order
 -it does not implement any functionality of cut other than cutting
  fields with given input delimiter and output delimiter 
 -the format of its command line arguments are simpler than cut's
 
The program expects command line arguments (CLAs) specifying the 
following, in this order:
  -input  delimiter (a single character)
  -output delimiter (a single character)
  -field(s) (at least one, and at most 100, unique positive integers, 
   given in increasing order of size)
   
Examples of proper calls to the program:
> a.out , . 2 4 5 6 9 <inputFile  
> a.out , , 3 <inputFile  
> a.out x y 1 4 32 33 37 42 57 77 86 204 337 <inputFile  

Examples of improper calls:
> a.out ,, . 2 4 5 6 9 <inputFile   #wrong input delimiter  
> a.out , . 2 4-6 9 <inputFile      #wrong field(s)  
> a.out  <inputFile                 #CLAs missing  
> a.out , . 4 4 5 6 9 <inputFile    #wrong field(s)  
> a.out , . 4 2 5  <inputFile       #wrong field(s)  

If CLAs are not as required above, print the following message on 
stderr and exit with exit code 1:
a.out: specify input_delimiter output_delimiter and 1-100 fields in order
Note that in the above error message, the following are NOT hard-coded,
but are obtained from appropriate arguments: "a.out", "100". Also,
"a.out" must be obtained from argv[0] and "100" must be from a 
#define preprocessor directive.
If the program run does not result in error, exit with exit code 0.

The program reads input from stdin only, with fields separated by a 
single input delimiter. e.g., the following file contains 3 lines, 
where line 1 has 4 fields, line 2 has 2 fields, and line 3 has 6 
fields (with input delimiter ","):
abc,de,f,ghi
a   b,cd
a,,cdefg,hi  jkl,     m     ,

The program writes output to stdout (and error message to stderr).
For each line of input, your program displays the required fields
on stdout using the output delimiter to separate fields.
e.g., if the above input file was named "thefile", then the following
run of your program produces the following output:
> ./a.out , , 1 3 <thefile  
abc,f  
a   b  
a,cdefg  
>

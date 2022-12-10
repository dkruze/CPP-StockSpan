INSTRUCTIONS FOR STOCK-SPAN PROGRAM:

	This program has two different executable files, compiled separately and independently. 
	The first file, "stockSpanBF.cpp," represents a brute-force algorithm for calculating the span of a set of values. 
	The second file, "stockSpan.cpp," represents a stack-based approach to the same problem, improving performance.
	Both files evaluate sets wherein no fewer than 2 values are allowed, because the span would then be entirely trivial. 
	As was also the case with the nQueens file, this file technically could also be "broken" with command line instructions larger than 100,000 characters, 
		so I don't recommend trying anything funny with it.
	There are two ways by which these files could be compiled: on Tesla and on a local machine with a compatible minGW g++ installed.
	
	To compile/run on Tesla:
		Option 1)  Place both cpp source files in the chosen directory. separately compile them by entering:
					g++ -c stockSpan.cpp -o [chosen executable name X]
					g++ -c stockSpanBF.cpp -o [chosen executable name Y]
				Then, you can run them one at a time with either of thse commands, respectively:
					./[X]
					./[Y]
				Where X and Y are the names your provided for your executables.
				
		Option 2)  Place both cpp source files in the chosen directory, alongside the makefile.mak file.
				Rename makefile.mak to simply "makefile," otherwise it will be unusable on Tesla
					Alternatively, you could use vim or emacs to make a file called "makefile" with no extension, then 
						copy-paste the contents from makefile.mak
				Compile both files using the following command:
					make clean
					make all
				Then, run the executables one at a time with either:
					make runBF (for the brute-force file)
					make runStack (for the stack file)
					
	To compile/run on a local machine:
		Place both cpp source files in the chosen directory. separately compile them by entering:
					g++ stockSpan.cpp -o [chosen executable name X]
					g++ stockSpanBF.cpp -o [chosen executable name Y]
				Then, you can run them one at a time with either of thse commands, respectively:
					./[X]
					./[Y]
				Where X and Y are the names your provided for your executables.
				Should you choose to compile AND run one at a time, note that modern g++ builds necessitate the use of ./a.exe 
					for unnamed executable files, NOT ./a.out like Tesla does. 
				On a linux machine, this may not be the case: make careful note of your personal install of g++.

	There is one problem with the stack implementation, and that is for any set of values where a combination of values exists between two values which are larger 
	than than every value in that combination. For example, the set 5, 1, 2, 4, 6 yields the span 1, 1, 1, 1, 5 because the existing loop 
		occasionally fails to reset the "tempIndex" variable under certain conditions. 
	This can be seen in a smaller case when n is set to 7. 
	Note that this problem does not persist for all values of n, and is considered an exception, not a rule, to the program's logic.
					

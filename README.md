# MyLinuxShell

Options Handled
A) Internal Commands :
	1) cd: Change Directory
			* cd ..: takes you one directory back
			* cd ~: takes you to the home directory		
			* cd [dirname]: takes you to specified directory 

	2) echo: This displays a line of text like a echo.
		Options-
			-n: skip printing the trailing newline
			-E: treat escape characters as part of the input string

	3) history: Shows commands used.
		-c: Clear history
		-w: adds to history without error.

	4) pwd: print current working directory(cwd)

	5) exit: Normal Exit.

B) External Commands :
	1) ls : print files and directories at pwd
		Options-
			-a : List all (including hidden) files and directories
			-A : Skip "." and ".." file

	2) cat : Concatenates files and print on the standard output
		Options-
			--help : Manpage of cat
			-n : also shows number of lines

	3) rm : Remove given files or directories
		Options-
			-f : ignore non-existent files and arguments without error
			-d : creates directory inside a directory recursively.
	
	4) date : Prints date or set the system date and time.
		Options-
			--help : Shows date commands
			-u : Shows time in UTC
	
	5) mkdir : Create directory
		Options-
			-v : Verbose directory making 
			--help : Shows manpage of mkdir

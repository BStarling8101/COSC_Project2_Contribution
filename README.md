# COSC_Project2_Contribution
Project 2
user input total # of contributors

create arrays w/:
num contributors
SUB array ea. having 4 cells

	SUBARRAYS:
	0 store name
	1 stores contribution (decimal #)
	  $$True/false != contribution must be at least 500 while the max contribution 20000. (if no, program create an 
                                                                                               error message and ask user 
                                                                                               to enter the amount again)
	2 telephone (10 digit e. 1234567891) - use character array or string (if not 10 digits error message/no alpha)
	3 class (platinum, diamond, gold, silver)

create allocated array (?? not sure on this. See step two in instructions)

Loop through num contributors and accept data input from user and store in allocated array. (How? "while for" loop?) 

If/else conditional statements:
	if > 10000 = platinum	
	else if 5001 to 10000 = diamond
	else if 1001 to 5000 = gold
	else 500 to 1000 = silver
(Not sure on ANY of this. Is if/else conditional statements what we want to use here?)



Program display:
Names
Amount donated
(Order by: Platinum; Diamond; Gold; Silver)

Write to .txt file called Charity.txt

# powerball-sim-prog

For this assignment you are to write a program to simulate playing the lottery game PowerBall. The rules for PowerBall can be found by clicking on this link: http://www.mnlottery.com/games/lotto_games/powerball/  or by clicking on this link: http://www.powerball.com/powerball/pb_howtoplay.asp
Prizes and Odds of Winning
Match	Win	Approx. Odds

5 of 5 + Powerball	JACKPOT*	1 in 292,201,338
5 of 5 numbers	$1,000,000	1 in 11,688,054
4 of 5 + Powerball	$50,000	1 in 913,129
4 of 5 numbers	$100	1 in 36,525
3 of 5 + Powerball	$100	1 in 14,494
3 of 5 numbers	$7	1 in 580
2 of 5 + Powerball	$7	1 in 701
1 of 5 + Powerball	$4	1 in 92
Powerball ONLY	$4	1 in 38











What you must do:
1.	You are to ask the user to input their numbers for the PowerBall drawings. Your program needs to perform input validation for each number entered by guaranteeing the number has not already been chosen and that it is a valid number for the lottery game PowerBall. The first five numbers must be between 1 and 69 inclusive and the powerball must be between 1 and 26 inclusive. The first five numbers are the white balls and the powerball is the red ball. 

2.	Your program will simulate the PowerBall drawing by using a random number generator to randomly select the 5 white balls and the one red ball for the lottery game. The program must guarantee each number generated for any of the five white balls has not already been selected. If the number has already been selected your program should generate a new number. You do not need to do this with the PowerBall number since only one number is selected. 

3.	NOTE: The PowerBall selection can be one of the numbers selected for the five white balls. For example: Suppose the user enters 1 2 3 4 5 for the first five numbers (the white balls), the user can also select as their PowerBall number 5 or 4 or 3 or 2 or 1. Uniqueness of the numbers only pertains to the white balls that are randomly generated and those values that are input from the user.

4.	Determine the amount of money the user has won based upon the rules shown above. 

5.	Demonstrate your program works by including test data where the user has won each prize. 

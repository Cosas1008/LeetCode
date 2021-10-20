/*
ID: yuweiic1
LANG: C++
TASK: beads
*/
### Problem of necklace

Given how many beads of necklace, find out the color which consist of most concessive identical color

b : black
w : white
r : red

white is the universal color can be regarded as even black or red.

### beads input file

29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb


#### Attemp 1

pseudo code

while (right == current color OR right == 'white')
	do right color update
		count += 1
while (left == current color OR left == 'white')
	do left color update
		count += 1

check the count > maxCount
	update maxCount

finally check whether the color in the middle is white or neigher the both side color


#### Attemp 2

add iteration parameter in loop that detect right bead color, might reduce the runtime

#### Attemp 3

do only one while loop, check the color isChanged or not indicate the breaking point

#### Attemp 4

brute force solution? Yes!


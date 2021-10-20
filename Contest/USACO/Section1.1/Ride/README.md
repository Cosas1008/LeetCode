##Your Ride Is Here

### Write a program which reads in the name of the comet and the name of the group and figures out whether according to the above scheme the names are a match, printing "**GO**" if they match and "**STAY**" if not. The names of the groups and the comets will be a string of capital letters with no spaces or punctuation, up to 6 characters long.



Examples:

<table>
<tr>
    <th>Input</th>
    <th>Output</th> 
  </tr>
  <tr>
    <td><p>COMETQ</p><p>HVNGAT<p></td>
    <td>GO</td> 
  </tr>
  <tr>
    <td><p>COMETQ</p><p>ABSTAR<p></td>
    <td>STAY</td>
  </tr>
</table>


##INPUT FORMAT

Line 1:	An upper case character string of length 1..6 that is the name of the comet.
Line 2:	An upper case character string of length 1..6 that is the name of the group.

##SAMPLE INPUT (file ride.in)

COMETQ
HVNGAT

##SAMPLE OUTPUT (file ride.out)

GO

##OUTPUT EXPLANATION

Converting the letters to numbers:
<pre>
<dt>C	O	M	E	T	Q</dt>
<dt>3	15	13	5	20	17</dt>	
<dt>H	V	N	G	A	T</dt>
<dt>8	22	14	7	1	20</dt>	
</pre>
then calculate the product mod 47:
<dt>3 * 15 * 13 * 5 * 20 * 17 = 994500 mod 47 = 27<dt>
<dt>8 * 22 * 14 * 7 *  1 * 20 = 344960 mod 47 = 27<dt>
Because both products evaluate to **27** (when modded by 47), the mission is 'GO'. 

Y.W.Chen submit on 2/22/2017 1:47:34 PM 
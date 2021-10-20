# input

<table>
  <tr>
    <th>Line</th>
    <th>Explain</th> 
  </tr>
  <tr>
    <td><p>1</p></td>
    <td> A single integer, N</td>
  </tr>
  <tr>
    <td>2 to N+1</td>
    <td>N lines of N characters (each either `@' or `-'); this is the square before transformation</td>
  </tr>
  <tr>
  	<td>N+2 to 2N+1</td>
  	<td>N lines of N characters (each either `@' or `-'); this is the square after transformation</td>
  </tr>
</table>


# output

## 1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
## 2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
## 3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
## 4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
## 5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
## 6: No Change: The original pattern was not changed.
## 7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
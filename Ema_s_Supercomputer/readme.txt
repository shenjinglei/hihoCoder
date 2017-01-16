Ema's Supercomputer

Ema built a quantum computer! Help her test its capabilities by solving the problem below.

Given a grid of size , each cell in the grid is either  or .

A valid plus is defined here as the crossing of two segments (horizontal and vertical) of equal lengths. These lengths must be odd, and the middle cell of its horizontal segment must cross the middle cell of its vertical segment.

In the diagram below, the blue pluses are valid and the orange ones are not valid. pluseses.png

Find the  valid pluses that can be drawn on  cells in the grid, and print an integer denoting the maximum product of their areas.

Note: The two pluses cannot overlap, and the product of their areas should be maximal.

Input Format

The first line contains two space-separated integers,  and .
The  subsequent lines contains  characters, where each character is either G () or B (). If the character in the  line is G, then  is a  cell (otherwise it's a  cell).

Constraints



Output Format

Find  pluses that can be drawn on  cells of the grid, and print an integer denoting the maximum product of their areas.

Sample Input 0

5 6
GGGGGG
GBBBGB
GGGGGG
GGBBGB
GGGGGG
Sample Output 0

5
Sample Input 1

6 6
BGBBGB
GGGGGG
BGBBGB
GGGGGG
BGBBGB
BGBBGB
Sample Output 1

25
Explanation

Here are two possible solutions for Sample 1 (left) and Sample 2 (right): plusss.png

Explanation Key:

Green:  cell
Red:  cell
Blue: possible .
For the explanation below, we will refer to a plus of length  as .

Sample 0 
There is enough good space to color one  plus and one  plus. , and . The product of their areas is , so we print .

Sample 1 
There is enough good space to color two  pluses. . The product of the areas of our two pluses is , so we print .
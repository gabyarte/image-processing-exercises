## Exercise 08a

Let I be the input image in file isn_256.pgm, which has a
binary impulsive noise added ("salt−and−pepper" noise). Let B be a
structuring element square of size 3x3.
Compute:
Filter 1: opening_B (I)
Filter 2: closing_B (I)
Filter 3: closing_B (opening_B (I))
Filter 4: opening_B (closing_B (I))
Indicate which are the two best filters to eliminate the noise
in output file: 'exercise_08a_output_01.txt' (particularly,
the first two lines should contain the filter numbers (1−4)).
Note: image isn_256.pgm is attached.

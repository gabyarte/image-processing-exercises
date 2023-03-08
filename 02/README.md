## Exercise 02a

Implement a program 'exercise_02a_thresh' that thresholds
an input image exercise_02a_input_01.pgm at level 'value':
exercise_02a_thresh exercise_02a_input_01.pgm value exercise_02a_output_01.pgm
The thresholding operation is as follows: a pixel p will have
a value of 255 in exercise_02a_output_01.pgm if its value in
exercise_02a_input_01.pgm is greater or equal than that of
value; otherwise, p will have a value of 0.
The image 'cam_74_threshold100.pgm' is the result of thresholding
'cam_74.pgm' at value 100.

---

## Exercise 02b

Implement a program 'exercise_02b_compare' that compares two
input PGM images (arguments of the program). The names of the
executable and of the input images are indicated in the
following example call:
exercise_02b_compare exercise_02b_input_01.pgm exercise_02b_input_02.pgm
The program should write '1' or '0' (without quotes) to an output
file called exercise_02b_output_01.txt depending on whether the
pgm images are equal or not.
The sizes of the input images could be different, in which case
exercise_02b_output_01.txt should contain '0' .
Note: two images I1 and I2 of identical sizes are equal if and only
if the intensity value of every pixel (x,y) of I1 is equal to
the intensity value of the same pixel (x,y) of I2.
Note: for checking, the previously mentioned images cam_74.pgm
and cam_74_threshold100.pgm could be used:
exercise_02b_compare cam_74.pgm cam_74.pgm
should give us that the images are equal.
On the other hand,
exercise_02b_compare cam_74.pgm cam_74_threshold100.pgm
should give us that the images are not equal.

---

## Exercise 02c

Implement a program 'exercise_02c_sup' that computes
the sup (supremum) of two input PGM images (arguments of the program).
The names of the executable and of the input images are indicated in the
following example call:
exercise_02c_sup exercise_02c_input_01.pgm exercise_02c_input_02.pgm exercise_02c_output_01.pgm
Analogous, implement a program 'exercise_02c_inf' for the inf (infimum) operation:
exercise_02c_inf exercise_02c_input_01.pgm exercise_02c_input_02.pgm exercise_02c*
output_01.pgm
Example images:
image1.pgm
image2.pgm
image1_sup_image2.pgm : sup of image1.pgm and image2.pgm
image1_inf_image2.pgm : inf of image1.pgm and image2.pgm

---

## Exercise 02d

In this exercise we are going to compare the number of
operations in two alternatives for computing a morphological dilation
with structuring element.
Let B be the MxM square structuring element.
Let C be the 1xM 1−D horizontal structuring element:
Let D be the Mx1 1−D vertical structuring element.
B (square MxM) −−−−−−−−−−−−−−−−−−− || || || |X| || || || −−−−−−−−−−−−−−−−−−−
C (1xM)
−−−−−−−−−−−−−−−−−−−
D (Mx1) −−−−−
|X||| −−−−−−−−−−−−−−−−−−− || || |X | || || || −−−−−
Note: − The number of pixels of B is MxM
− The number of pixels of C and D is M.
'X' denotes the origin of coordinates or center of the
structuring element. B, C and D are centered structuring
elements.
It can be observed that the following property holds:
B = dilate_C (D) = dilate_D (C).
Estimate the number or 'max' operations that must be computed in
order to process a NxN square input image using the following
alternatives:
dilate_B (I))
dilate_C(dilate_D (I)))
Border effects should not be considered for simplicity, i.e.,
all image pixels should be treated in the same manner.

# Instructions

## Compilation

```bash
cmake .
make
```

## Run

```bash
./bin/exercise_02a_thresh data/cam_74.pgm 100 data/threshold_output.pgm
./bin/exercise_02b_compare data/output1.pgm data/cam_74_threshold100.pgm
./bin/exercise_02c_sup data/image1.pgm data/image2.pgm data/02c__sup_output.pgm
./bin/exercise_02c_sup data/image1.pgm data/image2.pgm data/02c_inf_output.pgm
```

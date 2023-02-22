## Exercise 03a

Implement a program 'exercise_03a_erosion' that performs a morphological erosion of size 'i' using a square of size (2*i+1)x(2*i+1):

exercise_03a_erosion i exercise_03a_input_01.pgm exercise_03a_output_01.pgm Note: 8-connectivity is assumed.
Use the property of computing an erosion of size i in terms of elementary erosions of size 1.

Some test images:
immed_gray_inv.pgm (input image)
immed_gray_inv_20051123_ero1.pgm (erosion of size 1, 8-connectivity) immed_gray_inv_20051123_ero2.pgm (erosion of size 2, 8-connectivity)

---

## Exercise 03b

Implement a program 'exercise_03b_dilation' that performs a morphological dilation of size 'i' using a square of size (2*i+1)x(2*i+1):

exercise_03b_dilation i exercise_03b_input_01.pgm exercise_03b_output_01.pgm Note: 8-connectivity is assumed.
Use the property of computing a dilation of size i in terms of elementary dilations of size 1.

Some test images:
immed_gray_inv.pgm (input image)
immed_gray_inv_20051123_dil1.pgm (dilation of size 1, 8-connectivity) immed_gray_inv_20051123_dil2.pgm (dilation of size 2, 8-connectivity)

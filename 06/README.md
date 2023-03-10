## Exercise 06a

Implement a program 'exercise_06a_closing_opening' that performs a closing-opening alternated filter of size 'i' using a square of size (2*i+1)x(2*i+1):

exercise_06a_closing_opening i exercise_06a_input_01.pgm exercise_06a_output_01.pgm

Note: closing-opening( I ) refers to: closing( opening( I ) ). Note: 8-connectivity is assumed.

Some test images:
immed_gray_inv.pgm (input image)
immed_gray_inv_20051123_clo2ope2.pgm (closing (opening (I)) with size 2, 8-connectivity) immed_gray_inv_20051123_clo4ope4.pgm (closing (opening (I)) with size 4, 8-connectivity)

---

## Exercise 06b

Implement a program 'exercise_06a_opening_closing' that performs an opening-closing alternated filter of size 'i' using a square of size (2*i+1)x(2*i+1):

exercise_06b_opening_closing i exercise_06b_input_01.pgm exercise_06b_output_01.pgm

Note: opening-closing( I ) refers to: opening( closing( I ) ). Note: 8-connectivity is assumed.

Some test images:
immed_gray_inv.pgm (input image)
immed_gray_inv_20051123_ope2clo2.pgm (opening (closing (I)) with size 2, 8-connectivity) immed_gray_inv_20051123_ope4clo4.pgm (opening (closing (I)) with size 4, 8-connectivity)

# Instructions

## Compilation

```bash
cmake .
make
```

## Run

```bash
./bin/exercise_06a_closing_opening  data/immed_gray_inv.pgm 4 data/clo4ope4.pgm   
../02/bin/exercise_02b_compare data/clo4ope4.pgm data/immed_gray_inv_20051123_clo4ope4.pgm   

./bin/exercise_06a_opening_closing  data/immed_gray_inv.pgm 4 data/ope4clo4.pgm   
../02/bin/exercise_02b_compare data/ope4clo4.pgm  data/immed_gray_inv_20051123_ope4clo4.pgm 
```
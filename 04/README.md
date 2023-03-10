## Exercise 04a

Implement a program 'exercise_04a_opening' that performs a morphological opening of size 'i' using a square of size (2*i+1)x(2*i+1):

exercise_04a_opening i exercise_04a_input_01.pgm exercise_04a_output_01.pgm Note: 8-connectivity is assumed.

Some test images:
immed_gray_inv.pgm (input image)
immed_gray_inv_20051123_ope1.pgm (opening of size 1, 8-connectivity) immed_gray_inv_20051123_ope2.pgm (opening of size 2, 8-connectivity)

---

## Exercise 04b

Implement a program 'exercise_04b_closing' that performs a morphological closing of size 'i' using a square of size (2*i+1)x(2*i+1):

exercise_04b_closing i exercise_04b_input_01.pgm exercise_04b_output_01.pgm Note: 8-connectivity is assumed.

Some test images:
immed_gray_inv.pgm (input image)
immed_gray_inv_20051123_clo1.pgm (closing of size 1, 8-connectivity) immed_gray_inv_20051123_clo2.pgm (closing of size 2, 8-connectivity)

# Instructions

## Compilation

```bash
cmake .
make
```

## Run

```bash
./bin/exercise_04a_opening data/immed_gray_inv.pgm 2 data/opening2.pgm   
../02/bin/exercise_02b_compare data/opening2.pgm data/immed_gray_inv_20051123_ope2.pgm   

./bin/exercise_04b_closing data/immed_gray_inv.pgm 2 data/closing2.pgm   
../02/bin/exercise_02b_compare data/closing2.pgm data/immed_gray_inv_20051123_clo2.pgm 
```
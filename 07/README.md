## Exercise 07a

Check the idempotence of the 'closing−opening' alternated filters
for a particular case, using the programs implemented in previous exercises:
After the following calls, where 'i' denotes the size (an integer number):
exercise*06a_closing_opening i exercise_07a_input_01.pgm exercise_07a_output_01.pgm
;
exercise_06a_closing_opening i exercise_07a_output_01.pgm exercise_07a_output_02.pgm
;
exercise_02b_compare exercise_07a_output_01.pgm exercise_07a_output_02.pgm exercise*
02b\*output_01.pgm
Note: exercise_07a_output_01.pgm and exercise_07a_output_02.pgm
should be identical.
Note: use, for example, image cam_74.pgm as the
exercise_07a_input_01.pgm input image

```bash
../06/bin/exercise_06a_closing_opening data/cam_74.pgm 3 data/closing_opening_3_output1.pgm     
../06/bin/exercise_06a_closing_opening data/closing_opening_3_output1.pgm 3 data/closing_opening_3_output2.pgm  
../02/bin/exercise_02b_compare data/closing_opening_3_output1.pgm data/closing_opening_3_output2.pgm 
# Output: True
```
---

## Exercise 07b

Idem for the 'opening−closing' alternated filters.
After the following calls, where 'i' denotes the size (an integer number):
exercise_07b_opening_closing i exercise_07b_input_01.pgm exercise_07b_output_01.pgm
;
exercise_07b_opening_closing i exercise_07b_output_01.pgm exercise_07b_output_02.pgm
;
exercise_02b_compare exercise_07b_output_01.pgm exercise_07b_output_02.pgm exercise\*
02b_output_01.pgm
Note: exercise_07b_output_01.pgm and exercise_07b_output_02.pgm
should be identical.
Note: use, for example, image cam_74.pgm as the
exercise_07b_input_01.pgm input image

```bash
../06/bin/exercise_06a_opening_closing data/cam_74.pgm 3 data/opening_closing_3_output1.pgm     
../06/bin/exercise_06a_opening_closing data/opening_closing_3_output1.pgm 3 data/opening_closing_3_output2.pgm  
../02/bin/exercise_02b_compare data/opening_closing_3_output1.pgm data/opening_closing_3_output2.pgm 
# Output: True
```
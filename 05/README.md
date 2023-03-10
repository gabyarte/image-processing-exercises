## Exercise 05a

Check the idempotence of openings for a particular case,
using the programs implemented in previous exercises:
After the following calls, where 'i' denotes the size (an integer number):
exercise*04a_opening i exercise_04a_input_01.pgm exercise_04a_output_01.pgm ;
exercise_04a_opening i exercise_04a_output_01.pgm exercise_04a_output_02.pgm ;
exercise_02b_compare exercise_04a_output_01.pgm exercise_04a_output_02.pgm exercise*
02b\*output_01.txt
Note: exercise_04a_output_01.pgm and exercise_04a_output_02.pgm
should be identical.
Note: use, for example, image cam_74.pgm as the
exercise_04a_input_01.pgm input image

```bash
../04/bin/exercise_04a_opening data/cam_74.pgm 3 data/opening_3_output1.pgm     
../04/bin/exercise_04a_opening data/opening_3_output1.pgm 3 data/opening_3_output2.pgm  
../02/bin/exercise_02b_compare data/opening_3_output1.pgm data/opening_3_output2.pgm 
# Output: True
```
---

## Exercise 05b

Idem for closings.
After the following calls, where 'i' denotes the size (an integer number):
exercise_04b_closing i exercise_04b_input_01.pgm exercise_04b_output_01.pgm ;
exercise_04b_closing i exercise_04b_output_01.pgm exercise_04b_output_02.pgm ;
exercise_02b_compare exercise_04b_output_01.pgm exercise_04b_output_02.pgm exercise\*
02b_output_01.txt
Note: exercise_04b_output_01.pgm and exercise_04b_output_02.pgm
should be identical.
Note: use, for example, image cam_74.pgm as the
exercise_04b_input_01.pgm input image

```bash
../04/bin/exercise_04b_closing data/cam_74.pgm 3 data/closing_3_output1.pgm     
../04/bin/exercise_04b_closing data/closing_3_output1.pgm 3 data/closing_3_output2.pgm  
../02/bin/exercise_02b_compare data/closing_3_output1.pgm data/closing_3_output2.pgm 
# Output: True
```
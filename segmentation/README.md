# UPM Master's in Data Science: Exercises for Image Processing, Analysis and Classification subject

## Segmentation Exercises 

- S1a: Contour extraction using MM erosion or dilation

- S1b: Grassfire propagation algorithm

- S1c: Wheel teeth count

- S1d: Coffee grains watershed markers

- S1e: Fast watershed algorithm implementation

## Instructions

### Compilation

```bash
cmake .
make
```

### Run

```bash
./bin/exercise_04a_opening data/immed_gray_inv.pgm 2 data/opening2.pgm   
../02/bin/exercise_02b_compare data/opening2.pgm data/immed_gray_inv_20051123_ope2.pgm   

./bin/exercise_04b_closing data/immed_gray_inv.pgm 2 data/closing2.pgm   
../02/bin/exercise_02b_compare data/closing2.pgm data/immed_gray_inv_20051123_clo2.pgm 
```

## Collaborators
* Pablo Bande Sánchez - Girón ([@pbande](https://github.com/pbande))
* Gabriela Argüelles Terrón ([@gabyarte](https://github.com/gabyarte))
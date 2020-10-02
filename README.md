# extract-middle-term
Take two number from two statement when trying to factor second-degree equations


### Purpose
When factoring  <img src="https://latex.codecogs.com/gif.latex?ax^2&plus;bx&plus;c" title="ax^2+bx+c" /> in order to obtain *two terms* from *b* you will reach <img src="https://latex.codecogs.com/gif.latex?\inline&space;x&space;\times&space;y&space;=&space;a&space;\times&space;c" title="x \times y = a \times c" /> and <img src="https://latex.codecogs.com/gif.latex?\inline&space;x&space;&plus;&space;y&space;=&space;b" title="x + y = b" /> which requires you to "guess" the numbers. As this is a repetitive work computer might do it faster.

### Usage
There is a **run.sh** file which only puts the program in a loop, when running the program it will prompts you with `xy= ` and then `x+y= ` and then outputs the result.
As some equations are "prime" if program couldn't find any it will prints that out.

**Note: It only works with numbers!**

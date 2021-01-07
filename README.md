# Fract'ol

## Small fractal exploration program for 42 curriculum at Hive Helsinki

![Points](points.png)

### Goal of the project

• Software offers at least 3 different types of fractals - Julia - Mandelbrot
• Julia set will vary only with the mouse. As for the other types of fractal, I used same logic in order to keep UI intuitive.
• The mouse wheel zooms in and out, almost infinitely. This is the very principle of fractals.
• I use a few colors to show the depth of each fractal. There are 4 colourmodes available (blue and yellow, hue, iterations as colours and black and white)
• A parameter is passed on the command line to define what type of fractal will be
viewed. If no parameter is provided, or if the parameter is invalid, the program
displays a list of available parameters and exits.
  ./fractal "name"
The latest repository of the school's MinilibX can be found here. Note, that latest version has a function that releases mlx_init allocated memory properly, so I highly recommend only to use the latest version.
[Link](https://github.com/42Paris/minilibx-linux)

![Example of the Mandelbrot](example.png)

### Results of the project
• Software offers total of 8 different fractals; Julia, Mandelbrot, Burningship, Newton, Magnet, Tricorn, Thorn and Biomorph.
• Learnt about usage of complex numbers in computer graphics and practical use of fractals whilst scouring for information about fractals in general.
• Learnt about multithreading and optimization ie. how multiplication, square roots and divisions impact on the overall performance of the program.
• Gained deeper understanding about different colour scales (HSV vs. RGB) and how to switch between colours.
• Got to think about user experience in C programs.

Implemented following bonuses:
• Total of 8 different fractals.
• Four different colour modes.
• Ability to switch main colour.
• Added manipulation of constant C where-ever appliable.
• Zoom follows the mouse pointer.
• It is possible to move around in the image by using arrowkeys.
• Parallel computing using pthread.
• Possibility to open up multiple windows with different fractals at the same time.

### Reasonings

- I use g42 prefix for project files that I deem usable in other projects and frl to be project specific prefix.
- I retained doubles to get more precise calculations.

### Links

- MinilibX documentation by Codam students [Link](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux)
- Neener's tutorial how to use MinilibX, and DDA algorithm. [Link](https://gontjarow.github.io/MiniLibX/)
- Mandelbrot Plotting algorithms [Link](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set)
- C plotting algorithm [Link](https://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/)
- Linear interpolation [Link](https://en.wikipedia.org/wiki/Linear_interpolation))
- Illianois University examples on pthread [Link](https://courses.engr.illinois.edu/cs241/fa2010/ppt/10-pthread-examples.pdf)
- Lode's Computer Graphics tutorial is a must read, it holds basically everything you need to get the basics of fractals. [Link](https://lodev.org/cgtutor/juliamandelbrot.html)
- How to Render a Fractal, Fast [Link](https://blog.bede.io/how-to-render-a-fractal-fast/)
- About one person's endeavour to create Mandelbrot on stupidly slow machine [Link](
http://cowlark.com/2018-05-26-bogomandel/index.html)
- Equations for Nova and Magnet [Link](https://fractalfoundation.org/OFC/OFC-5-5.html)
- Paul Bourke's page on Biomorph fractals [Link](http://paulbourke.net/fractals/biomorph/)

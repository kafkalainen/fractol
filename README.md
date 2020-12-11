# Fract'ol

## Small fractal exploration program for 42 curriculum at Hive Helsinki

![Points](points.png)

### Goal of the project

• Software offers at least 3 different types of fractals - Julia - Mandelbrot
• Julia set will vary only with the mouse. As for the other types of fractal,
I used same logic in order to keep UI intuitive.
• The mouse wheel zooms in and out, almost infinitely. This is the very principle of fractals.
• I use a few colors to show the depth of each fractal.
• A parameter is passed on the command line to define what type of fractal will be
viewed. If no parameter is provided, or if the parameter is invalid, the program
displays a list of available parameters and exits properly.

The latest repository of the school's MinilibX can be found here. Note, that latest version has a function that releases mlx_init allocated memory properly, so I highly recommend only to use the latest version.
[Link](https://github.com/42Paris/minilibx-linux)

![Example of the Mandelbrot](example.png)

### To-do
- List of available parameters.
- Init vars has allocated memory, it needs to be freed.

### Checklist

- Norminette shows no errors
- No forbidden function/library
- No memory leaks
- When the program runs, there is at least a graphic window.
- ESC key exits properly the program.
- There is visual evolution when using the mouse wheel.
- Something happens visually in at least one of the implemented fractals when moving the mouse without clicking on it.
  Julia
- Set needs to evolve with moving the mouse around.
- Zooming in and out.
  Mandelbrot
- Zooming in and out.
  Additional fractals
- Zooming in and out.

Bonus

- Zooming goes where the mouse pointer is.
- It is possible to move around in the image by using arrowkeys. It also works with the zoom.
- Colors need to be very beautiful, psychedelic or changing.
- Several windows and different fractals at the same time.
- Parallel or GPU computing.
- Other features not listed here.

### Reasonings

- I use g42 prefix for project files that I deem usable in other projects and frl to be project specific prefix.
- I created g42 struct coord to hold 3d coordinates as doubles, and copy it to proj, and then translate those coordinates to screen coordinates.

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

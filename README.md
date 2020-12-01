# Fract'ol

## Small fractal exploration program for 42 curriculum at Hive Helsinki

![Points](points.png)

### Goal of the project
• Software offers at least 3 different types of fractals
	- Julia
	- Mandelbrot
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

### Features
- Rotation.

### Reasonings
- I use g42 prefix for project files that I deem usable in other projects and frl to be project specific prefix.
- I created g42 struct coord to hold 3d coordinates as doubles, and copy it to proj, and then translate those coordinates to screen coordinates.

### Links
- MinilibX documentation by Codam students [Link](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux)
- Neener's tutorial how to use MinilibX, and DDA algorithm. [Link](https://gontjarow.github.io/MiniLibX/)


// {
// 	t_vec3 start; //scaled x of pixel (scaled to lie in the mandelbrot X scale -2.5, 1)
// 				  //scaled y of pixel (scaled to lie in the mandelbrot Y scale -1, 1)
// 	t_vec3 current;
// 	int iteration;
// 	int max_iteration;
// 	double x_temp;
// 	double log_zn;
// 	double nu;

// 	iteration = 0;
// 	max_iteration = 1000;
// 	while (current.x * current.x + current.y * current.y <= (1 << 16) && iteration < max_iteration)
// 	{
// 		x_temp = current.x * current.x - current.y * current.y + start.x;
// 		current.y = 2 * current.x * current.y + start.y;
// 		current.x = x_temp;
// 		iteration++;
// 		if (iteration < max_iteration)
// 		{
// 			log_zn = log(current.x * current.x + current.y * current.y) / 2;
// 			nu = log(log_zn / log(2) / log(2));
// 		}
// 	}
// // }
//OPTIMIZED:
// x2 := 0
// y2 := 0

// while (x2 + y2 ≤ 4 and iteration < max_iteration) do
//     y := 2 × x × y + y0
//     x := x2 - y2 + x0
//     x2 := x × x
//     y2 := y × y
//     iteration := iteration + 1

# Fract_ol

This project is meant to create graphically beautiful fractals.


![Fract'ol](/img/Mandel.jpg)

Fract'ol is a School 42 project. The purpose of this project is to create fractal renderer.

Note that **macOS is only supported**.

[`fract_ol.en.pdf`](/fract_ol.en.pdf) is the task file.

## If you are new with minilibx

1. Go to minilibx_macos folder
2. Copy mlx.h in /usr/local/include
3. Make
4. Copy libmlx.a in /usr/local/lib

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## How to run program?

You can run the project with the following command:

```
./fractol <name>
```

For example, you can specify Mandelbrot fractal:

```
./fractol Mandelbrot
```

![Mandelbrot](/img/mandelbrot.png)


Available fractals:
* Mandelbrot
* Julia
* Burning ship
* Fish
* Ancients
* Web
* Rose

## Controls

Use mouse scroll to zoom.
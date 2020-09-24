<h1 align="center"><code>cub3d</code></h1>

<div align="center">
	<sub>Created by <a href="https://github.com/30c37b">Antoine Coulon</a></sub>
</div>
<div align="center">
	<sub>As part of my cursus at <a href="https://s19.be/">19</a></sub>
</div>

---

## Description

Cub3D is a simplified recreation of the famous video game [Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D) as part of the Cursus in schools of the [42 Network](https://www.42.fr/42-network/). The objective of this project is to learn graphical libraries - in this case, [MiniLibX](https://github.com/pbondoer/MinilibX), a simple library built for the students - and **raycasting**. Cub3D is written in C.

## My approach

To make my code easier to read, debug and upgrade, I decided to organise my code in an object-oriented style, simplified because of C limitations (no classes, methods, etc).

## Usage

#### Installation
```shell
$ git clone https://github.com/30c27b/cub3d.git
```

#### Compilation
```shell
$ cd cub3d
$ make
```

#### Launching Cub3D
```shell
$ ./Cub3D map [--save]
```

#### Arguments:
`map`: .cub file, examples [here](/assets/maps).

`--save`: optional, saves the first image instead of launching the game

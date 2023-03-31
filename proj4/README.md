Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

benchmark

| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | .02           | 91,964         |
| 20            | ...           | ...            |
| 50            | ...           | ...            |
| 100           | ...           | ...            |
| 200           | ...           | ...            |
| 500           | ...           | ...            |
| 1000          | ...           | ...            |
|---------------|---------------|----------------|
Grant Alderson Summary:I worked on dijkstras.cpp and answering the questions for the README.md

1. The graph is represented by a 2d array that holds the ints that each char represents on the grid.

2. according to geeksfor geeks insertion into a priority queue is log n and we do it E times do it id ElogV.



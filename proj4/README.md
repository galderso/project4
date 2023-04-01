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

benchmark by Grant Alderson and Sam Cradock

| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | .00           | 91,964         |
| 20            | .00           | 111,580        |
| 50            | .01           | 222,620        |
| 100           | .04           | 603,100        |
| 200           | .19           | 2,084,060      |
| 500           | 1.36          | 12,245,932     |
| 1000          | 6.08          | 48,737,164     |
|---------------|---------------|----------------|


1. The graph is represented by a 2d array that holds the ints that each char represents on the grid.

2. According to geeksfor geeks insertion into a priority queue is log n and we do it E times do it id ElogV.

3. With the increase in N and from the graph aboce we can see that this implementation of dijkstras is very inefficient as the numbers get higher. It uses way to much memory to be practical, this is likely because of the way it was implemented.

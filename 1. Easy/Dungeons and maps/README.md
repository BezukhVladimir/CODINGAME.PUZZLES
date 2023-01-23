# Dungeons and maps
https://www.codingame.com/training/easy/dungeons-and-maps/

## Goal
Your adventure path led you to an inn in a small, forgotten town somewhere to the North of Golem Hills. <br>
After gulping the last drop from the 9th mug of elf wine a shady old man materializes out of nowhere, in-front of you. <br>
You start to doubt the wine. <br>
The old man (throwing a pack of old maps on the table): Do you want to earn some good coins? <br>
You (without looking at him): I've enough for food and wine! <br>
The old man: What about a whole inn...! <br>
You: Hm... <br>
The old man: Yeees and you'll get the glory of being the first one to get to this treasure! <br>
You (looking at the bunch of maps): But they look the same!? <br>
The old man: Or do they, you must choose wisely. <br>
The voice of the old man (from nowhere): Ah right, one more thing, beware of the Dragons! <br>
You grab your staff and sword, swallow one more whole mug of wine: <br>
Well, it's glory time!

You are given N maps for a dungeon. Each map may contain a path to a treasure T, from starting position [ startRow; startCol ]. Determine the index of the map which holds the shortest path from the starting position to T, but be careful a map may lead you to a TRAP.

A path is marked on the map with ^, v, <, > symbols, each corresponding to UP, DOWN, LEFT, RIGHT directions respectively, i.e. each symbol shows you the next cell to move on.

A valid path must start from [ startRow; startCol ] and end on T.

The path length is the count of direction symbols plus 1, for the T cell.

Example: <br>
W = 4 H = 4 <br>
startRow = 1 startCol = 1 <br>
N = 3 <br>

Maps: <br>
0 <br>
.>>v <br>
.^#v <br>
..#v <br>
...T

1 <br>
.... <br>
.v#. <br>
.v#. <br>
.>>T

2 <br>
.... <br>
v<#. <br>
v.#. <br>
..>T


In the above example map 2 does not contain a valid path from [1; 1] to T, map 0 contains a valid path with length 7 (the count of the direction symbols + T) and map 1 contains a valid path with length 5, so the answer is 1.

## Input
Line 1: Width W and height H of the maps <br>
Line 2: startRow and startCol for the starting position on the map <br>
Line 3: An integer N for the number of maps to check <br>
N * H Lines: Each H consecutive lines are representing a single map. Each line contains W characters representing a row of a map.

Characters can be: <br>
. - Empty square <br>
\# - Wall <br>
^ - Move UP <br>
v - Move DOWN <br>
< - Move LEFT <br>
\> - Move RIGHT <br>
T - The treasure square

## Output
index of the map with the shortest path. If there isn't a map with valid path from [ startRow; startCol ] to T output TRAP.

## Constraints
There is always a T on the maps. <br>
If there are maps with valid path from [ startRow; startCol ] to T only one map holds the shortest path. <br>
The given maps are representing the same dungeon, but the position for T may differ. <br>
0 < N < 10 <br>
2 < W, H < 20

## Example
### Input
4 4 <br>
1 1 <br>
3 <br>
.>>v <br>
.^#v <br>
..#v <br>
...T <br>
.... <br>
.v#. <br>
.v#. <br>
.>>T <br>
.... <br>
v<#. <br>
v.#. <br>
..>T

### Output
1

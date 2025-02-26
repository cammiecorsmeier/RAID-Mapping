# RAID Mapping Project

## Overview
This project implements a program that maps the location of sectors in a RAID device into the sectors of the hard disks that compose it. Given a RAID configuration and a series of queries, the program determines where each queried sector is stored and, if applicable, where its copy or parity is located.

## Input Format
The input consists of:
1. A single line containing five space-separated values:
   - `T` - The RAID level ("0", "1", "01", "10", "4", or "5")
   - `N` - The number of hard disks
   - `C` - The size of the chunks (in sectors)
   - `S` - The number of sectors per disk
   - `Q` - The number of queries
2. `Q` lines, each containing a single integer representing a sector number in the RAID device.

### Constraints
- Hard disks are numbered from `0` to `N-1`.
- `N` is in the range `[2,16]`.
- `N` is always `2` for RAID level `1`.
- `N` is always an even number greater than `3` for RAID levels `01` and `10`.
- `N` is always greater than `2` for RAID levels `4` and `5`.
- `C` is in the range `[1,16]` for RAID level `0` and always `1` for other RAID levels.
- `S` is greater than `1`, always a multiple of `C`, and in the order of billions.
- `Q` is in the order of millions.
- The program must answer all queries within 1 second.

## Output Format
For each query, print a single line with two or three space-separated integers:
1. The disk number `[0, N-1]` that contains the queried sector.
2. The stripe `[0, S-1]` that contains the queried sector.
3. (If applicable) The disk number `[0, N-1]` that contains:
   - A copy of the queried sector (RAID levels `1`, `01`, `10`).
   - The parity for the queried sector (RAID levels `4`, `5`).

## RAID Level Behavior
Each RAID level follows a specific pattern for distributing sectors:
- **RAID 0**: Striped across `N` disks in chunks of size `C`.
- **RAID 1**: Mirrored between two disks.
- **RAID 01**: Mirrored striped RAID 0.
- **RAID 10**: Striped mirrored RAID 1.
- **RAID 4**: Striped with a dedicated parity disk.
- **RAID 5**: Striped with distributed parity.

## Example
### Input
```
0 4 2 6 10
18
3
23
16
1
9
10
1
14
1
```

### Output
```
1 4
1 1
3 5
0 4
0 1
0 3
1 2
0 1
3 2
0 1
```



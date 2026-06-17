// 29. Game Save State (Raw Memory Retrieval):
// Rule: Open savegame.dat. Read a raw block of memory bytes from the disk directly back into an empty PlayerStats object (containing int level, double health, int gold).
// Rule: Extract the entire object structure in a single disk operation, not variable-by-variable.

#include "iostream"
#include "fstream"
using namespace std;

struct PlayerStats {
    int level;
    double health;
    int gold;
};


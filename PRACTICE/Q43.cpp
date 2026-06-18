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

int main() {

    PlayerStats p1 = {5, 100.5, 500};
    ofstream pOut("savegame.dat", ios::binary);
    if(pOut.is_open()) {
        pOut.write(reinterpret_cast<char*>(&p1), sizeof(PlayerStats));
        pOut.close();
    }

    PlayerStats pLoaded;
    ifstream pIn("savegame.dat", ios::binary);

    if (pIn.is_open()) {
        
        pIn.read(reinterpret_cast<char*>(&pLoaded), sizeof(PlayerStats));
        pIn.close();

        cout << "--- Save State Loaded ---" << endl;
        cout << "Level: " << pLoaded.level << endl;
        cout << "Health: " << pLoaded.health << endl;
    }
}
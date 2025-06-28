#include "Graphics/GraphicsEngine.h"

int main() {
    // Will need to be moved to ZenithEngine, but here for testing purposes right now.
    GraphicsEngine gfx;
    if (!gfx.initialize(1280, 720, "Zenith Engine")) {
        return -1;
    }
    gfx.run();
    gfx.shutdown();
    return 0;
}

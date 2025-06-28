#include "ZenithEngine.h"

int main() {
    ZenithEngine engine;

    if (!engine.initialize()) {
        return -1;
    }

    engine.run();
    engine.shutdown();

    return 0;
}

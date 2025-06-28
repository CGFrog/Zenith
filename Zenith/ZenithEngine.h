#pragma once
#include <memory>

class ZenithEngine {
public:
    bool initialize();
    void run();
    void shutdown();

private:/*
    std::unique_ptr<GraphicsEngine> graphics;
    std::unique_ptr<PhysicsEngine> physics;
    std::unique_ptr<AudioEngine> audio;
    std::unique_ptr<InputManager> input;
    std::unique_ptr<SceneManager> scene;
    */
    bool isRunning = false;
};

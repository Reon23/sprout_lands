#pragma once
#include "raylib.h"

class Game {

    private:
        // Initialization
        const int screenWidth = 800;
        const int screenHeight = 450;

        void initVariables();
        void initWindow();

    public:
        // Constructors
        Game();
        virtual ~Game();

        void pollEvents();
        void update();
        void render();
        void run();
        
};

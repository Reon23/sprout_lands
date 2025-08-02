#pragma once
#include "raylib.h"

class Game {

    private:
        // Initialization
        const int screenWidth = 1000;
        const int screenHeight = 480;
        Color bgColor;
        Texture grassSprite;

        void initVariables();
        void initWindow();

    public:
        // Constructors
        Game();
        virtual ~Game();

        //Accessors
        const bool isRunning() const;

        void pollEvents();
        void update();
        void render();
        void run();
        
};

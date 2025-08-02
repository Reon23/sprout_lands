#pragma once
#include "raylib.h"

class Game {

    private:
        // Initialization
        const int screenWidth = 1000;
        const int screenHeight = 480;
        Color bgColor;
        Texture2D grassSprite;

        //Player
        Texture2D playerSprite;
        Rectangle playerSrc;
        Rectangle playerDest;
        float playerSpeed;

        void initVariables();
        void initWindow();

    public:
        // Constructor & Destructor
        Game();
        virtual ~Game();

        //Accessors
        const bool isRunning() const;

        void pollEvents();
        void update();
        void render();
        void run();
        
};

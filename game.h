#pragma once
#include "raylib.h"
#include "player.h"

class Game {

    private:
        // Initialization
        const int screenWidth = 1000;
        const int screenHeight = 480;
        Color bgColor;
        Texture2D grassSprite;

        //Music
        Music music;
        bool musicPaused;

        //Camera
        Camera2D camera;

        // Player
        Player* player;

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

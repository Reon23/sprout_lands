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

        //Player Movement
        bool playerMoving;
        bool playerUp;
        bool playerDown;
        bool playerLeft;
        bool playerRight;

        //Frame Count
        int playerDir;
        int playerFrame;
        int frameCount;

        //Music
        Music music;
        bool musicPaused;

        //Camera
        Camera2D camera;

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

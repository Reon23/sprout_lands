#pragma once
#include "raylib.h"

class Player {
    private:
        // Initialization 
        //Player
        Texture2D playerSprite;
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

        void initVariables();

    public:
        Rectangle playerSrc;
        Rectangle playerDest;

        // Constructor & Destructor
        Player();
        virtual ~Player();

        void handleMovement();
        void animate();
        void render();
};

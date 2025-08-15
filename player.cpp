#include "player.h"

void Player::initVariables() {
    // Player
    playerSprite = LoadTexture("assets/Characters/CharacterSpriteSheet.png");
    playerSrc = Rectangle{0, 0, 48, 48};
    playerDest = Rectangle{200, 200, 100, 100};
 
    playerMoving = false;
    playerUp = false;
    playerDown = false;
    playerLeft = false;
    playerRight = false;

    playerDir = 0;
    playerFrame = 0;
    frameCount = 0;   playerSpeed = 5;
}

Player::Player() {
    initVariables();
}

Player::~Player() {
    UnloadTexture(playerSprite);
}

void Player::handleMovement() {
    //INFO: Handle input events:
    // Player Movement
    if (IsKeyDown(KEY_W)) {
        playerMoving = true;
        playerDir = 1;
        playerUp = true;
    }
    if (IsKeyDown(KEY_S)) {
        playerMoving = true;
        playerDir = 0;
        playerDown = true;
    }
    if (IsKeyDown(KEY_A)) {
        playerMoving = true;
        playerDir = 2;
        playerLeft = true;
    }
    if (IsKeyDown(KEY_D)) {
        playerMoving = true;
        playerDir = 3;
        playerRight = true;
    }
}

void Player::animate() {
    // Player Movement
    if (playerMoving) {
        if (playerUp) {
            playerDest.y -= playerSpeed;
        }
        if (playerDown) {
            playerDest.y += playerSpeed;
        }
        if (playerLeft) {
            playerDest.x -= playerSpeed;
        }
        if (playerRight) {
            playerDest.x += playerSpeed;
        }
        if (frameCount % 8 == 1) playerFrame++;
    }
    else if (frameCount % 45 == 1) {
        playerFrame++;
    }

    // Player Animation
    frameCount++;
    if (playerFrame > 3) playerFrame = 0;
    if (!playerMoving && playerFrame > 1) playerFrame = 0;
    playerSrc.x = playerSrc.width * playerFrame;
    playerSrc.y = playerSrc.height * playerDir;

    // Player Movement
    playerMoving = false;
    playerUp = false;
    playerDown = false;
    playerLeft = false;
    playerRight = false;
}

void Player::render() {
    DrawTexturePro(playerSprite, playerSrc, playerDest,
            Vector2{playerDest.width / 2, playerDest.height / 2},
            0, RAYWHITE);
}

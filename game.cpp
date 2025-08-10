#include "game.h"

void Game::initVariables()
{
    // Initialization
    // TODO: Load resources / Initialize variables at this point

    // Background
    bgColor = (Color){147,211,196,255};
    grassSprite = LoadTexture("assets/Tilesets/Grass.png");

    // Player
    playerSprite = LoadTexture("assets/Characters/CharacterSpriteSheet.png");
    playerSrc = Rectangle{0, 0, 48, 48};
    playerDest = Rectangle{200, 200, 100, 100};
    playerSpeed = 5;

    //Music
    InitAudioDevice();
    music = LoadMusicStream("assets/audio/ChillMuzic.mp3");
    musicPaused = false;
    PlayMusicStream(music);

    //Camera
    camera = Camera2D{
        Vector2{screenWidth/2.f, screenHeight/2.f}, 
        Vector2{playerDest.x - playerDest.width/2.f, playerDest.y - playerDest.height/2.f}, 
        0.0, 1.0};
}

void Game::initWindow()
{
    InitWindow(screenWidth, screenHeight, "Sprout Lands");
    SetExitKey(0);
    SetTargetFPS(60);
}

Game::Game()
{
    initWindow();
    initVariables();
}

Game::~Game()
{
    UnloadTexture(grassSprite);
    UnloadTexture(playerSprite);
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
}

const bool Game::isRunning() const
{
    return !WindowShouldClose();
}

void Game::pollEvents()
{
    //TODO: Handle input events:
    //
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

    //Music Control
    if (IsKeyPressed(KEY_M)) musicPaused = !musicPaused;

    // Camera Position
    camera.target = Vector2{playerDest.x - playerDest.width/2.f, playerDest.y - playerDest.height/2.f};
}

void Game::render()
{
    BeginDrawing();
    ClearBackground(bgColor);
    BeginMode2D(camera);

    // TODO: Draw everything that requires to be drawn at this point:
    DrawTexture(grassSprite, 100, 50, RAYWHITE);
    DrawTexturePro(playerSprite, playerSrc, playerDest, Vector2{playerDest.width, playerSrc.height}, 0, RAYWHITE);

    EndMode2D();
    EndDrawing();
}

void Game::update()
{
    // TODO: Update variables :
    //
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


    // Music Stream
    UpdateMusicStream(music);
    if (musicPaused) PauseMusicStream(music);
    else ResumeMusicStream(music);

    // Player Movement
    playerMoving = false;
    playerUp = false;
    playerDown = false;
    playerLeft = false;
    playerRight = false;
}

void Game::run() {
    while (isRunning()) {
        pollEvents();
        update();
        render();
    }
}


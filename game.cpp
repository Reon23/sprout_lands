#include "game.h"
#include "player.h"

void Game::initVariables()
{
    // Initialization
    // TODO: Load resources / Initialize variables at this point

    // Background
    bgColor = (Color){147,211,196,255};
    grassSprite = LoadTexture("assets/Tilesets/Grass.png");

    //Music
    InitAudioDevice();
    music = LoadMusicStream("assets/audio/ChillMuzic.mp3");
    musicPaused = false;
    PlayMusicStream(music);

    //Player
    player = new Player();

    //Camera
    camera = Camera2D{
        Vector2{screenWidth/2.f, screenHeight/2.f}, 
        Vector2{player->playerDest.x - player->playerDest.width/2.f, player->playerDest.y - player->playerDest.height/2.f}, 
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
    delete player;
    UnloadTexture(grassSprite);
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
    player->handleMovement();

    //Music Control
    if (IsKeyPressed(KEY_M)) musicPaused = !musicPaused;

    // Camera Position
    camera.target = Vector2{player->playerDest.x - player->playerDest.width/2.f, player->playerDest.y - player->playerDest.height/2.f};
}

void Game::render()
{
    BeginDrawing();
    ClearBackground(bgColor);
    BeginMode2D(camera);

    // TODO: Draw everything that requires to be drawn at this point:
    DrawTexture(grassSprite, 100, 50, RAYWHITE);

    player->render();

    EndMode2D();
    EndDrawing();
}

void Game::update()
{

    player->animate();

    // Music Stream
    UpdateMusicStream(music);
    if (musicPaused) PauseMusicStream(music);
    else ResumeMusicStream(music);
}

void Game::run() {
    while (isRunning()) {
        pollEvents();
        update();
        render();
    }
}


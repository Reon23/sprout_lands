#include "game.h"

void Game::initVariables()
{
    // Initialization
    // TODO: Load resources / Initialize variables at this point
    grassSprite = LoadTexture("assets/Tilesets/Grass.png");
    bgColor = (Color){147,211,196,255};
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
    CloseWindow();
}

const bool Game::isRunning() const
{
    return !WindowShouldClose();
}

void Game::pollEvents()
{
    //TODO: Handle input events:
}

void Game::render()
{
    BeginDrawing();

    // TODO: Draw everything that requires to be drawn at this point:
    DrawTexture(grassSprite, 100, 50, RAYWHITE);
    ClearBackground(bgColor);

    EndDrawing();
}

void Game::update()
{
    // TODO: Update variables :
}

void Game::run() {
    while (isRunning()) {
        pollEvents();
        update();
        render();
    }
}


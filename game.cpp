#include "game.h"
#include <raylib.h>

void Game::initVariables()
{
    // Initialization
    // TODO: Load resources / Initialize variables at this point
}

void Game::initWindow()
{
    InitWindow(screenWidth, screenHeight, "raylib [<module>] example - <name>");
    SetTargetFPS(60);
}

Game::Game()
{
    initVariables();
    initWindow();
}

Game::~Game()
{
    CloseWindow();
}

void Game::pollEvents()
{
    //TODO: Handle input events:
}

void Game::render()
{
    BeginDrawing();

    // TODO: Draw everything that requires to be drawn at this point:
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}

void Game::update()
{
    // TODO: Update variables :
}

void Game::run() {
    while (!WindowShouldClose()) {
        pollEvents();
        update();
        render();
    }
}


#include "raylib.h"
#include "raymath.h"

int main(void) {

    const int screenWidth = 640;
    const int screenHeight = 480;

    int frames = 6;
    const float scarfyWalkSpeed = 8.5f;

    InitWindow(screenWidth, screenHeight, "2D Title");

    //Texture2D scarfyTexture = LoadTexture("../resources/scarfy.png");
    Texture2D scarfyTexture = LoadTexture("resources/scarfy.png");
    int frameWidth = scarfyTexture.width / frames; // 6 sprites per texture
    int frameHeight = scarfyTexture.height;

    Rectangle scarfyRectangle = {0.0f, 0.0f, (float) frameWidth, (float) frameHeight};
    Vector2 scarfyPosition = {(float) screenWidth / 2.5f, (float) screenHeight / 2.5f};
    Vector2 scarfyVelocity = {0.0f, 0.0f};

    bool isMoving = false;

    unsigned frameDelay = 5;
    unsigned frameDelayCounter = 0;
    unsigned frameIndex = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        DrawText("Press < or >", 20, 20, 12, BLACK);

        if (IsKeyDown(KEY_RIGHT)) {
            scarfyVelocity.x = scarfyWalkSpeed;
            if (scarfyRectangle.width < 0) {
                scarfyRectangle.width *= -1;
            }
        } else if (IsKeyDown(KEY_LEFT)) {
            scarfyVelocity.x = -scarfyWalkSpeed;
            if (scarfyRectangle.width > 0) {
                scarfyRectangle.width *= -1;
            }
        } else {
            scarfyVelocity.x = 0;
        }

        isMoving = (scarfyVelocity.x == 0.0f && scarfyVelocity.y == 0.0f) ? false : true;

        scarfyPosition = Vector2Add(scarfyPosition, scarfyVelocity);

        if (++frameDelayCounter > frameDelay) {

            frameDelayCounter = 0;

            if (isMoving) {
                ++frameIndex;
                frameIndex %= frames;
                scarfyRectangle.x = (float) frameWidth * (float) frameIndex;
            }
        }


        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureRec(scarfyTexture, scarfyRectangle, scarfyPosition, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

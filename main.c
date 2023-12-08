#include <raylib.h>
#include <stdio.h>

#define DANCEMAN_COUNT 7
#define FRAME_SPEED 8
#define FPS 60

int main(void)
{
    const int screen_width = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "Dance man");

    Texture2D danceman = LoadTexture("resources/danceman.png");
    Rectangle frame = {0.0f, 0.0f, (float)danceman.width / DANCEMAN_COUNT, (float)danceman.height};
    int current_frame = 0;
    int frame_count = 0;

    InitAudioDevice();
    Music music = LoadMusicStream("resources/rockbeat.mp3");
    PlayMusicStream(music);

    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        frame_count++;
        UpdateMusicStream(music);

        if (frame_count >= FPS / FRAME_SPEED)
        {
            frame_count = 0;
            current_frame++;

            if (current_frame > DANCEMAN_COUNT - 1) current_frame = 0;
            frame.x = (float)current_frame * (float)danceman.width / DANCEMAN_COUNT;
        }

        // BeginDrawing and EndDrawing are needed even if we do not want to draw
        // - music and WindowShouldClose bugs out without them
        BeginDrawing();

        ClearBackground(BLACK);
        DrawTextureRec(danceman, frame, (Vector2){.x = (float)screen_width / 2, .y = (float)screen_height / 2},
                       RAYWHITE);

        EndDrawing();
    }

    UnloadTexture(danceman);
    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

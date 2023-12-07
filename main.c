#include <stdio.h>

#include <raylib.h>

int main(void)
{
    const int screen_width = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "Hey buddy");

    InitAudioDevice();
    Music music = LoadMusicStream("resources/rockbeat.mp3");
    PlayMusicStream(music);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
      UpdateMusicStream(music);

      // These two are needed even if we do not want to draw
      // music and WindowShouldClose bugs out without them
      BeginDrawing();
      EndDrawing();
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

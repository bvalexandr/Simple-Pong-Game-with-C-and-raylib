#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Vector2 pos;
    int radius;
    double speed;
    Vector2 dirs;
    Color color;
} Ball;

typedef struct {
    Rectangle rect;
    double speed;
    Color color;
    int score;
} Pad;

int main(void) {
    const int w_width = 800;
    const int w_height = 600;
    const int max_score = 10;
    Ball ball;
    ball.pos.x = w_width / 2;
    ball.pos.y = w_height / 2;
    ball.radius = 10;
    ball.speed = 250.0;
    ball.color = GREEN;
    ball.dirs.x = (float)rand() / (float)(RAND_MAX);
    ball.dirs.y = sqrt(1 - pow(ball.dirs.x, 2));
    Pad left_pad;
    left_pad.rect.x = 0;
    left_pad.rect.y = w_height / 2;
    left_pad.rect.width = 15;
    left_pad.rect.height = 80;
    left_pad.speed = 300.0;
    left_pad.color = BLUE;
    left_pad.score = 0;
    Pad right_pad = left_pad;
    right_pad.rect.x = w_width - right_pad.rect.width;
    InitWindow(w_width, w_height, "RayLib Pong");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        float delta = GetFrameTime();
        BeginDrawing();
        ClearBackground((Color){100, 150, 100, 100});
        if (left_pad.score == max_score || right_pad.score == max_score) {
            DrawText(TextFormat("Player %s Wins!", left_pad.score > right_pad.score ? "Left" : "Right"),
                     w_width / 2 - 110, w_height / 2, 32, WHITE);
        } else {
            ball.pos.x += ball.dirs.x * ball.speed * delta;
            ball.pos.y += ball.dirs.y * ball.speed * delta;
            if (CheckCollisionCircleRec(ball.pos, ball.radius, left_pad.rect)) {
                ball.dirs.x *= -1 + ((float)rand() / (float)(RAND_MAX)) / 50.0;
                ball.dirs.y = sqrt(1 - pow(ball.dirs.x, 2));
            } else if (ball.pos.x < 0 && ball.dirs.x < 0) {
                right_pad.score++;
                ball.pos.x = w_width / 2;
                ball.pos.y = w_height / 2;
                ball.dirs.x = (float)rand() / (float)(RAND_MAX);
                ball.dirs.y = sqrt(1 - pow(ball.dirs.x, 2));
            }
            if (CheckCollisionCircleRec(ball.pos, ball.radius, right_pad.rect)) {
                ball.dirs.x *= -1 + ((float)rand() / (float)(RAND_MAX)) / 50.0;
                ball.dirs.y = sqrt(1 - pow(ball.dirs.x, 2));
            } else if (ball.pos.x > w_width && ball.dirs.x > 0) {
                left_pad.score++;
                ball.pos.x = w_width / 2;
                ball.pos.y = w_height / 2;
                ball.dirs.x = (float)rand() / (float)(RAND_MAX) * -1;
                ball.dirs.y = sqrt(1 - pow(ball.dirs.x, 2));
            }
            if (ball.pos.y - ball.radius < 0 || ball.pos.y + ball.radius > w_height) {
                ball.dirs.y *= -1;
            }
            if (IsKeyDown(KEY_W) && left_pad.rect.y > 0) {
                left_pad.rect.y += -1 * left_pad.speed * delta;
            }
            if (IsKeyDown(KEY_S) && left_pad.rect.y + left_pad.rect.height < w_height) {
                left_pad.rect.y += 1 * left_pad.speed * delta;
            }
            if (IsKeyDown(KEY_P) && right_pad.rect.y > 0) {
                right_pad.rect.y += -1 * right_pad.speed * delta;
            }
            if (IsKeyDown(KEY_L) && right_pad.rect.y + right_pad.rect.height < w_height) {
                right_pad.rect.y += 1 * right_pad.speed * delta;
            }
            DrawCircle(ball.pos.x, ball.pos.y, ball.radius, ball.color);
            DrawRectangleRounded(left_pad.rect, 1, 4, left_pad.color);
            DrawRectangleRounded(right_pad.rect, 1, 4, right_pad.color);
            DrawLine(w_width / 2, 0, w_width / 2, w_height, WHITE);
            DrawText(TextFormat("%d", left_pad.score), w_width / 2 - 40, 10, 32, WHITE);
            DrawText(TextFormat("%d", right_pad.score), w_width / 2 + 22, 10, 32, WHITE);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
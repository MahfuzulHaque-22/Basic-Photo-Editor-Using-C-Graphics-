#include <graphics.h>
#include <stdio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Load the image
    readimagefile("image.bmp", 0, 0, getmaxx(), getmaxy());

    // Get the dimensions of the image
    int width = getmaxx() + 1;
    int height = getmaxy() + 1;

    // Change the size of the image
    int new_width = width / 2;
    int new_height = height / 2;
    setviewport(0, 0, new_width - 1, new_height - 1, 1);
    clearviewport();
    putimage(0, 0, &imagesize(0, 0, width - 1, height - 1));

    // Change the color of the image
    setcolor(BLUE);
    setbkcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(50, 50, "Hello, World!");

    // Change the hue of the image
    setcolor(RED);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(200, 200, 100);
    floodfill(200, 200, RED);

    // Change the brightness of the image
    setcolor(WHITE);
    setbkcolor(BLACK);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 100, "Brightness Test");
    for (int i = 0; i < 256; i++) {
        setpalette(i, i, i, i);
        delay(10);
    }

    // Save the modified image
    writeimagefile("output.bmp", 0, 0, new_width - 1, new_height - 1);

    getch();
    closegraph();
    return 0;
}

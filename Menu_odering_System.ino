#include <LCDWIKI_GUI.h>
#include <LCDWIKI_KBV.h>
#include <SoftwareSerial.h>

// LCDWIKI for ILI9341
LCDWIKI_KBV mylcd(ILI9341, A3, A2, A1, A0, A4); // model,cs,cd,wr,rd,reset

// TTP229 Touch Sensor connected to digital pins 2–9
const int touchPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// Color definitions
#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0
#define BLUE    0x001F
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define GREY    0x8410
#define GOLD    0xFEA0
#define LIME    0x07E0

// Menu labels (updated)
const char* labels[8] = {
  "1.Vat", "2.Ruti", "3.Dal", "4.Sobji", "5.Goru", "6.Burger", "7.Call Waiter", "8.Bill"
};

// Button layout and appearance
int buttonX[8] = {10, 10, 10, 130, 130, 130, 10, 10};
int buttonY[8] = {30, 80, 130, 30, 80, 130, 180, 230};
int buttonW[8] = {100, 100, 100, 100, 100, 100, 220, 220};
int buttonH[8] = {40, 40, 40, 40, 40, 40, 40, 40};
uint16_t buttonColor[8] = {GOLD, GOLD, GOLD, GOLD, GOLD, GOLD, CYAN, MAGENTA};

void setup() {
  Serial.begin(9600);
  mylcd.Init_LCD();
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Text_Mode(0);
  mylcd.Set_Text_Size(3);
  mylcd.Set_Text_Back_colour(BLACK);
  mylcd.Set_Text_colour(WHITE);
  mylcd.Print_String("Loading...", CENTER, 110);
  delay(500);

  drawHome();

  // Set all touch pins as input
  for (int i = 0; i < 8; i++) {
    pinMode(touchPins[i], INPUT_PULLUP);
  }

  Serial.println("TTP229 Touch Sensor Initialized");
}

void loop() {
  for (int i = 0; i < 8; i++) {
    if (digitalRead(touchPins[i]) == HIGH) {
      handleButtonPress(i);
      delay(500); // debounce
    }
  }
}

// Draw full menu screen
void drawHome() {
  mylcd.Fill_Screen(WHITE);
  mylcd.Draw_Round_Rectangle(0, 0, 319, 240, 8);
  mylcd.Set_Text_Size(3);
  mylcd.Set_Text_Back_colour(WHITE);
  mylcd.Set_Text_colour(LIME);
  mylcd.Print_String("Menu", CENTER, 0);

  for (int i = 0; i < 8; i++) {
    drawButton(buttonX[i], buttonY[i], buttonW[i], buttonH[i], buttonColor[i], labels[i]);
  }
}

// Draw individual button
void drawButton(int x, int y, int w, int h, uint16_t color, const char *label) {
  mylcd.Set_Draw_color(color);
  mylcd.Fill_Round_Rectangle(x, y, x + w, y + h, 8);
  mylcd.Set_Draw_color(WHITE);
  mylcd.Draw_Round_Rectangle(x, y, x + w, y + h, 8);

  mylcd.Set_Text_Size(2);
  mylcd.Set_Text_Back_colour(color);
  mylcd.Set_Text_colour(BLACK);
  int textX = x + (w - strlen(label) * 12) / 2;
  int textY = y + (h - 16) / 2;
  mylcd.Print_String(label, textX, textY);
}

// Handle button press logic
void handleButtonPress(int index) {
  int x = buttonX[index];
  int y = buttonY[index];
  int w = buttonW[index];
  int h = buttonH[index];
  const char* label = labels[index];

  Serial.print(label);
  Serial.println(" Ordered");

  // Press feedback effect
  mylcd.Set_Draw_color(WHITE);
  mylcd.Fill_Round_Rectangle(x, y, x + w, y + h, 8);
  delay(70);

  mylcd.Set_Draw_color(GREEN);
  mylcd.Fill_Round_Rectangle(x, y, x + w, y + h, 8);
  mylcd.Set_Draw_color(WHITE);
  mylcd.Draw_Round_Rectangle(x, y, x + w, y + h, 8);
  mylcd.Set_Text_Size(2);
  mylcd.Set_Text_Back_colour(GREEN);
  mylcd.Set_Text_colour(WHITE);
  int textX = x + (w - strlen(label) * 12) / 2;
  int textY = y + (h - 16) / 2;
  mylcd.Print_String(label, textX, textY);
  delay(500);

  // Restore original button
  drawButton(x, y, w, h, buttonColor[index], label);
}

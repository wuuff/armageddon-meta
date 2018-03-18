#define NUM_HIGHSCORES 5
#define NAME_SIZE 11
#define ENTRY_SIZE 16

uint32_t highscores[NUM_HIGHSCORES];
char names[NUM_HIGHSCORES][NAME_SIZE+1];

void loadHighscores(){
  for( uint8_t entry = 0; entry < NUM_HIGHSCORES; entry++ ){
    gb.save.get(entry, names[entry], NAME_SIZE);
    highscores[entry] = gb.save.get(NUM_HIGHSCORES+entry);
  }
}

uint8_t isHighscore(uint32_t score){
  if( score > highscores[NUM_HIGHSCORES-1] ){
    return 1;
  }
  return 0;
}

void saveHighscore(uint32_t score, char* who){
  uint8_t found = 0;
  uint32_t tmp_score = 0;
  char tmp_name[10];
  for( uint8_t entry = 0; entry < NUM_HIGHSCORES; entry++ ){
    if( score > highscores[entry] ){
      found = 1;
    }
    if( found ){
      tmp_score = highscores[entry];
      strcpy(tmp_name,names[entry]);

      highscores[entry] = score;
      strcpy(names[entry], who);

      score = tmp_score;
      strcpy(who, tmp_name);
    }
  }
  for( uint8_t entry = 0; entry < NUM_HIGHSCORES; entry++ ){
    gb.save.set(entry, names[entry], NAME_SIZE);
    gb.save.set(NUM_HIGHSCORES+entry, highscores[entry]);
  }
}

void drawHighscores(){
  gb.display.cursorX = 84/2 - 5*4;
  gb.display.cursorY = 5;
  gb.display.print(F("HIGHSCORES"));

  for( uint8_t entry = 0; entry < NUM_HIGHSCORES; entry++ ){
    gb.display.cursorX = 5;
    gb.display.cursorY = 12 + 5*entry;
    gb.display.print(names[entry]);
    gb.display.print(F(" "));
    gb.display.cursorX = 84 - 5*6;
    if( highscores[entry] < 100000 ){
      gb.display.print(0);
    }
    if( highscores[entry] < 10000 ){
      gb.display.print(0);
    }
    if( highscores[entry] < 1000 ){
      gb.display.print(0);
    }
    if( highscores[entry] < 100 ){
      gb.display.print(0);
    }
    if( highscores[entry] < 10 ){
      gb.display.print(0);
    }
    gb.display.print(highscores[entry]);
  }
}


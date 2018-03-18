const Gamebuino_Meta::Sound_FX player_launch[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,-4,56,10},
};

const Gamebuino_Meta::Sound_FX enemy_launch[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,4,56,10},
};

const Gamebuino_Meta::Sound_FX missile_detonate[] = {
  {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,255,0,-28,128,10},
};

const Gamebuino_Meta::Sound_FX sound_pip[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,0,56,2},
};

const Gamebuino_Meta::Sound_FX city_detonate[] = {
  {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,255,0,28,64,14},
};

const Gamebuino_Meta::Sound_FX sound_lose[] = {
  {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,5,50,30},
};

void playSound(uint8_t i){
  switch( i){
    case 0:
      gb.sound.fx(player_launch);
      break;
    case 1:
      gb.sound.fx(enemy_launch);
      break;
    case 2:
      gb.sound.fx(missile_detonate);
      break;
    case 3:
      gb.sound.fx(sound_pip);
      break;
    case 4:
      gb.sound.fx(city_detonate);
      break;
    case 5:
      gb.sound.fx(sound_lose);
      break;
  }
}


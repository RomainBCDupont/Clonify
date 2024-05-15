#include "headers/Artist.h"
#include "headers/Player.h"
#include "headers/Song.h"
#include <mpg123.h>

int main() {

  /*
   * TODO :
   *
   * Rendre la lecture Threadée
   *
   * Créer un moyen de faire pause :
   *  - utiliser des sémaphores (ou mutex ?)
   *
   * Commencer à voir pour un GUI
   *  - Python ou QT
   *
   * Terminer la modélisation
   *
   *
   */
  Song song = Song(12, "test", Artist("ouioui"));
  song.setFilepath("Songs/test.mp3");
  const char *fp = song.getFilepath();

  Player player = Player(fp);
  player.init();

  while (player.play() == 0) {
    printf("Je lis...\n");
  }
  return 0;
}

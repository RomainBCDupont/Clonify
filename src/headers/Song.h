#ifndef SONG_H
#define SONG_H

class Song {

private:
  int duration_s;

public:
  Song(const int a) : duration_s(a){};

  int getDuration();
};

#endif

#ifndef PLAY_H
#define PLAY_H

#include <ao/ao.h>
#include <mpg123.h>

class Player {

private:
  const char *filepath;

  mpg123_handle *mh;
  char *buffer;
  uint_32 buffer_size;
  size_t bytes_read;

  int driver;
  ao_device *dev;

  ao_sample_format format;
  int channels, encoding;
  long rate;

public:
  Player(const char *str) : filepath(str){};

  int init();
  int play();
  int pause();

  ~Player();
};

#endif

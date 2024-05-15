#ifndef ARTIST_H
#define ARTIST_H

class Artist {

private:
  const char *name;
  int number_listening;

public:
  Artist(const char *str) : name(str){};

  const char *getName();
  int getPopularity();
};

#endif

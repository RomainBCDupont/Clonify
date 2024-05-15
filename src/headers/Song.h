#ifndef SONG_H
#define SONG_H

#include "Artist.h"
#include "Genre.h"

#include <vector>

class Song {

private:
  int duration_s;
  const char *title;
  Artist author;
  std::vector<Genre> genres;
  const char *filepath;

public:
  Song(const int n, const char *str_t, const Artist art)
      : duration_s(n), title(str_t), author(art){};

  int getDuration();
  const char *getTitle();
  const Artist *getAuthor();

  void setFilepath(const char *str);
  const char *getFilepath();

  void addGenre(Genre);
};

#endif

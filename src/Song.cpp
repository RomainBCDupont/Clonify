#include "headers/Song.h"
#include "headers/Genre.h"

int Song::getDuration() { return this->duration_s; }
const char *Song::getTitle() { return this->title; }
const Artist *Song::getAuthor() { return &this->author; }

const char *Song::getFilepath() { return this->filepath; }
void Song::setFilepath(const char *str) { this->filepath = str; }

void Song::addGenre(Genre genre) { this->genres.push_back(genre); }

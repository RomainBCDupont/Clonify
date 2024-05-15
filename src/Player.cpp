#include "headers/Player.h"

int Player::init() {
  /* initializations */
  ao_initialize();
  driver = ao_default_driver_id();

  if (mpg123_init() != MPG123_OK)
    return -1;

  mh = mpg123_new(NULL, NULL);
  if (mh == NULL)
    return -1;

  /* Return the max size of decoded data with the current settings */
  buffer_size = mpg123_outblock(mh);

  buffer = (char *)malloc(buffer_size * sizeof(unsigned char));

  if (buffer == NULL)
    return -1;

  /* open the file and get the decoding format */
  if (mpg123_open(mh, filepath) != MPG123_OK)
    return -1;
  if (mpg123_getformat(mh, &rate, &channels, &encoding) != MPG123_OK)
    return -1;

  /* set the output format and open the output device */
  format.bits = mpg123_encsize(encoding) * 8;
  format.rate = rate;
  format.channels = channels;
  format.byte_format = AO_FMT_NATIVE;
  format.matrix = 0;

  dev = ao_open_live(driver, &format, NULL);

  return 0;
}

int Player::play() {
  /* decode and play */
  if (mpg123_read(mh, buffer, buffer_size, &bytes_read) == MPG123_OK) {
    printf("Buffer size : %d\n", buffer_size);
    ao_play(dev, buffer, buffer_size);
    return 0;
  } else {
    return -1;
  }
}

Player::~Player() {
  /* clean up */
  free(buffer);

  mpg123_close(mh);
  mpg123_delete(mh);
  mpg123_exit();

  ao_close(dev);
  ao_shutdown();
}

    char *tmp = ...;

    // the erase-remove idiom for a cstring
    *std::remove(tmp, tmp+strlen(tmp), '\n') = '\0'; // removes _all_ new lines.

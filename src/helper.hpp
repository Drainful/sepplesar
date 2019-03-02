/*
 * Provides various helper functions
 */

#ifndef HELPER
#define HELPER

namespace environment {
    const char* opencv_share_path;
}

namespace helper {
    char* get_cascade_path(const char* cascade_name);
}

#endif

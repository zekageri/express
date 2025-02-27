#pragma once
#include <string.h>

class MimeType {
   public:
    static const char* getType(const char* path);
    static const char* getExtension(const char* type, int skip = 0);

   private:
    struct entry {
        const char* fileExtension;
        const char* mimeType;
    };
    static MimeType::entry types[347];
    static int strcmpi(const char* s1, const char* s2);
};

inline MimeType mimeType;
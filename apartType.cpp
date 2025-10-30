/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "apartType.h"

const char* decorationStyleInText(int style)
{
    switch (style)
    {
        case 0:
            return "Minimalist";
            break;
        case 1:
            return "Modern";
            break;
        case 2:
            return "Classic";
            break;
        default:
            return "Not defined";
            break;
    }
}

/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#include "apartCostType.h"

const char* apartCostTypeInText(int style)
{
    switch (style)
    {
        case Daily:
            return "Daily";
            break;
        case Monthly:
            return "Monthly";
            break;
        default:
            return "Base";
            break;
    }
}
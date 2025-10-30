/* Muhammad Somaan - 2528404
I read and accept the submission rules and the extra rules specified in each
question. This is my own work that is done by myself only */

#pragma once
#ifndef APARTCOSTTYPE_H_INCLUDED
#define APARTCOSTTYPE_H_INCLUDED

enum apartCostType
{
    Base,
    Daily,
    Monthly,
    ApartCostTypeLast,
    ApartCostTypeFirst = Daily
};

const char* apartCostTypeInText(int style);

#endif // APARTCOSTTYPE_H_INCLUDED

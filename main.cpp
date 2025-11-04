#include <iostream>
#include "App.h"
#include "rlutil.h"

using namespace std;

int main()
{
    rlutil::setColor(rlutil::WHITE);
    App app;
    app.run();
    return 0;
}

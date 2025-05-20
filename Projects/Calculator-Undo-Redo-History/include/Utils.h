// ColorUtils.h
#ifndef UTILS_H
#define UTILS_H

// Namespace to organize ANSI color codes
namespace Color
{
    const char *RESET = "\033[0m";     // Reset to default color
    const char *RED = "\033[31m";      // Red text (errors)
    const char *GREEN = "\033[32m";    // Green text (success)
    const char *YELLOW = "\033[33m";   // Yellow text (warnings/info)
    const char *BLUE = "\033[34m";     // Blue text
    const char *MAGENTA = "\033[35m";  // Magenta text
    const char *CYAN = "\033[36m";     // Cyan text
    const char *BOLD = "\033[1m";      // Bold text
    const char *UNDERLINE = "\033[4m"; // Underlined text
}

#endif // COLOR_UTILS_H

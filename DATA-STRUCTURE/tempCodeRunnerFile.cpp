#include <stdio.h>

void printLine(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("-");
    }
    printf("\n");
}

void printRow(const char *date, const char *day, const char *slot, const char *subject, const char *initial, const char *room)
{
    printf("| %-12s | %-12s | %-16s | %-10s | %-10s | %-30s |\n", date, day, slot, subject, initial, room);
}

int main()
{
    int width = 110; // Increased width for better alignment
    printLine(width);
    printRow("DATE", "DAY", "SLOT & TIME", "SUBJECT", "INITIAL", "ROOM NO");
    printLine(width);
    printRow("18/12/2024", "BUD", "9:00-11:00 (A)", "DS", "MJZ", "216(7), 217(24), 218(21)");
    printLine(width);

    printRow("19/12/2024", "BRIHOSH", "X", "X", "X", "X");
    printLine(width);

    printRow("20/12/2024", "FRI", "X", "X", "X", "X");
    printLine(width);

    printRow("21/12/2024", "SONI", "9:00-11:00 (A)", "MATH", "SSL", "216(7), 217(24), 218(21)");
    printLine(width);

    printRow("22/12/2024", "ROBI", "X", "X", "X", "X");
    printLine(width);

    printRow("23/12/2024", "SHOM", "9:00-11:00 (A)", "EC", "TARA", "216(7), 217(24), 218(21)");
    printLine(width);

    printRow("24/12/2024", "MONGOL", "X", "X", "X", "X");
    printLine(width);

    printRow("25/12/2024", "BUD", "X", "X", "X", "X");
    printLine(width);

    printRow("26/12/2024", "BRIHOSH", "9:00-11:00 (A)", "PHY", "SMH", "216(7), 217(24), 218(20)");
    printLine(width);

    printRow("27/12/2024", "FRI", "X", "X", "X", "X");
    printLine(width);

    printRow("28/12/2024", "SONI", "X", "X", "X", "X");
    printLine(width);

    printRow("29/12/2024", "ROBI", "9:00-11:00 (A)", "ENG", "AJS", "216(7), 217(24), 218(21)");
    printLine(width);

    return 0;
}

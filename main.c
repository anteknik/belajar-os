void cls();

void printString(char *);
void printChar(char);
void scroll();

char *TM_START;
int CELL;

int cmain()
{
	TM_START = (char *)0xb8000;
	CELL = 0;

	cls();
	char Welcome[] = "Welcome To OSANT : Copyright 2022\n";
	char Welcome2[] = "Command Line Version 1.0.0.0\n\n";
	char OSM[] = "OS0 > ";

	printString(Welcome);
	printString(Welcome2);
}

void cls()
{
	int i = 0;
	CELL = 0;
	while (i < (2 * 80 * 25))
	{
		*(TM_START + i) = ' '; // Clear screen
		i += 2;
	}
}

void printString(char *cA)
{
	int i = 0;
	while (*(cA + i) != '\0')
	{
		printChar(*(cA + i));
		i++;
	}
}

void printChar(char c)
{
	if (CELL == 2 * 80 * 25)
		scroll();
	if (c == '\n')
	{
		CELL = ((CELL + 160) - (CELL % 160));
		return;
	}
	*(TM_START + CELL) = c;
	CELL += 2;
}

void scroll()
{
	int i = 160, y = 0;
	while (i < 2 * 80 * 25)
	{
		*(TM_START + y) = *(TM_START + i);
		i += 2;
		y += 2;
	}
	CELL = 2 * 80 * 24;
	i = 0;
	while (i < 160)
	{
		*(TM_START + CELL + i) = ' ';
		i += 2;
	}
}

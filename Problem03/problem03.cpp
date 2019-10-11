#include <iostream>
#include <cstring>
#include <stdlib.h>

void solution01(char* buff)
{
	char buff2[101];
	int idx = 0;

	for(int i = 0; i < strlen(buff); i++)
	{
		if(buff[i] != 'a')
			if(buff[i] != 'A')
				if(buff[i] != 'e')
					if(buff[i] != 'E')
						if(buff[i] != 'i')
							if(buff[i] != 'I')
								if(buff[i] != 'o')
									if(buff[i] != 'O')
										if(buff[i] != 'u')
											if(buff[i] != 'U')
											{
												buff2[idx] = buff[i];
												idx += 1;
											}

	}
	buff2[idx] = '\0';
	std::cout << buff2 << std::endl;
}

void solution02(char* buff)
{
	char buff2[101];
	int idx = 0;

	for(int i = 0; i < strlen(buff); i++)
	{
		switch(buff[i])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			break;
		default:
			buff2[idx] = buff[i];
			idx += 1;
		}
	}
	buff2[idx] = '\0';
	std::cout << buff2 << std::endl;
}

void solution03(char* buff)
{
	char buff2[101];
	buff2[0] = '\0';
	int idx = 0;

	char* token = strtok(buff, "aeiouAEIOU");
	
	while(token != NULL)
	{
		strcat(buff2, token);
		token = strtok(NULL, "aeiouAEIOU");
	}
	std::cout << buff2 << std::endl;
}

int main(int argc, char** argv)
{ 
	char buff[1000];
    std::cout << "Enter a string " << std::endl;
    std::cout << ">>";
    std::cin >> buff;

    solution01(buff);
    solution02(buff);
    solution03(buff);

    return 0;
}
#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <string>
 
int main(int argc, char** argv)
{
		int target_num;
		std::cin >> target_num;
		int count = 0;

		for(int i = 10; i <= target_num; i++)
		{
			int sum = 0;
			std::string buf = std::to_string(i);
			
			for (int j = 0; j < buf.size();j++) 
			{
    			if(i%2 != 0) sum += buf[j] - '0';
			}
			
			if(sum==7) 	count++;
			
		}
		std::cout << count << std::endl;
	
	return 0;
}

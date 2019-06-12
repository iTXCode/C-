//#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include<io.h>
//#include <string.h>
//int main()
//{
//	char buf[1024];
//	size_t s = _read(0, buf, sizeof(buf));
//	if (s > 0){
//		buf[s] = 0;
//		_write(1, buf, strlen(buf));
//		_write(2, buf, strlen(buf));
//	}
//	_close(1);
//	_close(2);
//	_close(0);
//	return 0;
//}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd = open("myfile", O_RDONLY);
	if (fd < 0){
		perror("open");
		return 1;
	}
	printf("fd: %d\n", fd);
	close(fd);
	system("pause");
	return 0;
}
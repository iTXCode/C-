//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//int  main()
//{
//	char ch[1000], re[1000], key[1000], r;
//	int key1[1000], n = 0, k, m;
//	int i = 0;
//	printf("ÊäÈëÃÜÎÄ:\n");
//	gets(ch);
//	printf("ÊäÈëÃÜÔ¿:\n");
//	gets(key);
//	while (key[i] != '\0')
//	{
//		key1[i] = (int)key[i] - 97;
//		i++;
//	}
//	int c = strlen(ch);
//
//	int j;
//	if (c%i > 0)j = c / i + 1;
//	else j = c / i;
//
//	for (k = 0; k < j; k++)
//	{
//		for (m = 0; m < i; m++)
//		{
//			if (ch[n] != '\0'){
//				re[n] = (((int)ch[n] - 97 + key1[m]) % 26 + 97) <= 122 ? (char)(((int)ch[n] - 97 + key1[m]) % 26 + 97) : (char)(((int)ch[n] - 97 + key1[m]) % 26 + 97 - 26);
//				printf("%c", re[n]);
//				n++;
//			}
//
//
//		}
//	}
//	n = 0;
//	printf("\n");
//	for (k = 0; k < j; k++)
//	{
//		for (m = 0; m < i; m++)
//		{
//			if (re[n] != '\0'){
//				r = (((int)re[n] - 97 - key1[m]) % 26 + 97) >= 97 ? (char)(((int)re[n] - 97 - key1[m]) % 26 + 97) : (char)(((int)re[n] - 97 - key1[m]) % 26 + 97 + 26);
//				printf("%c", r);
//				n++;
//			}
//		}
//	}
//	printf("\n");
//	return 0;
//}
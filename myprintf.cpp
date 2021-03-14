#include "stdio.h"

//字符串常量的长度函数
int strlen(const char c[]) {
	int i = 0;
	while (c[i] != 0) i++;
	return i;
}

void myprintf(const char* string,...) {
	int i, j;
	int len = strlen(string);
	void *p = &string+1;//读出第二个虚参的地址
	printf("string的地址：%d\np的值：%d\n", &string,p);
	for (i = 0;i<len; i++) {
		if (*(string + i) == '%') {
			if (*(string + i + 1) == 'd') {
				printf("%d", *((int*)p));
				//putchar(*((int*)p) +48);
				//p += sizeof(int);
			}
			i++;
		}
		else {
			putchar(*(string + i));
		}
	}

}

int main() {
	//TODO:实现整型的输出
	myprintf("a%dappppp",67);
	printf("a%dappppp", 67);
	return 1;
}
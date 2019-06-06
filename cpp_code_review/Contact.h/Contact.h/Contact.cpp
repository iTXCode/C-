#include"Contact.h"


void IntInfor(Infor *infor){
	assert(infor);
	infor->sz = 0;
	memset(infor->data, 0, sizeof(infor->data));
}
void addInfor(Infor *infor){
	assert(infor);
	if (infor->sz == PEOPLE_MAX){
		cout << "通讯录已满，请改变通讯录容量" << endl;
	}
	else{
		cout <<"请输入用户姓名" << endl;
		cin >> infor->data[infor->sz].name;
		cout << "请输入用户年龄"<< endl;
		cin >> infor->data[infor->sz].age;
		cout <<"请输入用户性别" << endl;
		cin >> infor->data[infor->sz].sex;
		cout <<"请输入用户住址" << endl;
		cin >> infor->data[infor->sz].addr;
		cout <<"请输入用户电话" << endl;
		cin >> infor->data[infor->sz].tele;
		infor->sz++;
	}
}

int findInfor(Infor *infor,char* name){
	assert(infor);
	for (int i = 0; i < infor->sz; i++){
		if (strcmp(infor->data[i].name, name) == 0){
			return i;
		}
	}
	return -1;
}
void searchInfor(Infor *infor){
	assert(infor);
	cout << "请输入要查找的用户姓名" << endl;
	char name[ NAME_MAX];
	cin >> name;
	int temp = findInfor(infor, name);
	if (temp == -1){
		cout << "您要查找的用户不存在" << endl;
	}
	else{
		cout << "您要查找的用户信息如下" << endl;
		cout << infor->data[temp].name << endl;
		cout << infor->data[temp].age << endl;
		cout << infor->data[temp].sex << endl;
		cout << infor->data[temp].addr << endl;
		cout << infor->data[temp].tele << endl;
	}
}

void coutInfor(Infor *infor){
	assert(infor);
	printf("-----------------------------------------------------------------------\n");
	printf("%10s\t%5s\t%5s\t%10s\t%10s\t\n",
		"姓名", "年龄", "性别", "电话", "住址");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < infor->sz; i++){
		printf("%10s\t%5d\t%5s\t%10s\t%10s\t\n",
			infor->data[i].name,
			infor->data[i].age,
			infor->data[i].sex,
			infor->data[i].addr,
			infor->data[i].tele);
		printf("-----------------------------------------------------------------------\n");
	}
	cout << endl;
}

void deleteInfor(Infor *infor){
	assert(infor);
	char name[NAME_MAX];
	
	if (infor->sz == 0){
		cout << "通讯录已空，不能继续删除" << endl;
		return;
	}
		cout << "请输入要删除对象的姓名" << endl;
		cin>> name;
		int tmp = findInfor(infor, name);
		if (tmp==-1){
			cout << "您要删除的联系人不存在，请核对后重新输入" << endl;
			return;
		}
		else{
			for (int j = tmp; j < infor->sz - 1; j++){
				infor->data[j] = infor->data[j + 1];
			}
			infor->sz--;
			cout << "删除成功" << endl;
		}
		return;
}

void modefyInfor(Infor* infor){
	assert(infor);
	cout << "请输入要修改对象的姓名" << endl;
	char name[NAME_MAX];
	cin >> name;
	int tmp = findInfor(infor,name);
	if (tmp == -1){
		cout << "您输入的用户不存在，请查询后重新进行修改" << endl;
	}
	else{
		cout << "请输入需改后的用户姓名" << endl;
		cin >> infor->data[tmp].name;
		cout << "请输入需改后的用户年龄" << endl;
		cin >> infor->data[tmp].age;
		cout << "请输入需改后的用户性别" << endl;
		cin >> infor->data[tmp].sex;
		cout << "请输入需改后的用户住址" << endl;
		cin >> infor->data[tmp].addr;
		cout << "请输入需改后的用户电话" << endl;
		cin >> infor->data[tmp].tele;
	}
}

void srotInfor(Infor *infor){
	assert(infor);
	contact temp;
	for (int j = 0; j < infor->sz - 1; j++){
		int flag = 1;
		for (int i = 0; i < infor->sz - 1 - j; i++){
			if (strcmp(infor->data[i].name, infor->data[i + 1].name)>0){
				temp = infor->data[i];
				infor->data[i] = infor->data[i + 1];
				infor->data[i + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1){
			break;
		}
	}
}
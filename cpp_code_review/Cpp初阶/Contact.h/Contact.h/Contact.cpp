#include"Contact.h"


void IntInfor(Infor *infor){
	assert(infor);
	infor->sz = 0;
	memset(infor->data, 0, sizeof(infor->data));
}
void addInfor(Infor *infor){
	assert(infor);
	if (infor->sz == PEOPLE_MAX){
		cout << "ͨѶ¼��������ı�ͨѶ¼����" << endl;
	}
	else{
		cout <<"�������û�����" << endl;
		cin >> infor->data[infor->sz].name;
		cout << "�������û�����"<< endl;
		cin >> infor->data[infor->sz].age;
		cout <<"�������û��Ա�" << endl;
		cin >> infor->data[infor->sz].sex;
		cout <<"�������û�סַ" << endl;
		cin >> infor->data[infor->sz].addr;
		cout <<"�������û��绰" << endl;
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
	cout << "������Ҫ���ҵ��û�����" << endl;
	char name[ NAME_MAX];
	cin >> name;
	int temp = findInfor(infor, name);
	if (temp == -1){
		cout << "��Ҫ���ҵ��û�������" << endl;
	}
	else{
		cout << "��Ҫ���ҵ��û���Ϣ����" << endl;
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
		"����", "����", "�Ա�", "�绰", "סַ");
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
		cout << "ͨѶ¼�ѿգ����ܼ���ɾ��" << endl;
		return;
	}
		cout << "������Ҫɾ�����������" << endl;
		cin>> name;
		int tmp = findInfor(infor, name);
		if (tmp==-1){
			cout << "��Ҫɾ������ϵ�˲����ڣ���˶Ժ���������" << endl;
			return;
		}
		else{
			for (int j = tmp; j < infor->sz - 1; j++){
				infor->data[j] = infor->data[j + 1];
			}
			infor->sz--;
			cout << "ɾ���ɹ�" << endl;
		}
		return;
}

void modefyInfor(Infor* infor){
	assert(infor);
	cout << "������Ҫ�޸Ķ��������" << endl;
	char name[NAME_MAX];
	cin >> name;
	int tmp = findInfor(infor,name);
	if (tmp == -1){
		cout << "��������û������ڣ����ѯ�����½����޸�" << endl;
	}
	else{
		cout << "��������ĺ���û�����" << endl;
		cin >> infor->data[tmp].name;
		cout << "��������ĺ���û�����" << endl;
		cin >> infor->data[tmp].age;
		cout << "��������ĺ���û��Ա�" << endl;
		cin >> infor->data[tmp].sex;
		cout << "��������ĺ���û�סַ" << endl;
		cin >> infor->data[tmp].addr;
		cout << "��������ĺ���û��绰" << endl;
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
#include"Contact.h"

using namespace std;

void menu(){

	cout << "****************************" << endl;
	cout << "**0.�˳�************1.���**" << endl;
	cout << "**2.ɾ��************3.�޸�**" << endl;
	cout << "**4.��ѯ************5.��ӡ**" << endl;
	cout << "******6.���û���������******" << endl;
	cout << "****************************" << endl;
}


void testInfor(){
	Infor infor;
	int input;
	IntInfor(&infor);
	do{
		menu();
		cout << "����������ѡ��" << endl;
		cin >> input;
		switch (input){
		case EXIT:
			cout << "�˳�����" << endl;
			break;
		case ADD:
			addInfor(&infor);
			break;
		case DELETE:
			deleteInfor(&infor);
			break;
		case MODIFY:
			modefyInfor(&infor);
			break;
		case FIND:
			searchInfor(&infor);
			break;
		case SHOW:
			coutInfor(&infor);
			break;
		case SORT:
			srotInfor(&infor);
			break;
		default:
			cout << "�������������ѡ��" << endl;
			break;
		}

	} while (input);
}

int main(){
	testInfor();
	return 0;
}
#include"Contact.h"

using namespace std;

void menu(){

	cout << "****************************" << endl;
	cout << "**0.退出************1.添加**" << endl;
	cout << "**2.删除************3.修改**" << endl;
	cout << "**4.查询************5.打印**" << endl;
	cout << "******6.按用户姓名排序******" << endl;
	cout << "****************************" << endl;
}


void testInfor(){
	Infor infor;
	int input;
	IntInfor(&infor);
	do{
		menu();
		cout << "请输入您的选择" << endl;
		cin >> input;
		switch (input){
		case EXIT:
			cout << "退出程序" << endl;
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
			cout << "输入错误，请重新选择" << endl;
			break;
		}

	} while (input);
}

int main(){
	testInfor();
	return 0;
}
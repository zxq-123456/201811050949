#include <iostream>
using namespace std;
struct Monkey
{
	int num;  //���ӵı��
	struct Monkey *next; //��һֻ����
};
int main()
{
	int m, n, i, j, king;
	Monkey *head, *p1, *p2;
	cin >> m >> n;
	if (n == 1)
	{
		king = m;
	}
	else
	{
		//��������Χ�ɵ�ԲȦ
		p1 = p2 = new Monkey;
		head = p1;
		p1->num = 1;
		for (i = 1; i < m; i++)  //����m-1ֻ����
		{
			p1 = new Monkey;  //p1�������ӵ�
			p1->num = i + 1;
			p2->next = p1;
			p2 = p1;          //p2������һֻ
		}
		p2->next = head;      //���һֻ��ָ���һֻ������һ��ԲȦ

		//����Ҫ��ʼ����
		p1 = head;
		for (i = 1; i < m; i++)  //ѭ��m-1�Σ���̭m-1ֻ����
		{
			//��p1��ʼ����n-1ֻ���ҵ���nֻ��
			for (j = 1; j < n - 1; j++)  //ʵ�����ҵ���n-1ֻ����һֻ���Ǳ���̭��
				p1 = p1->next;    //Χ��Ȧ�ģ������ٿ�ʼ�ӵ�һֻ���������δ����̭�Ļ�

			//�ҵ��ˣ�
			p2 = p1->next;  //p2����ɾ��
			//cout<<"��"<<i<<"����̭"<<p2->num<<endl;   //���������۲��м���
			p1->next = p2->next;  //p2�����������ܿ��ˡ�
			p1 = p2->next;  //��һ�������������
			delete p2;  //�����������еĽ�������
		}
		king = p1->num;
		delete p1;
	}
	cout << king << endl;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE

void main()
{
#ifdef WRITE_TO_FILE
	setlocale(LC_ALL, "");
	cout << "HelloWorld" << endl;
	std::ofstream fout;//������� �����  
	fout.open("File.txt", std::ios_base::app); //��������� �����(append  �������� ����� �����)
	//fout << "HelloWorld" << endl;//����� � �����
	time_t now = time(NULL);
	fout << ctime(&now) << endl;
	fout.close();//��������� ����� 
	system("notepad File.txt");
#endif // WRITE_TO_FILE
	//������� � ��������� ����� 
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//����� ����� ������ ���� 
		const int SIZE = 256; //������ �������
		char buffer[SIZE]{};//������ 

		while (!fin.eof())//NOT EndofFile
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);//������ ������ � ��������� 
			cout << buffer << endl; 
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error:File not found" << endl;
	}
	
}